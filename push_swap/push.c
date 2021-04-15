#include "push_swap.h"

void	ft_push(int *stack_dest, int *stack_source, int *size_dest, int *size_source)
{
	int i;

	if (*size_source == 0)
		return ;
	i = *size_dest;
	while (i > 0)
	{
		stack_dest[i] = stack_dest[i - 1];
		i--;
	}
	stack_dest[0] = stack_source[0];
	i = 0;
	while (++i < *size_source)
		stack_source[i - 1] = stack_source[i];
	*size_source -= 1;
	*size_dest += 1;
}
