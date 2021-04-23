#include "minishell.h"

void	dont_terminate(int par)
{
	par = 5;
}

int main(int ac, char **av, char **env) {
//	t_mini	mini;
	int		r, i = 0;
	char 	comm[1024];

	if (ac != 1)
		exit(av[0][1]);
	if (!env)
		exit(1);

	// to manage ctrl+c
	signal(SIGINT, dont_terminate);
	// to manage ctrl+d
	signal(SIGQUIT, dont_terminate);


	write(1, "e3r5p12.$>", 10);
	while (1)
	{
		if (comm[i] == '\n')
		{
			comm[i] = '\0';
			execve("/bin/ls", av, env);
		}
	}

	return 0;
}
