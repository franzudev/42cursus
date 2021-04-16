#include "push_swap.h"

int	is_sorted_asc(int *stack, int size)
{
	int i;

	i = 0;
	while (stack[i] && i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted_desc(int *stack, int size)
{
	int i;

	i = 0;
	while (stack[i] && i < size - 1)
	{
		if (stack[i] < stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_stack(int *stack)
{
	if (stack)
		free(stack);
}

void	print_result(t_data *data)
{
	int	i;

	if (data->size_b)
	{
		write(1, "KO\n", 3);
		return ;
	}
	i = -1;
	while (++i < data->size_a - 1)
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	write(1, "OK\n", 3);
	free_stack(data->stack_a);
	free_stack(data->stack_b);
}

void	ft_exit(char *str, t_data *data)
{
	free_stack(data->stack_a);
	free_stack(data->stack_b);
	write(2, str, ft_strlen(str));
	exit(1);
}
