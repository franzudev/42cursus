#include "push_swap.h"

void ft_swap(int *stack, int size)
{
	int temp;

	if (size < 2)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}