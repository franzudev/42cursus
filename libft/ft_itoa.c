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

static int	digit_count(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		d;

	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	d = digit_count(n);
	res = (char *)malloc(sizeof(char) * d);
	if (!res)
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[d--] = '\0';
	while (n)
	{
		res[d--] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
