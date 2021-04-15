#include "push_swap.h"

void	r_rotate_a(t_data *data)
{
	int	tmp;
	int	i;

	i = data->size_a - 1;
	tmp = data->stack_a[i];
	while (i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}
	data->stack_a[0] = tmp;
}

void	r_rotate_b(t_data *data)
{
	int	tmp;
	int	i;

	i = data->size_b - 1;
	tmp = data->stack_b[i];
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}
	data->stack_b[0] = tmp;
}

void	r_rotate_r(t_data *data)
{
	r_rotate_a(data);
	r_rotate_b(data);
}
