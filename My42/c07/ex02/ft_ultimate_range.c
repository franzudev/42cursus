/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:34:11 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/10 09:34:13 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int size;
	int i;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	i = 0;
	size = max - min;
	range[0] = (int *)malloc(sizeof(int) * size);
	if (!range || !range[0])
		return (-1);
	while (i < size)
		range[0][i++] = min++;
	range[0][i] = '\0';
	return (size);
}
