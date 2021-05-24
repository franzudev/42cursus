#include "minishell.h"
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
//	ft_strlcpy(term->line, "echo '' '' ''", ft_strlen
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
	free_all();
	return (0);
}


//	ft_strlcpy(term->line, "export PS1=e3r4p12$>", 20);
//	t_comm *comm = parse_input();
//	cmd_export(comm);
//	char **reenv = rebuild_env(term->env, term->reenv);
//	execve("\x2f\x62\x69\x6e\x2f\x62\x61\x73\x68", NULL, reenv);
