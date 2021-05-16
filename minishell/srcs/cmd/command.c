#include "../../minishell.h"

int	launch_cmd(t_comm *cmd)
{
	int open_fd;
	int status;
	int ofd[2];

	open_fd = 0;
	while(cmd->output_type == PIPE)
	{
		open_fd = 1;
		pipe(cmd->pipe);
		if (fork() == 0)
		{
			dup2(cmd->pipe[1], 1);
			close(cmd->pipe[0]);
			close(cmd->pipe[0]);
			exec_cmd(cmd);
			exit(0);
		}
		//wait(&status);
		dup2(cmd->pipe[0], 0);
		close(cmd->pipe[0]);
		close(cmd->pipe[1]);
		ofd[0] = cmd->pipe[0];
		ofd[1] = cmd->pipe[1];
		while(wait(&status) > 0);
		cmd = cmd->next;
	}
	if(cmd->output_type == STD)
	{
		exec_cmd(cmd);
		
	}
	
	
	return(0);
}