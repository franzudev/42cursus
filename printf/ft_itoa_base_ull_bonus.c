/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:18:29 by franzu            #+#    #+#             */
/*   Updated: 2021/02/08 09:18:30 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(unsigned long long n)
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

static int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

static char	*zero(void)
{
	char *res;

	if (!(res = (char *)malloc(sizeof(char) * 2)))
		return ("0");
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

static void	build_nbr(char *res, unsigned long long *nbr, int *s, char *base)
{
	unsigned long long	nbr_final[200];
	int					count;
	int					i;

	i = 0;
	while (*nbr)
	{
		nbr_final[i++] = *nbr % *s;
		*nbr /= *s;
	}
	count = 0;
	while (--i >= 0)
		res[count++] = base[nbr_final[i]];
	res[count] = '\0';
}

char		*ft_itoa_base_ull(unsigned long long nbr, char *base)
{
	int		size_base;
	int		count;
	char	*res;

	size_base = 0;
	res = NULL;
	if (nbr == 0)
		return (zero());
	if (check_base(base))
	{
		count = digit_count(nbr);
		res = (char *)malloc(sizeof(char) * (count + 1));
		res[count] = '\0';
		while (base[size_base])
			size_base++;
		build_nbr(res, &nbr, &size_base, base);
	}
	return (res);
}
