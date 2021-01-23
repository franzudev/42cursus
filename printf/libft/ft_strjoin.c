/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:45:06 by franzu            #+#    #+#             */
/*   Updated: 2021/01/02 23:45:08 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;
	int		i;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * size);
	if (!res)
		return (0);
	while (*s1)
		res[i++] = *(s1++);
	while (*s2)
		res[i++] = *(s2++);
	return (res);
}
