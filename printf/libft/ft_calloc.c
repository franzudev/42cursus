/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:53:10 by franzu            #+#    #+#             */
/*   Updated: 2020/12/31 13:53:12 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*res;

	i = 0;
	res = (void *)malloc(size * count);
	while (i < count)
		((unsigned char *)res)[i++] = 0;
	return (res);
}
