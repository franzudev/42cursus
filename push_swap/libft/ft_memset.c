/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:16:15 by lincerpi          #+#    #+#             */
/*   Updated: 2021/04/21 15:49:13 by lincerpi         ###   ########.fr       */
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
