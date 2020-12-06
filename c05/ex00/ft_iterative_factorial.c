int	ft_iterative_factorial(int nb)
{
	int res;
	int num;

	if (nb < 0)
		return (0);
	res = 1;
	num = nb;
	while(nb)
	{
		res *= nb--;
	}
	return (res);
}
