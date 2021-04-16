/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:26:13 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/16 16:44:29 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**count_and_alloc(const char *str, char charset)
{
	int	w;
	int	i;

	if (!str)
		return (0);
	w = 1;
	i = 0;
	while (str[i])
	{
		if ((str[i] == charset && str[i + 1] != charset && str[i + 1] != '\0')
			|| (str[i] != charset && i == 0))
			w++;
		i++;
	}
	return ((char **)malloc(sizeof(char *) * w));
}

static void	alloc_string_space(char **res, char const *str, char charset)
{
	int	w;
	int	i;
	int	len;

	i = 0;
	w = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != charset)
			len++;
		if ((str[i + 1] == charset || str[i + 1] == '\0') && len > 0)
		{
			res[w++] = (char *)malloc(sizeof(char) * (len + 1));
			len = 0;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		w;
	int		i;
	int		a;

	a = 0;
	i = 0;
	res = count_and_alloc(s, c);
	if (!res || !s)
		return (0);
	alloc_string_space(res, s, c);
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
			res[w][a++] = s[i];
		if ((s[i + 1] == c || s[i + 1] == '\0') && a > 0)
		{
			res[w++][a] = '\0';
			a = 0;
		}
		i++;
	}
	res[w] = 0;
	return (res);
}
