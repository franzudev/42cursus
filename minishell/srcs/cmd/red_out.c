#include "../../minishell.h"

static char	*ft_read_n_write(void)
{
	char	buff;
	char	temp[MAX_LEN];
	int		i;
	char	*out;

	i = 0;
	while (read(0, &buff, 1) > 0)
		temp[i++] = buff;
	temp[i] = 0;
	out = ft_strdup(temp);
	return (out);
}

int	cmd_red_out(char *file_path, int i)
{
	int		fd;
	char	*out;

	fd = 0;
	if (!(i == WRITE || i == APPEND))
		return (EXIT_FAILURE);
	if (i == WRITE)
		fd = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (i == APPEND)
		fd = open(file_path, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
		return (EXIT_FAILURE);
	out = ft_read_n_write();
	if (!out)
		return (EXIT_FAILURE);
	if (write(fd, out, ft_strlen(out)) < 0)
		return (EXIT_FAILURE);
	free(out);
	close(fd);
	return (EXIT_SUCCESS);
}
