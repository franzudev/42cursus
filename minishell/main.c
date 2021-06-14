#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	int r;

	r = 0;
	g_term = (t_term *)malloc(sizeof(t_term));
	if (argc != 1)
		exit(1);
	if (!argv[0])
		exit(1);
	init_env(env);
	enableRawMode();
//	ft_strlcpy(g_term->line, "echo '' '' ''", ft_strlen
//			("echo '' '' ''") + 1);
//	update_history(1);
//	update_history(1);
//	update_history(1);
//	t_comm *comm = parse_input();
//	comm = NULL;
//	exit(0);
//	update_history(1);
	while (r > -1)
		r = read_input();
	restore_term();
	free_all();
	return (0);
}


//	ft_strlcpy(g_term->line, "export PS1=e3r4p12$>", 20);
//	t_comm *comm = parse_input();
//	cmd_export(comm);
//	char **reenv = rebuild_env(g_term->env, g_term->reenv);
//	execve("\x2f\x62\x69\x6e\x2f\x62\x61\x73\x68", NULL, reenv);
