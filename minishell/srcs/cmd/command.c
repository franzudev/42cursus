#include "../../minishell.h"


// static void	ft_pipe(t_comm *cmd)
// {
// 	// pid_t pidC;
// 	// int status;

// 	pipe(cmd->pipe);
// 	cmd->pidC = fork();
// 	if (cmd->pidC == 0)
// 	{
// 		dup2(cmd->pipe[1], 1);
// 		close(cmd->pipe[0]);
// 		close(cmd->pipe[1]);
// 		exec_cmd(cmd);
// 		exit(0);
// 	}
// 	if(cmd->next && cmd->next->output_type == PIPE)
// 	{
// 		// pidC = fork();
// 		// if (pidC == 0)
// 		// {
// 			dup2(cmd->pipe[0], 0);
// 			close(cmd->pipe[0]);
// 			close(cmd->pipe[1]);
// 			//exit(0);
// 		// }
// 		// waitpid(pidC, NULL, 0);
// 		// waitpid(cmd->pidC, NULL, 0);
// 	}
// }

static void	ft_pipe(t_comm *cmd)
{
	pipe(cmd->pipe);
	cmd->pidC = fork();
	if (cmd->pidC == 0)
	{
		if(cmd->prev)
			dup2(cmd->prev->pipe[0], 0);
		dup2(cmd->pipe[1], 1);
		close(cmd->pipe[0]);
		exec_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	waitpid(cmd->pidC, NULL, 0);
	close(cmd->pipe[1]);
}

static void	ft_std(t_comm *cmd)
{
	cmd->pidC = fork();
	if (cmd->pidC == 0)
	{
		if(cmd->prev && cmd->prev->output_type == PIPE)
		{
			dup2(cmd->prev->pipe[0], 0);
			close(cmd->prev->pipe[0]);
			close(cmd->prev->pipe[1]);
		}
		exec_cmd(cmd);
		exit(0);
	}
	waitpid(cmd->pidC, NULL, 0);
}

static void	ft_out(t_comm *cmd)
{
	pid_t pidC;

	pipe(cmd->pipe);
	cmd->pidC = fork();
	if (cmd->pidC == 0)
	{
		dup2(cmd->pipe[0], 0);
		close(cmd->pipe[0]);
		close(cmd->pipe[1]);
		cmd_red_out(cmd->output, cmd->output_type);
		exit(0);
	}
	pidC = fork();
	if (pidC == 0)
	{
		dup2(cmd->pipe[1], 1);
		close(cmd->pipe[0]);
		close(cmd->pipe[1]);
		waitpid(pidC, NULL, 0);
//		wait(NULL);
		exec_cmd(cmd);
		exit(0);
	}
	close(cmd->pipe[0]);
	close(cmd->pipe[1]);
	waitpid(pidC, NULL, 0);
}


static void ft_in(t_comm *cmd)
{
	pid_t pidC;

	pipe(cmd->pipe);
	cmd->pidC = fork();
	if (cmd->pidC == 0)
	{
		dup2(cmd->pipe[1], 1);
		close(cmd->pipe[0]);
		close(cmd->pipe[1]);
		cmd_red_in(cmd->input);
		exit(0);
	}
	pidC = fork();
	if (pidC == 0)
	{
		dup2(cmd->pipe[0], 0);
		close(cmd->pipe[0]);
		close(cmd->pipe[1]);
		exec_cmd(cmd);
		exit(0);
	}
	close(cmd->pipe[0]);
	close(cmd->pipe[1]);
	waitpid(pidC, NULL , 0);
	//waitpid(cmd->pidC, NULL, 0);
}

int	launch_cmd(t_comm *cmd)
{
	t_comm *save;

	save = cmd;
	ft_add_prev(cmd);
	while(cmd)
	{
		if(!ft_strncmp(cmd->value, "exit", 5))
			return (cmd_exit());
		else if (!ft_strncmp(cmd->value, "cd", 3))
			cmd_cd(cmd);
		else if (!ft_strncmp(cmd->value, "export", 7))
			cmd_export(cmd);
		else if (!ft_strncmp(cmd->value, "unset", 6))
			cmd_unset(cmd);
		else if (cmd->input)
			ft_in(cmd);
		else if (cmd->output_type == STD)
			ft_std(cmd);
		else if (cmd->output_type == WRITE || cmd->output_type == APPEND)
			ft_out(cmd);
		else if (cmd->output_type == PIPE)
			ft_pipe(cmd);
		cmd = cmd->next;
	 }
	while (save)
	{
		if (save->output_type != STD)
		{
			close(save->pipe[0]);
			close(save->pipe[1]);
		}
		waitpid(save->pidC, NULL, 0);
		save = save->next;
	}
	return(EXIT_SUCCESS);
}
