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

void 	arrow_up(int *cp)
{
//	ft_putnbr_fd(hist_size(), 1);
	if (term->history->order == hist_size())
	{
		put_history(term->history->display, cp);
		if (term->history->prev)
			term->history = term->history->prev;
		return ;
	}
	if (term->history->prev)
	{
		put_history(term->history->prev->display, cp);
		term->history = term->history->prev;
	}
}

void 	arrow_down(int *cp)
{
//	int	len;

	if (term->history->order == hist_size() && !ft_strlen(term->line))
		return ;
	else if (term->history->order == hist_size() && ft_strlen(term->line) && !term->history->executed)
		put_history("", cp);
	if (term->history->next)
	{
		put_history(term->history->next->display, cp);
		term->history = term->history->next;
//		len = ft_strlen(term->line);
//		if (len > 0)
//		{
//			delete_nbytes(len);
//			ft_memset(term->line, 0, len);
//		}
//		len = 0;
//		while (*term->history->next->display)
//			term->line[len++] = *(term->history->next->display++);
//		*cp = ft_strlen(term->line);
//		write(1, term->line, len);
//		term->history = term->history->next;
	}
}

void	is_arrow_key(int *cp)
{
	char	buff[2];

	read(STDIN_FILENO, &buff, 2);
	if (!term->history)
		return ;
//	ft_putnbr_fd(term->history->order, 1);
	if (buff[0] == '[' && buff[1] == 'A')
	{
		if (ft_strlen(term->line) > 0 && ft_strncmp(term->line, term->history->display,
													ft_strlen(term->history->display)))
		{
			update_history(0);
			term->history = term->history->next;
		}
		arrow_up(cp);
	}
	if (buff[0] == '[' && buff[1] == 'B')
		arrow_down(cp);
	term->history_mode = 1;
}

int	read_input(void)
{
	ssize_t	r;
	int		cp;
	char	c;
	t_comm	*comm;


	cp = 0;
	write(1, USER, ft_strlen(USER));
	r = read(STDIN_FILENO, &c, 1);
	while (r > -1)
	{
		if (c == '\x1b')
			is_arrow_key(&cp);
		if (ft_isprint(c))
			write_char(&cp, c);
		if (c == 127 && cp != 0)
			delete_char(&cp);
		if (c == '\r')
		{
			// history
			// update_history();
			
			comm = parse_input();

//			restore_term();
//			t_history *temp = term->history;
//			while (temp)
//			{
//				write(1, "\n\x0dexecd: ", 9);
//				write(1, temp->executed, ft_strlen(temp->executed));
//				write(1, "\n\x0dexec: ", 8);
//				write(1, temp->display, ft_strlen(temp->display));
//				if (temp->prev)
//				{
//					write(1, "\n\x0dhistory: ", 11);
//					write(1, temp->prev->executed, ft_strlen(temp->prev->executed));
//				}
//				temp = temp->next;
//			}
//			enableRawMode();
			
			if (comm)
			{
				restore_term();
				launch_cmd(comm);
				free_cmd(comm);
				enableRawMode();
			}
			new_line_command(&cp);
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
