#include "libft/libft.h"

#include <limits.h>

void free_pointer(char *str)
{
	str = NULL;
	free(str);
}

int get_next_line(char **line)
{
	char tmp[ARG_MAX];
	int ret;
	int i;

	if (!line)
		return (-1);
	i = 0;
	while ((ret = read(0, &tmp[i], 1)) > -1)
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
	}
	return (-1);
}

int check_instruction()
{

}

int main(int argc, char *argv[])
{
	if (argc == 100)
		return (int)argv;
	char *line;
	line = malloc(100);
	while (get_next_line(&line) != 0)
	{
		check_instruction(line);

	}
	return (0);
}