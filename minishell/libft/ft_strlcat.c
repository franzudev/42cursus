/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:16:40 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/01/12 11:16:41 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;
	size_t	res;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (dstsize < ft_strlen(dst))
		return (dstsize + s_len);
	i = ft_strlen(dst);
	size = dstsize - i;
	if (size > 0)
		size -= 1;
	res = i + s_len;
	while (*src && size > 0)
	{
		dst[i++] = *(src++);
		size--;
	}
	dst[i] = '\0';
	if (i > dstsize)
		return (s_len + dstsize);
	return (res);
}
