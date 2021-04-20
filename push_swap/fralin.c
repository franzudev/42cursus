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

void	calculate_moves(int *a_stack, int size, char **operations)
{
	int	i;
	int	*b_stack;
	int	b_size;
	operations = malloc(1);
	i = 0;
	b_stack = (int *)malloc(sizeof(int) * size);
	b_size = size;
	int j;
	while (!is_sorted_asc(a_stack, size) && i < 20)
	{
		j = 0;
		while (j < size)
			printf("%d\n", a_stack[j++]);
		if (is_pushable(a_stack, 0, size))
		{
			ft_push(b_stack, a_stack, &b_size, &size);
			ft_putstr_fd("pa\n", 1);
			continue;
		}
		if (is_swappable(a_stack, 0, size))
		{
			ft_swap(a_stack, size);
			ft_putstr_fd("sa\n", 1);
			i++;
			continue;
		}
		if (is_rotatable(a_stack, 0, size))
		{
			if (is_rev_rotatable(a_stack, 0, size))
			{
				ft_r_rotate(a_stack, size);
				ft_putstr_fd("rra\n", 1);
				i++;
				continue ;
			}
			ft_rotate(a_stack, size);
			ft_putstr_fd("ra\n", 1);
			i++;
			continue;
		}
		ft_rotate(a_stack, size);
	}
	ft_putnbr_fd(i, 1);
}

void	sort_array(t_data *data)
{
	int		*indexes;
	char	*operations;

	indexes = generate_index_array(data->stack_a, data->size_a);
	int i = 0;
	while (i < data->size_a)
	{
		printf("%10d -- %10d\n", data->stack_a[i], indexes[i]);
		i++;
	}
	exit(1);
	calculate_moves(indexes, data->size_a, &operations);
}
*/