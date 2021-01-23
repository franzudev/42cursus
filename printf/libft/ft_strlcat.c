/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:53:41 by franzu            #+#    #+#             */
/*   Updated: 2021/01/02 18:53:42 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t size;
	size_t res;

	i = ft_strlen(dst);
	size = dstsize - i - 1;
	res = i + ft_strlen(src);
	while (*src && size)
	{
		dst[i++] = *(src++);
		size--;
	}
	dst[i] = '\0';
	return (res);
}
