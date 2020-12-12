/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:54:46 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/03 15:57:43 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2, int size)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && i < size)
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int x;

	x = 0;
	while (to_find[x] != '\0')
	{
		x++;
	}
	if (x < 1)
	{
		return (str);
	}
	while (*str)
	{
		if (*str == to_find[0])
		{
			if (ft_strcmp(str, to_find, x))
			{
				return (str);
			}
		}
		str++;
	}
	return (0);
}
