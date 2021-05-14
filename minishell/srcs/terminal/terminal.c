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
//		if (c == '\x1b') // ctrl keys
		if (ft_isprint(c))
			write_char(&cp, c);
		if (c == 127 && cp != 0)
			delete_char(&cp);
		if (c == '\r')
		{
			// history
//			update_history();
			comm = parse_input();
//			if (!check_error(comm))
<<<<<<< HEAD
			//  restore_term();
			// if(!ft_strncmp(comm->value, "exit", 4))
			// 	return (cmd_exit());
			launch_cmd(comm);

			//  enableRawMode();
=======
			exec_cmd(comm);
//			free_cmd(comm);
//			free(comm);
>>>>>>> 6bdf7bf3e6c8234a635261f1f96473e2c6926742

//			 int i;
//			 while (term->history)
//			 {
//			 	ft_putstr_fd("\nexecd: ", 1);
//			 	ft_putendl_fd(term->history->executed, 1);
//			 	ft_putstr_fd("\nexec: ", 1);
//			 	ft_putendl_fd(term->history->display, 1);
//			 	if (term->history->prev)
//			 	{
//			 		ft_putstr_fd("\nhistory: ", 1);
//					ft_putendl_fd(term->history->prev->executed, 1);
//				}
//			 	term->history = term->history->next;
//			 }


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
