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
	int 	j;

	cmds = ft_split(term->line, ';');
	command = (t_comm *)malloc(sizeof(t_comm));
	commands = command;
	i = 0;
	j = 0;
	while (cmds[i])
	{
		cmd = ft_split(cmds[i], '|');
		command->output = (ft_index_of(cmds[i], "|") != -1) + STD;
		while (cmd[j])
		{
			command->args = ft_split(cmd[j], ' ');
			command->value = command->args[0];
			command->next = (t_comm *) malloc(sizeof(t_comm));
			command = command->next;
			j++;
		}
		free(cmd);
		i++;
	}
	free(cmds);
	return commands;
}

int read_input(void)
{
	int r;
	int cp;
	char c;
	t_comm *comm;

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
			comm = parse_command();
			if (ft_strncmp(term->line, "pwd", 3) == 0)
				cmd_pwd();
			if (ft_strncmp(term->line, "exit", 4) == 0)
				cmd_exit();
			if (ft_strncmp(term->line, "env", 3) == 0)
				env_command();
//			new_line_command();
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
	enableRawMode();
	ft_strlcpy(term->line, "ls -la toro | echo 'zio can'", 29);
	parse_command();
	/*if (fork() == 0)
	{
		restore_term();
		char *av[] = {"ls", "la", NULL};
		execve("/bin/ls", av, env);
	} else {
		wait(NULL);
		enableRawMode();
	}*/
	while (r > -1)
		r = read_input();
	free_all();
	return (0);
}


// for strings
//int string_in_command()
//{
//	char	*cm;
//	int 	sidx;
//	int 	didx;
//	sidx = ft_index_of(cmd[j], "'");
//	didx = ft_index_of(cmd[j], "\x22");
//	cm = cmd[j];
//	if (sidx != -1)
//	{
//		if (sidx < didx || didx == -1)
//		{
//			cm = ft_substr(cmd[j], 0, sidx);
//			cm = ft_strjoin(cm, ft_substr(cmd[j], sidx, ft_strlen
//																(cmd[j]) -
//														didx));
//		}
//	}
//	if (didx != -1)
//	{
//		if (didx < sidx || sidx == -1)
//		{
//			cm = ft_substr(cmd[j], 0, didx);
//			cm = ft_strjoin(cm, ft_substr(cmd[j], didx, ft_index_of
//																(cmd[j],
//																 "\x22") -
//														didx + 1));
//		}
//	}
//}