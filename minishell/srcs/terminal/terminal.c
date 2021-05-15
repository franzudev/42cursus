#include "../../minishell.h"

void	enableRawMode(void)
{
	struct termios	raw;

	if (tcgetattr(STDIN_FILENO, &term->old_conf) == -1)
		exit(1);
	raw = term->old_conf;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
		exit(1);
}

void	restore_term(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term->old_conf);
}

void 	arrow_up(int *cp)
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
	if (len == 1)
	{
		if (ft_strncmp(term->line, term->history->display, ft_strlen(term->line)))
			return ;
		len = ft_strlen(term->line);
		if (len > 0)
		{
			delete_nbytes(len);
			ft_memset(term->line, 0, len);
		}
		len = 0;
		while (*term->history->display)
			term->line[len++] = *(term->history->display++);
		*cp = len;
		write(1, term->line, len);
	}

	if (term->history->prev)
	{
		len = ft_strlen(term->line);
		if (len > 0)
		{
			delete_nbytes(len);
			ft_memset(term->line, 0, len);
		}
		len = 0;
		while (*term->history->prev->display)
			term->line[len++] = *(term->history->prev->display++);
		len = 4;
		*cp = len;
		write(1, term->line, len);
		term->history = term->history->prev;
	}
}

void 	arrow_down(int *cp)
{
	int	len;

	if (term->history->next)
	{
		len = ft_strlen(term->line);
		if (len > 0)
		{
			delete_nbytes(len);
			ft_memset(term->line, 0, len);
		}
		len = 0;
		while (*term->history->next->display)
			term->line[len++] = *(term->history->next->display++);
		*cp = ft_strlen(term->line);
		write(1, term->line, len);
		term->history = term->history->next;
	}
}

void	is_arrow_key(int *cp)
{
	char	buff[2];

	read(STDIN_FILENO, &buff, 2);
	if (!term->history)
		return ;
	if (buff[0] == '[' && buff[1] == 'A')
	{
		if (ft_strlen(term->line) > 0 && ft_strncmp(term->line, term->history->display,
													ft_strlen(term->line)) != 0)
			update_history();
		arrow_up(cp);
	}
	if (buff[0] == '[' && buff[1] == 'B')
		arrow_down(cp);
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
			update_history();
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
				launch_cmd(comm);
				free_cmd(comm);
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
