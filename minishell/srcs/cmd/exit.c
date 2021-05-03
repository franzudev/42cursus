#include "../../minishell.h"

int	cmd_exit(void)
{
	free_all();
	return (EXIT_SUCCESS);
}