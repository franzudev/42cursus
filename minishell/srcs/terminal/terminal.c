#include "../../minishell.h"

void	enableRawMode(void)
{
	struct termios	raw;

	if (tcgetattr(STDIN_FILENO, &term->old_conf) == -1)
		exit(2);
	raw = term->old_conf;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &raw) == -1)
		exit(3);
}

void	restore_term(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term->old_conf);
}

void	put_history(char *display, int *cp)
{
	int len;

	len = ft_strlen(term->line);
	if (len > 0)
	{
		delete_nbytes(len);
		ft_memset(term->line, 0, len);
	}
	len = 0;
	while (*display)
		term->line[len++] = *(display++);
	*cp = len;
	write(1, term->line, len);
}

int	hist_size(void)
{
	int			len;
	t_history	*hist;

	hist = term->history_clone;
	len = 0;
	while  (hist)
	{
		len++;
		hist = hist->next;
	}
	return (len);
}

int		is_same_history()
{
	int len;

	len = ft_strlen(term->line);
	if (ft_strncmp(term->line, term->history->display, len) == 0)
		return (1);
	return (0);
}

void 	arrow_up(int *cp)
{
	t_history *history;

	history = term->history;
	if (!history->executed)
	{
		ft_memset(history->display, 0, ft_strlen(history->display));
		history->display = ft_strdup(term->line);
	}
	if (history->order == hist_size() && !term->history_mode)
		put_history(history->display, cp);
	else if (history->prev)
	{
		put_history(history->prev->display, cp);
		term->history = history->prev;
	}
	else
		put_history(history->display, cp);
	term->history_mode = 1;
}

void 	arrow_down(int *cp)
{
//	int	len;

	if (term->history->order == hist_size() && !ft_strlen(term->line))
		return ;
	else if (!term->history->executed)
		return;
	else if (term->history->order == hist_size())
	{
		put_history("", cp);
		term->history_mode = 0;
		if (term->history->next)
			term->history = term->history->next;
	}
	else if (term->history->next)
	{
		put_history(term->history->next->display, cp);
		term->history = term->history->next;
		term->history_mode = 1;
	}
//	else
//	{
//		put_history("", cp);
//		term->history_mode = 0;
//		if (term->history->next)
//			term->history = term->history->next;
//	}
}

void	is_arrow_key(int *cp)
{
	char	buff[2];

	read(STDIN_FILENO, &buff, 2);
//	arrow_up(cp);
//	arrow_up(cp);
//	buff[0] = '[';
//	buff[1] = 'B';
	if (!term->history)
		return ;
	if (buff[0] == '[' && buff[1] == 'A')
	{
		if (ft_strlen(term->line) > 0
		&& hist_size() == term->history->order && !is_same_history())
		{
			update_history(0);
//			term->history = term->history->next;
		}
		arrow_up(cp);
	}
	if (buff[0] == '[' && buff[1] == 'B')
		arrow_down(cp);
}

void	remove_unexecuted()
{
	t_history *prev;

	while (term->history_clone)
	{
		if (!term->history_clone->executed)
		{
			free(term->history_clone->display);
			if (term->history_clone->prev)
			{
				prev = term->history_clone->prev;
				prev->next = term->history_clone->next;
			}
			else
				prev = term->history_clone->next;
			free(term->history_clone);
			term->history_clone = prev;
		}
		if (term->history_clone->next)
			term->history_clone = term->history_clone->next;
		else
			break;
	}
	while (term->history_clone)
	{
		if (term->history_clone->prev)
			term->history_clone = term->history_clone->prev;
		else
			break;
	}
}

int	read_input(void)
{
	ssize_t	r;
	int		cp;
	char	c;
	t_comm	*comm;
//	int i = 0;

	cp = 0;
	write(1, USER, ft_strlen(USER));
	r = read(STDIN_FILENO, &c, 1);
	while (r > -1)
	{
		if (c == '\x1b'/* || i == 3*/)
			is_arrow_key(&cp);
		if (ft_isprint(c))
			write_char(&cp, c);
		if (c == 127 && cp != 0)
			delete_char(&cp);
		if (c == '\r')
		{
			// history
			if (term->history && !term->history->executed)
				term->history->executed = ft_strdup(term->line);
			else
			{
				if (term->history)
				{
					ft_memset(term->history->display, 0,
							  ft_strlen(term->history->display));
					term->history->display = ft_strdup(term->history->executed);
				}
				remove_unexecuted();
				update_history(1);
			}
			comm = parse_input();
			if (comm)
			{
				restore_term();
				launch_cmd(comm);
				free_cmd(comm);
				enableRawMode();
			}
			term->history_mode = 0;
			new_line_command(&cp);
//			i++;
		}
		if (c == (('d') & 0x1f) && cp == 0)
			return (quit_gracefully());
		if (c == (('c') & 0x1f))
			new_line_command(&cp);
		c = 0;
		r = read(STDIN_FILENO, &c, 1);
	}
	return (r);
}
