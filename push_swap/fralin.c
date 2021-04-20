#include "push_swap.h"
/*
static	int	*generate_index_array(int *stack, int size)
{
	int	*copy;
	int	*index_arr;
	int	i;
	int	j;

	i = 0;
	copy = (int *)malloc(sizeof(int) * size);
	index_arr = (int *)malloc(sizeof(int) * size);
	if (!copy || !index_arr)
		exit(1);
	copy = ft_memmove(copy, stack, sizeof(int) * size);
	ft_quicksort(copy, 0, size - 1);
	while (i < size)
	{
		j = 0;
		while (stack[i] != copy[j] && j < size)
			j++;
		index_arr[i] = j;
		i++;
	}
	free(copy);
	return (index_arr);
}

void	calculate_moves(int *a_stack, int size)
{
	int	*b_stack;
}

void	sort_array(t_data *data)
{
	int		*indexes;
	char	*operations;

	indexes = generate_index_array(data->stack_a, data->size_a);
	calculate_moves(indexes, data->size_a);
}
*/