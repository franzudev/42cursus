/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:16:15 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/01/12 11:16:16 by ffrancoi         ###   ########.fr       */
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
