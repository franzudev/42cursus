#include "minishell.h"

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

static void	delete_nbytes(int cp)
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

static int	quit_gracefully(void)
{
	write(STDOUT_FILENO, "exit\n\x0d", 6);
	return (-1);
}

static void	new_line_command(void)
{
	write(1, "\n\x0d", 2);
	write(1, USER, ft_strlen(USER));
}

int	ft_index_of(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_rindex_of(char *str, char *set)
{
	int	i;

	i = (int)ft_strlen(str) - 1;
	while (i > -1)
	{
		if (ft_strchr(set, str[i]))
			return (i);
		i--;
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

int	is_append(char *str, int *wri)
{
	if (*wri > 0 && str[*wri - 1] == '>')
	{
		*wri -= 1;
		return (*wri + 1);
	}
	return (-1);
}

void	command_output(t_comm *command, char *str)
{
	int		wri;
	int		app;
	int		inp;
	char	*temp;

	wri = ft_rindex_of(str, ">");
	app = is_append(str, &wri);
	if (wri != -1 || app != -1)
	{
		++wri;
		++app;
		if (wri > app)
		{
			inp = ft_rindex_of(&str[wri], "<");
			command->output_type = WRITE;
			if (inp != -1)
				temp = ft_substr(&str[wri], 0, ft_index_of(&str[wri], "<"));
			else
				temp = ft_substr(&str[wri], 0, ft_strlen(&str[wri]));
		}
		if (app > wri)
		{
			inp = ft_rindex_of(&str[app], "<");
			command->output_type = APPEND;
			if (inp != -1)
				temp = ft_substr(&str[app], 0, ft_index_of(&str[app], "<"));
			else
				temp = ft_substr(&str[app], 0, ft_strlen(&str[app]));
		}
		command->output = ft_strtrim(temp, " ");
		free(temp);
	}
	else
	{
		command->output = NULL;
		command->output_type = STD;
	}
}

void	command_input(t_comm *command, char *str)
{
	int		inp;
	int		wri;
	int		app;
	char	*temp;

	inp = ft_rindex_of(str, "<");
	if (inp != -1)
	{
		++inp;
		wri = ft_index_of(&str[inp], ">");
		app = is_append(&str[inp], &wri);
		if (wri == -1 && app == -1)
			temp = ft_substr(&str[inp], 0, ft_strlen(&str[inp]));
		else
			temp = ft_substr(&str[inp], 0, ft_index_of(&str[inp], ">"));
		command->input = ft_strtrim(temp, " ");
		free(temp);
	}
	else
		command->input = NULL;
}

int	ft_size(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	*slice_operators(char *str)
{
	int	inp;
	int	wri;

	inp = ft_index_of(str, "<");
	wri = ft_index_of(str, ">");
	if (inp == -1 && wri == -1)
		return (str);
	if (inp < wri)
		return (ft_substr(str, 0, inp));
	return (ft_substr(str, 0, wri));
}

void	parse_operators(t_comm *command, char *cmd, int cmds_size, int index)
{
	char	*tmp;

	command_output(command, cmd);
	if (!command->output && cmds_size > 1 && index != cmds_size - 1)
		command->output_type = PIPE;
	command_input(command, cmd);
	if (command->output_type > STD && command->input)
	{
		tmp = slice_operators(cmd);
		command->args = ft_split(tmp, ' ');
		free(tmp);
	}
	else
		command->args = ft_split(cmd, ' ');
}

void	parse_command(t_comm *command, char **cmd)
{
	int	j;
	int size;

	j = 0;
	size = ft_size((void **)cmd);
	while (cmd[j])
	{
		parse_operators(command, cmd[j], size, j);
		command->value = command->args[0];
		command->next = (t_comm *)malloc(sizeof(t_comm));
		command = command->next;
		free(cmd[j]);
		j++;
	}
}

t_comm	*parse_input(void)
{
	int		i;
	char	**cmds;
	char	**cmd;
	t_comm	*commands;
	t_comm	*command;

	cmds = ft_split(term->line, ';');
	commands = (t_comm *)malloc(sizeof(t_comm));
	command = commands;
	i = 0;
	while (cmds[i])
	{
		cmd = ft_split(cmds[i], '|');
		parse_command(command, cmd);
		free(cmd);
		i++;
	}
	i = 0;
	while (cmds[i])
		free(cmds[i++]);
	free(cmds);
	return (commands);
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

void	restore_term(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term->old_conf);
}

#include <sys/types.h>
#include <sys/stat.h>

int	main(int argc, char **argv, char **env)
{
	atexit(restore_term); // to remove
	int r;
//	struct stat st;

	r = 0;
	term = (t_term *)malloc(sizeof(t_term));
	if (argc != 1)
		exit(1);
	if (!argv[0])
		exit(1);
	init_env(env);
	enableRawMode();
//	ft_strlcpy(term->line, "echo 'dio can' | echo 'porco dio' < prova > inputprova", 55);
//	t_comm *comm = parse_input();
//	restore_term();
//	int i;
//	while (comm->next)
//	{
//		i = 0;
//		printf("\n\nCOMMAND: %s", comm->value);
//		while (comm->args[i])
//			printf("\nARGS: %s", comm->args[i++]);
//		printf("\nINPUT: %s", comm->input);
//		printf("\nOUTPUT: %s", comm->output);
//		printf("\nTYPE: %d", comm->output_type);
//		comm = comm->next;
//	}
//	enableRawMode();
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


/*if (fork() == 0)
{
	restore_term();
	char *av[] = {"ls", "la", NULL};
	execve("/bin/ls", av, env);
} else {
	wait(NULL);
	enableRawMode();
}*/
