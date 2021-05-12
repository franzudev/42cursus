#include "../../minishell.h"

static void	close_pipe(int pipe[2])
{
	close(pipe[0]);
	close(pipe[1]);
}

static void	dup_n_close(int pipe[2], int pipe_dup)
{
	dup2(pipe[pipe_dup], pipe_dup);
	close_pipe(pipe);
}

void	apply_last_pipe(t_comm *cmd)
{
	// se il precedente esiste e precedente pipi
	if(cmd->prev && cmd->prev->output_type == PIPE)
		close_pipe(cmd->prev->pipe);
	// se successivo esiste e successivo e red_in
	if(cmd->next && cmd->next->output_type == STD)
		close_pipe(cmd->next->pipe);

	// red_out
	if((cmd->output_type == WRITE || cmd->output_type == APPEND))
		close_pipe(cmd->pipe);
}

void	apply_pipe(t_comm *cmd)
{
	// se il precedente e  precedente e pipe 
	if (cmd->prev && cmd->prev->output_type == PIPE)
		dup_n_close(cmd->prev->pipe, 0);
	// se esiste il prossimo ed e red_in
	if (cmd->next && cmd->next->output_type == STD)
		dup_n_close(cmd->next->pipe, 0);
	// red_out
	if (cmd->output_type == WRITE || cmd->output_type == APPEND)
		dup_n_close(cmd->pipe, 0);
	// red_in
	if (cmd->output_type == STD)
		dup_n_close(cmd->pipe, 1);
	//esiste il prossimo ed pipi o red_out
	if (cmd->next && (cmd->next->output_type == PIPE || cmd->next->output_type == WRITE || cmd->next->output_type == APPEND))
		dup_n_close(cmd->next->pipe, 1);
}
