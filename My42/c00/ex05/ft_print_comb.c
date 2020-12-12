/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:52:02 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/11/28 17:02:37 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_it(int i, int j, int k)
{
	char p;

	p = i;
	write(1, &p, 1);
	p = j;
	write(1, &p, 1);
	p = k;
	write(1, &p, 1);
	if (!(i == 55 && j == 56 && k == 57))
	{
		p = ',';
		write(1, &p, 1);
		p = ' ';
		write(1, &p, 1);
	}
}

void	ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = 48;
	while (i <= 57)
	{
		j = i + 1;
		while (j <= 57)
		{
			k = j + 1;
			while (k <= 57)
			{
				print_it(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
