#include "push_swap.h"

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
	free_stack(data);
}

void	ft_exit(char *str, t_data *data)
{
	free_stack(data->stack_a);
	free_stack(data->stack_b);
	write(2, str, ft_strlen(str));
	exit(1);
}
