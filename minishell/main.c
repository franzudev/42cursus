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
//	ft_strlcpy(term->line, "echo 'dio can' | echo 'porco dio' > inputprova", 55);
//	t_comm *comm = parse_input();
//	comm = NULL;
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
