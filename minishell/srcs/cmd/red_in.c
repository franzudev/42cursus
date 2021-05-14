#include "../../minishell.h"

int	cmd_red_in(char *file_path)
{
	int	fd;
	char buff[1];

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	while (read(fd, buff, 1) > 0)
	{
		if (write(STDOUT_FILENO, buff, 1) < 0)
			return (EXIT_FAILURE);
	}
	close(fd);
	write(STDOUT_FILENO, "\n\x0d", 2);
	return (EXIT_SUCCESS);
}
