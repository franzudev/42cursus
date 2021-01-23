/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:06:03 by franzu            #+#    #+#             */
/*   Updated: 2021/01/02 17:06:04 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		ch;
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;
	void				*res;

	ch = c;
	d = dst;
	s = src;
	i = 0;
	res = 0;
	while (i < n)
	{
		if (s[i] == c)
			return (&d[++i]);
		d[i] = s[i];
		i++;
	}
	return (res);
}
