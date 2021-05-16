#include "../../minishell.h"

int	cmd_echo(t_comm *cmd)
{
	int 	i;
	int		option;
	i = 1;
	option = 0;
	if (cmd->args[i])
	{
		if (!ft_strncmp(cmd->args[1], "-n", 3))
		{
			i = 2;
			option = 1;
			if(!cmd->args[i])
				return(EXIT_SUCCESS);
		}
		write(STDOUT_FILENO, cmd->args[i], ft_strlen(cmd->args[i]));
		while (cmd->args[++i])
		{
				write(STDOUT_FILENO, " ", 1);
				write(STDOUT_FILENO, cmd->args[i], ft_strlen(cmd->args[i]));
		}
	}
	if (option == 0)
		write(STDOUT_FILENO, "\n\x0d", 2);
	return (EXIT_SUCCESS);
}
