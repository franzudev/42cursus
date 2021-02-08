/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:34:22 by franzu            #+#    #+#             */
/*   Updated: 2021/01/02 23:34:23 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * len);
	if (!res || !*s)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	return (res);
}
