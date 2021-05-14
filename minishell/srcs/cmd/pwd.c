#include "../../minishell.h"

int	cmd_pwd(void)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, MAX_LEN);
	if (buf == NULL)
      return (EXIT_FAILURE);
    else
      ft_putstr_fd(buf, STDOUT_FILENO);
    free(buf);
	write(STDOUT_FILENO, "\n\x0d", 2);
	return (EXIT_SUCCESS);
}

