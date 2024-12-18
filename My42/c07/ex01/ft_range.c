/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:33:56 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/10 09:33:58 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *ints;
	int size;
	int i;

	if (min >= max)
		return (0);
	i = 0;
	size = max - min;
	ints = (int *)malloc(sizeof(int) * size);
	while (i < size)
		ints[i++] = min++;
	ints[i] = '\0';
	return (ints);
}
