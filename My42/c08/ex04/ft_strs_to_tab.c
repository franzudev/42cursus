/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:27:27 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/11 13:58:49 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char				*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_str	generate_struct(char *av)
{
	int					i;
	struct s_stock_str	*repl;

	i = 0;
	repl = (struct s_stock_str *)malloc(sizeof(struct s_stock_str ) * 1);
	while (av[i])
		i++;
	repl->str = av;
	repl->copy = ft_strdup(av);
	repl->size = i;
	return (*repl);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*res;
	int					a;

	res = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!res)
		return (0);
	a = 0;
	while (a < ac)
	{
		res[a] = generate_struct(av[a]);
		a++;
	}
	res[a].str = 0;
	return (res);
}
