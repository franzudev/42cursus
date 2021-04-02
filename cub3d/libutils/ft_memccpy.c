/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:31 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:23 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_uc	*from;
	t_uc	*to;
	t_uc	stop;
	size_t	index;

	index = 0;
	from = (t_uc*)src;
	to = (t_uc*)dst;
	stop = (t_uc)c;
	while (index < n)
	{
		to[index] = from[index];
		if (to[index] == stop)
			return (&to[index += 1]);
		index++;
	}
	return (NULL);
}
