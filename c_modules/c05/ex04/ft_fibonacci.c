#include <stdio.h>

int ft_fibonacci(int index)
{
	if (index < 0)
		return -1;
	
	return index + ft_fibonacci(index + 1);

}

int	main(void)
{
	ft_fibonacci(5);
}