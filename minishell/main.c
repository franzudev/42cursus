#include "minishell.h"

void enableRawMode() {
	if (tcgetattr(STDIN_FILENO, &term->old_conf) == -1)
		exit(1);
	struct termios raw = term->old_conf;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;

	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
		exit(1);
}

static void delete_nbytes(int cp)
{
	while (cp)
	{
		write(STDOUT_FILENO, "\b", 1);
		write(STDOUT_FILENO, "\x20", 1);
		write(STDOUT_FILENO, "\b", 1);
		cp--;
	}
}

static void	delete_char(int *cp)
{
	delete_nbytes(1);
	*cp -= 1;
	term->line[*cp] = '\0';
}

void	write_char(int *cp, char c)
{
	write(STDOUT_FILENO, &c, 1);
	term->line[*cp] = c;
	*cp += 1;
}

static int	quit_gracefully()
{
	write(STDOUT_FILENO, "exit\n\x0d", 6);
	return (-1);
}

static void new_line_command()
{
	write(1, "\n\x0d", 2);
	write(1, USER, ft_strlen(USER));
}

int	ft_index_of(char *str, char *set)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
			return (i);
		i++;
	}
	return (-1);
}

/*static	int	ft_isspace(char c)
{
	if (c == '\n' || c == '\r' || c == '\f' || c == '\t' || c == '\v'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_is_reserved_symbol(char *c)
{
	if (ft_strncmp("|", c, 1)
		|| ft_strncmp("<", c, 1)
		|| ft_strncmp(">", c, 1)
		|| ft_strncmp(">>", c, 2))
		return (1);
	return (0);
}*/

t_comm	*parse_command()
{
	char	**cmds;
	char	**cmd;
	t_comm	*commands;
	t_comm	*command;
	int 	i;

	cmds = ft_split(term->line, ';');
	command = (t_comm *)malloc(sizeof(t_comm));
	commands = command;
	i = 0;
	while (cmds[i])
	{
		if (ft_index_of(cmds[i], " "))
		cmd = ft_split(cmds[i], ' ');
		command->value = cmd[0];
		command->args = cmd;
		command->next = (t_comm *)malloc(sizeof(t_comm));
		command = command->next;
		free(cmd);
		i++;
	}
	free(cmds);

	i = 0;
	printf("%s\n", commands->value);
	while (i < 3)
		printf("%s\n", commands->args[i++]);
	return commands;
}

int read_input(void)
{
	int r;
	int cp;
	char c;

	cp = 0;
	write(1, USER, ft_strlen(USER));
	r = read(STDIN_FILENO, &c, 1);
	while (r > -1)
	{
//		if (c == '\x1b') // ctrl keys
		if (ft_isprint(c))
			write_char(&cp, c);
		if (c == 127 && !(cp == 0))
			delete_char(&cp);
		if (c == '\r') // lexer
		{
			parse_command();
			new_line_command();
			cp = 0;
		}
		if (c == (('d') & 0x1f) && cp == 0)
			return quit_gracefully();
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

void restore_term()
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term->old_conf);
}

int	main(int argc, char **argv, char **env)
{
	atexit(restore_term); // to remove
	int r;

	r = 0;
	term = (t_term *)malloc(sizeof(t_term));
	if (argc != 1)
		exit(1);
	if (!argv[0])
		exit(1);
	init_env(env);
////	env_command();
	enableRawMode();
	ft_strlcpy(term->line, "ls -la toro", 6);
	parse_command();
	/*if (fork() == 0)
	{
		restore_term();
		char *av[] = {"ls", "la", NULL};
		execve("/bin/ls", av, env);
	} else {
		wait(NULL);
		enableRawMode();
	}
	while (r > -1)
		r = read_input();*/
	free_all();
	return (0);
}
