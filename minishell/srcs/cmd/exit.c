#include "../../minishell.h"

int	cmd_exit(void)
{
	write(STDOUT_FILENO, "exit\n", 5);
	free_all();
	exit(EXIT_SUCCESS);
}
