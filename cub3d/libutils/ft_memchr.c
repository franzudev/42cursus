/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:31 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:23 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	t_uc	*vect;
	t_uc	stop;

	vect = (t_uc*)s;
	index = 0;
	stop = (t_uc)c;
	while (index < n)
	{
		if (vect[index] == stop)
			return (&vect[index]);
		index++;
	}
	return (NULL);
}
