/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:25:22 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/01/12 11:25:23 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(long n)
{
	int count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*res;
	long	t;
	int		d;

	t = (long)n;
	d = digit_count(t);
	res = (char *)malloc(sizeof(char) * d);
	if (!res)
		return (0);
	if (t < 0)
	{
		res[0] = '-';
		t *= -1;
	}
	res[d--] = '\0';
	if (t == 0)
		res[d] = '0';
	while (t)
	{
		res[d--] = (t % 10) + '0';
		t /= 10;
	}
	return (res);
}
