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
			// store_cmd();
			comm = parse_input();
//			if (!check_error(comm))
			
				
					// if (fork() == 0)
					// {
				
					// 	exec_cmd(comm);
					// } else {
					// 	wait(NULL);
						
					// }
			exec_cmd(comm);
				
			

			// restore_term();
			// int i;
			// while (comm->value)
			// {
			// 	i = 0;
			// 	ft_putstr_fd("\nCOMMAND: ", 1);
			// 	ft_putendl_fd(comm->value, 1);
			// 	while (comm->args[i])
			// 	{
			// 		ft_putstr_fd("\nARGS: ", 1);
			// 		ft_putstr_fd(comm->args[i++], 1);
			// 	}
			// 	ft_putstr_fd("\nINPUT: ", 1);
			// 	ft_putendl_fd(comm->input, 1);
			// 	ft_putstr_fd("\nOUTPUT: ", 1);
			// 	ft_putendl_fd(comm->output, 1);
			// 	ft_putstr_fd("\nOUTPUT TYPE: ", 1);
			// 	ft_putnbr_fd(comm->output_type, 1);
			// 	ft_putendl_fd("", 1);
			// 	comm = comm->next;
			// }
			// enableRawMode();
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
