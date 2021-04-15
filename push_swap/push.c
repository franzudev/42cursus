#include "push_swap.h"

void	push_a(t_data *data)
{
	int	i;

	if (data->size_a == 0)
		return ;
	i = data->size_b;
	while (i > 0)
	{
		data->stack_b[i + 1] = data->stack_b[i];
		i--;
	}
	data->stack_b[0] = data->stack_a[0];
	i = 0;
	while (++i < data->size_a)
		data->stack_a[i - 1] = data->stack_a[i];
	data->size_a--;
	data->size_b++;
}

void	push_b(t_data *data)
{
	int	i;

	if (data->size_b == 0)
		return ;
	i = data->size_a;
	while (i > 0)
	{
		data->stack_a[i + 1] = data->stack_a[i];
		i--;
	}
	data->stack_a[0] = data->stack_b[0];
	i = 0;
	while (++i < data->size_b)
		data->stack_b[i - 1] = data->stack_b[i];
	data->size_b--;
	data->size_a++;
}
