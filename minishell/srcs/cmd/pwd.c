#include "../../minishell.h"

int	cmd_pwd(void)
{
	char	*buf;

	buf = getcwd(buf, MAX_LEN);
	if (buf == NULL)
      return (errno);
    else
	{
      write(STDOUT_FILENO, buf, ft_strlen(buf));
	  write(STDOUT_FILENO, "\n", 1);
	}
	return (EXIT_SUCCESS);
}

// If successful, getcwd() returns a pointer to the buffer.

// If unsuccessful, getcwd() returns a NULL pointer and sets errno to one of the following values cit.IBM
// if (getcwd(cwd, sizeof(cwd)) == NULL)
//       perror("getcwd() error");
//     else
//       printf("current working directory is: %s\n", cwd);