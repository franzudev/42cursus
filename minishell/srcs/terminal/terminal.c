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
