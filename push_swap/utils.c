#include "push_swap.h"

static void	free_stack(t_data *data)
{
	if (data->stack_a)
		free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
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

void	ft_exit(char *str, t_data *data) //togli str e metti ERR
{
	free_stack(data);
	write(2, str, ft_strlen(str)); // write ERROR
	exit(1);
}
