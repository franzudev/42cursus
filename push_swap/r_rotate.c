#include "push_swap.h"

void	r_rotate(int **stack, int size)
{
	int	tmp;
	int	i;

	i = size - 1;
	tmp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}

