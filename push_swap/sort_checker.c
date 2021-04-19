#include "push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

/* int is_srp(int *stack, int index, int size)
{
	if (is_swappable(stack, index)
		&& is_rotatable(stack, index, size)
		&& is_pushable(stack, index, size))
		return (1);
	return (0);
}

int is_sp(int *stack, int index, int size)
{
	if (is_swappable(stack, index)
		&& is_pushable(stack, index, size))
		return (1);
	return (0);
}

int is_rp(int *stack, int index, int size)
{
	if (is_rotatable(stack, index, size)
		&& is_pushable(stack, index, size))
		return (1);
	return (0);
} */

int	is_swappable(int *stack, int index, int size)
{
	if (ft_abs(stack[index] - stack[index + 1]) < ft_abs(stack[index] - stack[size - 1]))
		return (0);
	return (1);
}

int	is_rotatable(int *stack, int index, int size)
{
	if (ft_abs(stack[index] - stack[index + 1]) < ft_abs(stack[index] - stack[size - 1]))
		return (0);
	return (1);
}

int is_rev_rotatable(int *stack, int index, int size)
{
	if (stack[index] <= size / 2)
		return (1);
	return (0);
}

int	is_pushable(int *stack, int index, int size)
{
	if (stack[index] < size / 2)
		return (1);
	return (0);
}

