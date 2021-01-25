#include "libft.h"

int		check_base(char *base)
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

void	ft_putnbr_base(int nbr, char *base)
{
	int			size_base;
	int			nbr_final[200];
	int			i;
	long int	nb;

	i = 0;
	size_base = 0;
	nb = (long)nbr;
	if (check_base(base))
	{
		if (nb < 0)
			ft_putchar_fd('-', 1);
		if (nb < 0)
			nb = -nb;
		while (base[size_base])
			size_base++;
		while (nb)
		{
			nbr_final[i] = nb % size_base;
			nb = nb / size_base;
			i++;
		}
		while (--i >= 0)
			ft_putchar_fd(base[nbr_final[i]], 1);
	}
}