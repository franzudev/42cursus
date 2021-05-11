#include "../../minishell.h"

// creare funzione che libera la lista dei comandi attuali e inserirla in cmd_exit()

int	cmd_exit(void)
{
	write(STDOUT_FILENO, "\n\x0d", 2);
	write(STDOUT_FILENO, "exit\n\x0d", 6);
	free_all();
	exit(EXIT_SUCCESS);
}
