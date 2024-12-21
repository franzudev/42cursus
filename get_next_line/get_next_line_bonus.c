#include "get_next_line.h"

static void		ft_delptr(char **ptr)
{
	if (!ptr || !*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

static void		buff_rem_cpy(char **buff, unsigned long j)
{
	unsigned long	i;
	char			tmp[ARG_MAX];

	i = 0;
	if (!buff[0][j])
		ft_delptr(&*buff);
	else
	{
		while (buff[0][j])
			tmp[i++] = buff[0][j++];
		tmp[i] = '\0';
		ft_delptr(&*buff);
		*buff = ft_strdup(tmp);
	}
}

static int		buff_cpy(char **line, char **buff)
{
	unsigned long	i;
	unsigned long	j;
	char			tmp[ARG_MAX];

	i = 0;
	j = 0;
	while (line[0][i])
	{
		tmp[i] = line[0][i];
		i++;
	}
	ft_delptr(&*line);
	while (buff[0][j] && buff[0][j] != '\n')
		tmp[i++] = buff[0][j++];
	tmp[i] = '\0';
	*line = ft_strdup(tmp);
	if (buff[0][j] == '\n')
	{
		buff_rem_cpy(&*buff, j + 1);
		return (1);
	}
	ft_delptr(&*buff);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*rem[OPEN_MAX];
	char		tmp[ARG_MAX];
	int			read_size;
	int			ret;

	if (fd >= 0 && line && BUFFER_SIZE > 0 && (*line = ft_strdup("")))
	{
		ret = 0;
		while (ret == 0)
		{
			if (!rem[fd] && (read_size = read(fd, tmp, BUFFER_SIZE)) >= 0
				&& !(tmp[read_size] = '\0'))
				rem[fd] = ft_strdup(tmp);
			if (rem[fd])
				read_size = ft_strlen(rem[fd]);
			if (read_size < 0)
				break ;
			ret = buff_cpy(&*line, &rem[fd]);
			if (read_size == 0)
				return (0);
		}
		if (ret == 1)
			return (1);
	}
	ft_delptr(&*line);
	return (-1);
}
