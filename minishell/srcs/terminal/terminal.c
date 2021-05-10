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
			comm = parse_input();
			if (ft_strncmp(term->line, "pwd", 3) == 0)
				cmd_pwd();
			if (ft_strncmp(term->line, "exit", 4) == 0)
				cmd_exit();
			if (ft_strncmp(term->line, "env", 3) == 0)
				env_command();
			restore_term();
			int i;
			while (comm->next)
			{
				i = 0;
				printf("\n\nCOMMAND: %s", comm->value);
				while (comm->args[i])
					printf("\nARGS: %s", comm->args[i++]);
				printf("\nINPUT: %s", comm->input);
				printf("\nOUTPUT: %s", comm->output);
				printf("\nTYPE: %d", comm->output_type);
				comm = comm->next;
			}
			enableRawMode();
			new_line_command();
			cp = 0;
		}
		if (c == (('d') & 0x1f) && cp == 0)
			return (quit_gracefully());
		if (c == (('c') & 0x1f))
		{
			cp = 0;
			new_line_command();
		}
		c = 0;
		r = read(STDIN_FILENO, &c, 1);
	}
	return (r);
}