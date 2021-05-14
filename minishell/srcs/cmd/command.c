#include "../../minishell.h"


int	ft_out(t_comm *cmd)
{
	int fds[2];
	pid_t pidC;
	int status;

	//cmd[stdout] -> red_ount{stdin}
	 pipe(fds);
	pidC = fork();

	if (pidC == -1)
    {
        perror ("fork");
        exit (1);
    }
	else if (pidC == 0)    /* Primo Figlio */
    {
        dup2 (fds[0], STDIN_FILENO);
        close (fds[0]);
        close (fds[1]);

        if (cmd_red_out(cmd->output, cmd->output_type) == EXIT_FAILURE)
        {
            perror ("red_in");
            exit (1);
        }
		exit(0);
    }
	// else if (pidC > 0)
	// 	wait(&status);
	
	 pidC = fork ();

    if (pidC == -1)
    {
        perror ("fork");
        exit (1);
    }
	else if (pidC == 0)    /* Secondo Figlio */
    {
        dup2 (fds[1], STDOUT_FILENO);
        close (fds[0]);
        close (fds[1]);

        if (exec_cmd(cmd) == -1)
        {
            perror ("execlp");
            exit (1);
        }
		exit(0);
    }
	else if (pidC > 0)
		wait(&status);
	// else if (pidC > 0)
	// {
	// 	return(EXIT_SUCCESS);
	// }

    close (fds[0]);
    close (fds[1]);
	
		// wait(&status);
			// while (&status > 0);

	return (EXIT_SUCCESS);
}


int	ft_pi(t_comm *cmd)
{
	int fds[2];
	pid_t pidC;
	int status;

	//cmd[stdout] -> red_ount{stdin}
	pipe(fds);
	pidC = fork();

	if (pidC == 0)    /* Primo Figlio */
    {
        dup2 (fds[1], STDOUT_FILENO);
        close (fds[0]);
        close (fds[1]);

        execve("/bin/ls", cmd->args, term->reenv);
	
    }
	
			
	 wait(&status);
	 pidC = fork ();

    if (pidC == -1)
    {
        perror ("fork");
        exit (1);
    }
	else if (pidC == 0)    /* Secondo Figlio */
    {
        dup2 (fds[0], STDIN_FILENO);
        close (fds[0]);
        close (fds[1]);

        execve("/bin/wc", cmd->args, term->reenv);
		
	}
		
	// else if (pidC > 0)
	// 	wait(&status);
	

    close (fds[0]);
    close (fds[1]);
	
	 wait(&status);
	// while (&status > 0);
	return (EXIT_SUCCESS);
}

int	ft_in(t_comm *cmd)
{
	int fds[2];
	pid_t pidC;
	 int status;

	//cmd[stdout] -> red_ount{stdin}
	 pipe(fds);
	pidC = fork();

	if (pidC == -1)
    {
        perror ("fork");
        exit (1);
    }
	else if (pidC == 0)    /* Primo Figlio */
    {
        dup2 (fds[1], STDOUT_FILENO);
        close (fds[0]);
        close (fds[1]);

        if (cmd_red_in(cmd->input) == EXIT_FAILURE)
        {
            perror ("red_out");
            exit (1);
        }
    }
	else if (pidC > 0)
		wait(&status);

	 pidC = fork ();

    if (pidC == -1)
    {
        perror ("fork");
        exit (1);
    }
	else if (pidC == 0)    /* Secondo Figlio */
    {
        dup2 (fds[0], STDIN_FILENO);
        close (fds[0]);
        close (fds[1]);

        if (exec_cmd(cmd) == -1)
        {
            perror ("execlp");
            exit (1);
        }
    }
	// else if(pidC > 0)
	// {
	// 	return(EXIT_SUCCESS);
	// }
    close (fds[0]);
    close (fds[1]);
	
	 wait(&status);
	 
	// while (&status > 0);
	return (EXIT_SUCCESS);
}

int	launch_cmd(t_comm *cmd)
{
	if (!ft_strncmp(cmd->value, "cd", 3)
	|| !ft_strncmp(cmd->value, "echo", 5)
	|| !ft_strncmp(cmd->value, "pwd", 3))
		ft_putstr_fd("\n\x0d", 1);

	// aggiungere se redIn e redOut
	//ft_putstr_fd("ce sto", 1);
	while(cmd)
	{
		
		// if(cmd->input && cmd->output_type == 0)
		// {
		// 	ft_in(cmd);
			//cmd_red_in(cmd->args[1]);
		// }	//TODO: esegui red_in con path cmd->args[1] ed esegui cmd
		// else if(cmd->output_type == 2 || cmd->output_type == 3)
		// {
		// 	ft_out(cmd);
		// 	//cmd_red_out(cmd->args[1], cmd->output_type);
		// }
			//TODO: esegui red_out con path cmd->args[1] e output_type ed esegui cmd
		if(cmd->output_type == 1)
		{
			ft_pi(cmd);
			cmd = cmd->next; //no
		}
			//TODO: esegui pipe cmd && cmd-next! 
		else
		{

			exec_cmd(cmd);
			// enableRawMode();
		}
			//TODO:exec_cmd
		cmd = cmd->next;
	}
	
	return (EXIT_SUCCESS);
}

// int main (void)
// {
//     pid_t pid;
//     int   fd_pipe[2];
//     int   r, status;

//     r = pipe (fd_pipe);

//     if (r == -1)
//     {
//         perror ("pipe");
//         exit (1);
//     }

//     pid = fork ();

//     if (pid == -1)
//     {
//         perror ("fork");
//         exit (1);
//     }
//     else if (pid == 0)    /* Primo Figlio */
//     {
//         dup2 (fd_pipe[1], STDOUT_FILENO);
//         close (fd_pipe[0]);
//         close (fd_pipe[1]);

//         if (execlp ("who", "who", NULL) == -1)
//         {
//             perror ("execlp");
//             exit (1);
//         }
//     }

//     pid = fork ();

//     if (pid == -1)
//     {
//         perror ("fork");
//         exit (1);
//     }
//     else if (pid == 0)    /* Secondo Figlio */
//     {
//         dup2 (fd_pipe[0], STDIN_FILENO);
//         close (fd_pipe[0]);
//         close (fd_pipe[1]);

//         if (execlp ("wc", "wc", "-l", NULL) == -1)
//         {
//             perror ("execlp");
//             exit (1);
//         }
//     }

//     close (fd_pipe[0]);
//     close (fd_pipe[1]);

//     while (wait (&status) > 0);

//     return 0;
// }