#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int res;
	int neg;

	neg = 1;
	res = 1;
	if (nb == 0 || power < 0)
		return res;
	if (nb < 0 && power % 2 == 0)
		neg *= -1;
	while(power--)
		res *= nb;
	return (res * neg);
}

int	main(void)
{
	printf("%d", ft_iterative_power(-5, 0));
	return (0);
}