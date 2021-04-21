/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <ffrancoi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:50:12 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/21 15:50:13 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
