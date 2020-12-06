#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
	int neg;

	neg = 1;
	if (nb == 0 || power == 0)
		return 1;
	if (nb < 0 && power % 3 == 0)
		neg *= -1;
	return nb * ft_recursive_power(nb, power - 1) * neg;
}

int main(void)
{
	printf("%d", ft_recursive_power(5, 3));
	return (0);
}