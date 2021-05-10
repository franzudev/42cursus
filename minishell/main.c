#include "minishell.h"

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
