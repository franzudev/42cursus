#include "../../minishell.h"

int	exec_cmd(t_comm *cmd)
{
	if (!ft_strncmp(cmd->value, "echo", 5))
		return (cmd_echo(cmd));
	else if (!ft_strncmp(cmd->value, "pwd", 4))
		return (cmd_pwd());
	else if (!ft_strncmp(cmd->value, "env", 4))
		return (env_command(0));
	else if (!cmd_bin(cmd))
		return (EXIT_SUCCESS);
	else
		return (ft_error(cmd->value, -1));
}
