#include "libft.h"

static int	digit_count(long n)
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

static int		check_base(char *base)
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

#include <stdio.h>

char	*ft_itoa_base(long nbr, char *base)
{
	int			size_base;
	long		nbr_final[200];
	int			i;
	int			count;
	char		*res;
	long		nb;

	nb = nbr;
	i = 0;
	size_base = 0;
	res = NULL;
	if (check_base(base))
	{
		count = digit_count(nb);
		res = (char *) malloc(sizeof(char) * (count + 1));
		res[count] = '\0';
		while (base[size_base])
			size_base++;
		while (nb)
		{
			nbr_final[i++] = nb % size_base;
			nb = nb / size_base;
		}
		count = 0;
		while (--i >= 0)
			res[count++] = base[nbr_final[i]];
		res[count] = '\0';
	}
	return (res);
}