#include "../../minishell.h"


// se ; esegui i cmd creando fork()

// se INPUT...pipe con stdin lo stdout di "INPUT"

// se OUTPUT ...pipe con stdin di ÖUTPUT lo stdout

// se pipe fai pipe


int		exec_cmd(t_comm *cmd)
{
	if ((!ft_strncmp(cmd->value, "cd", 3)
	|| !ft_strncmp(cmd->value, "echo", 5)
	|| !ft_strncmp(cmd->value, "pwd", 3)) && cmd->output_type < 2)
		ft_putstr_fd("\n\x0d", 1);	
	if (!ft_strncmp(cmd->value, "cd", 3))
		return (cmd_cd(cmd));
	else if(!ft_strncmp(cmd->value, "echo", 5))
	 	return (cmd_echo(cmd));
	else if(!ft_strncmp(cmd->value, "pwd", 3))
		return (cmd_pwd());
	else if(!ft_strncmp(cmd->value, "exit", 4))
		return (cmd_exit());
	else if(!ft_strncmp(cmd->value, "export", 6))
		return (cmd_export(cmd));
	else if(!ft_strncmp(cmd->value, "env", 3))
		return (env_command());
	else if(!ft_strncmp(cmd->value, "unset", 5))
		return (cmd_unset(cmd));
	else if(!cmd_bin(cmd))
		return (EXIT_SUCCESS);
	else
		return (-1);
}