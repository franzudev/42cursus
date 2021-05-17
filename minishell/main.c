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
//	ft_strlcpy(term->line, "echo quarto", 11);
//	update_history(1);
	while (r > -1)
		r = read_input();
//	ft_strlcpy(term->line, "export PS1=e3r4p12$>", 20);
//	t_comm *comm = parse_input();
//	cmd_export(comm);
//	char **reenv = rebuild_env(term->env, term->reenv);
//	execve("\x2f\x62\x69\x6e\x2f\x62\x61\x73\x68", NULL, reenv);
	free_all();
	return (0);
}

// child process
/*int main(int argc, char **argv, char **env)
{
	pid_t proc, wpid;
	int	status = 0;
	char *prov[] = {"/bin/cat", "main.c", NULL};

	if (!argc || !argv || !env)
		return 1;

	proc = fork();
	ft_putnbr_fd(proc, 1);
	ft_putendl_fd("", 1);
	if (proc == 0)
	{
		ft_putendl_fd("child", 1);
		execve("/bin/cat", prov, env);
	}
	else {
		while ((wpid = wait(&status)) > 0);
		ft_putendl_fd("parent", 1);
		while (1);
	}
}*/

// pipe
/*#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	int pipefd[2];
	pid_t cpid;
	char buf;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	cpid = fork();
	if (cpid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (cpid == 0) {    *//* Child reads from pipe *//*
		ft_putstr_fd("\n##### CHILD #####\n", 1);
		close(pipefd[1]);          *//* Close unused write end *//*

		while (read(pipefd[0], &buf, 1) > 0)
			write(STDOUT_FILENO, &buf, 1);

		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
		_exit(EXIT_SUCCESS);

	} else {            *//* Parent writes argv[1] to pipe *//*
		ft_putstr_fd("\n##### PARENT #####\n", 1);
		close(pipefd[0]);          *//* Close unused read end *//*
		write(pipefd[1], argv[1], strlen(argv[1]));
		close(pipefd[1]);          *//* Reader will see EOF *//*
		wait(NULL);                *//* Wait for child *//*
		exit(EXIT_SUCCESS);
	}
}*/
