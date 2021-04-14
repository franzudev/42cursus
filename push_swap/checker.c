#include "push_swap.h"

#include <limits.h>

void	free_pointer(char *str)
{
	str = NULL;
	free(str);
}

int	get_next_line(char **line)
{
	char	tmp[ARG_MAX];
	int		ret;
	int		i;

	if (!line)
		return (-1);
	i = 0;
	ret = read(0, &tmp[i], 1);
	while (ret > -1)
	{
		if (tmp[i] == '\n' || ret == 0)
		{
			tmp[i] = '\0';
			*line = ft_strdup(tmp);
			if (!*line)
				return (-1);
			if (ret)
				return (1);
			return (0);
		}
		i++;
		ret = read(0, &tmp[i], 1);
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 1)
		exit(0);
	check_args(&data, argc, argv);
	while (get_next_line(&data.operation) > 0)
	{
		check_instruction(data.operation);
		exec_instruction(&data);
	}
	return (0);
}
