#include "../../minishell.h"

int	cmd_pwd(void)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, MAX_LEN);
	if (buf == NULL)
      return (EXIT_FAILURE);
    else
	{
	  write(STDOUT_FILENO, "\n\x0d", 2);
      write(STDOUT_FILENO, buf, ft_strlen(buf));
	}
    free(buf);
	return (EXIT_SUCCESS);
}

