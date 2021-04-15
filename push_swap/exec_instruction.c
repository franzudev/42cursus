#include "push_swap.h"

void	exec_instruction(t_data *data)
{
	if (data->operation == "sa")
		ft_swap(data->stack_a, data->stack_a);
	else if (data->operation == "sb")
		ft_swap(data->stack_b, data->stack_b);
	else if (data->operation == "ss")
	{
		ft_swap(data->stack_a, data->stack_a);
		ft_swap(data->stack_b, data->stack_b);
	}
	else if (data->operation == "pa")
		push(data->stack_a, data->stack_b, data->size_a, data->size_b);
	else if (data->operation == "pb")
		push(data->stack_b, data->stack_a, data->size_b, data->size_a);
	else if (data->operation == "ra")
		ft_rotate(data->stack_a, data->size_a);
	else if (data->operation == "rb")
		ft_rotate(data->stack_b, data->size_b);
	else if (data->operation == "rr")
	{
		ft_rotate(data->stack_a, data->size_a);
		ft_rotate(data->stack_b, data->size_b);
	}
	else if (data->operation == "rra")
		r_rotate(data->stack_a, data->size_a);
	else if (data->operation == "rrb")
		r_rotate(data->stack_b, data->size_b);
	else if (data->operation == "rrr")
	{
		r_rotate(data->stack_a, data->size_a);
		r_rotate(data->stack_b, data->size_b);
	}
}