#include "../../minishell.h"
#include <limits.h>	//aggiungere in minishell.h

static char *ft_read_n_write(void)
{
	char buff[ARG_MAX];
	char *out;

	out = ft_strdup("");
	while (read(0, buff, 1) > 0)
	{
		out = ft_strjoin(out, buff);
		if (!out)
			return (NULL);
	}
	return (out);
}


int	cmd_red_out(char *file_path) // dove mi mandi il comando? quale struttura? serve filename e se red_singola o doppia
{
	int fd;
	char *out;
	
	if () // red_singola 
		fd = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
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

int main()
{
	cmd_red_out("ciao");
	return 0;
}