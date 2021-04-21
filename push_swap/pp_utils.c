#include "push_swap.h"

static void	phase_two_bis(t_data *data, int raffaello)
{
	if (raffaello == 0)
	{
		ft_rotate(data->stack_a, data->size_a);
		if (!is_sorted_desc(data->stack_b, data->size_b))
		{
			ft_rotate(data->stack_b, data->size_b);
			write(1, "rr\n", 3);
		}
		else
			write(1, "ra\n", 3);
	}
	if (raffaello == 1)
	{
		ft_r_rotate(data->stack_a, data->size_a);
		if (!is_sorted_desc(data->stack_b, data->size_b))
		{
			ft_r_rotate(data->stack_b, data->size_b);
			write(1, "rrr\n", 4);
		}
		else
			write(1, "rra\n", 4);
	}
}

static void	phase_two(t_data *data, t_sort *sort)
{
	int	raffaello;

	raffaello = 0;
	while (!is_sorted_asc(data->stack_a, data->size_a))
	{
		if (data->stack_a[0] == sort->stack[sort->size - 1])
			raffaello = 1;
		if (data->stack_a[0] == sort->mediana)
			raffaello = 0;
		if (data->stack_a[0] > data->stack_a[1])
		{
			ft_swap(data->stack_a, data->size_a);
			if (data->stack_b[0] < data->stack_b[1])
			{
				ft_swap(data->stack_b, data->size_b);
				write(1, "ss\n", 3);
			}
			else
				write(1, "sa\n", 3);
		}
		else
			phase_two_bis(data, raffaello);
	}
}

static int	phase_three_bis(t_data *data, t_sort *sort, int michelangelo)
{
	if (data->stack_b[0] == sort->stack[0])
		michelangelo = 1;
	if (data->stack_b[0] == sort->stack[sort->index_mediana - 1])
		michelangelo = 0;
	if (michelangelo == 0)
	{
		ft_rotate(data->stack_b, data->size_b);
		write(1, "rb\n", 3);
	}
	if (michelangelo == 1)
	{
		ft_r_rotate(data->stack_b, data->size_b);
		write(1, "rrb\n", 4);
	}
	return (michelangelo);
}

static void	phase_three(t_data *data, t_sort *sort)
{
	int	michelangelo;

	michelangelo = 0;
	while (!is_sorted_desc(data->stack_b, data->size_b))
	{
		if (data->stack_b[0] < data->stack_b[1])
		{
			if (data->stack_b[0] == sort->stack[0])
				michelangelo = 1;
			if (data->stack_b[0] == sort->stack[sort->index_mediana - 1])
				michelangelo = 0;
			ft_swap(data->stack_b, data->size_b);
			write(1, "sb\n", 3);
		}
		else
			michelangelo = phase_three_bis(data, sort, michelangelo);
	}
}

void	phase_magic(t_data *data, t_sort *sort)
{
	phase_two(data, sort);
	phase_three(data, sort);
	while (data->size_b)
	{
		ft_push(data->stack_a, data->stack_b, &data->size_a, &data->size_b);
		write(1, "pa\n", 3);
	}
}
