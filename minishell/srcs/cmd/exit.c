#include "../../minishell.h"

int	cmd_exit(void)
{
	write(STDOUT_FILENO, "\n\x0d", 2);
	write(STDOUT_FILENO, "exit\n\x0d", 6);
	free_all();
	exit(EXIT_SUCCESS);
}
