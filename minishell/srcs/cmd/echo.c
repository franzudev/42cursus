#include "../../minishell.h"

int	cmd_echo(t_comm *cmd)
{
	//aggiungere $ARG..porco cazzo!! se non trova ARG linea vuota! e $? dove lo mettiamo????
	write(STDOUT_FILENO, cmd->value, ft_strlen(cmd->value));
	if (ft_strcmp(cmd->flags, "-n"))
		write(STDOUT_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}

