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

void	parse_command()
{
	char	*line;
	char	**cmds;
	char	**pipes;
	char 	**redis;
	char	*cmd;
	int 	i;
	int		j;
	int 	idx;
	int		phase;
	t_token tokens;

	line = term->line;
	cmds = NULL;
	pipes = NULL;
	redis = NULL;

	phase = COMM;

	if (ft_strchr(line, ';'))
		cmds = ft_split(line, ';');
	i = 0;
	while (cmds[i])
	{
		j = 0;
		cmd = ft_strtrim(cmds[i], " \n\r\f\t\v");
		idx = ft_index_of(cmd, " \n\r\f\t\v");
		tokens.value = ft_substr(cmd, 0, idx);
		tokens.type = COMM;
		cmd += idx;
		while (*cmd)
		{
			cmd = ft_strtrim(cmd, " \n\r\f\t\v");
			if (phase == COMM && *cmd == '-')
				phase = FLAGS;
			if (phase == FLAGS)
			{
				/*while (*cmd == '-')
				{
					ft_index_of(cmd, "")
				}*/
			}
		}
	}
	return ;
}

int read_input(void)
{
	ssize_t r;
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
		if (c == 127 && cp != 0)
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

#include <sys/types.h>
#include <sys/stat.h>

int	main(int argc, char **argv, char **env)
{
	atexit(restore_term); // to remove
	int r;
	struct stat st;

	r = 0;
	term = (t_term *)malloc(sizeof(t_term));
	if (argc != 1)
		exit(1);
	if (!argv[0])
		exit(1);
	init_env(env);
	enableRawMode();

//	if (fork() == 0)
//	{
//		restore_term();
//		char *av[] = {"ls", "-la", "srcs", NULL};
//		execve("/bin/ls", av, env);
//	} else {
//		wait(NULL);
//		enableRawMode();
//	}
	while (r > -1)
		r = read_input();
	free_all();
	return (0);
}
