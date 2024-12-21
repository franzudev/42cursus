/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:28:10 by franzu            #+#    #+#             */
/*   Updated: 2021/01/02 17:28:11 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;
	unsigned char	ch;
	size_t			i;

	d = b;
	ch = c;
	i = 0;
	while (i < len)
		d[i++] = ch;
	return (b);
}
