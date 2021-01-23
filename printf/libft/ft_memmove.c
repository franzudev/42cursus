/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:18:09 by franzu            #+#    #+#             */
/*   Updated: 2021/01/02 17:18:11 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned char		*r;
	const unsigned char	*s;
	size_t				i;

	d = dst;
	r = dst;
	s = src;
	i = 0;
	while (i < len)
	{
		r[i] = s[i];
		i++;
	}
	return (r);
}
