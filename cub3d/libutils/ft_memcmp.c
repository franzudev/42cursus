/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:31 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:23 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_uc	*vect1;
	t_uc	*vect2;
	size_t	index;

	vect1 = (t_uc*)s1;
	vect2 = (t_uc*)s2;
	index = 0;
	while (index < n)
	{
		if (vect1[index] != vect2[index])
			return ((int)vect1[index] - (int)vect2[index]);
		index++;
	}
	return ((int)vect1[index - 1] - (int)vect2[index - 1]);
}
