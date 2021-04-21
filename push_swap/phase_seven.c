#include "push_swap.h"

static void	seven_continue(t_sort *sort, int check)
{
	if (ft_find_nb(sort->stack_b, sort->size_b, check))
	{
		while (sort->stack_b[0] != check)
		{
			ft_r_rotate(sort->stack_b, sort->size_b);
			write(1, "rrb\n", 4);
		}
		ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
		write(1, "pa\n", 3);
	}
	else
	{
		while (sort->stack_b[0] != check)
		{
			ft_rotate(sort->stack_b, sort->size_b);
			write(1, "rb\n", 3);
		}
		ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
		write(1, "pa\n", 3);
	}
}

void	phase_seven_three(t_sort *sort, int check)
{
	int	giri;

	if (ft_find_stack(sort->stack_a, sort->size_a, check))
	{
		giri = 0;
		while (sort->stack_a[0] != check)
		{
			ft_rotate(sort->stack_a, sort->size_a);
			write(1, "ra\n", 3);
			giri++;
		}
		ft_push(sort->stack_b, sort->stack_a, &sort->size_b, &sort->size_a);
		write(1, "pb\n", 3);
		while (giri > 0)
		{
			ft_r_rotate(sort->stack_a, sort->size_a);
			write(1, "rra\n", 4);
			giri--;
		}
		ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
		write(1, "pa\n", 3);
	}
	else
		seven_continue(sort, check);
}

void	phase_seven_plus(t_sort *sort)
{
	ft_swap(sort->stack_a, sort->size_a);
	if (sort->stack_b[0] < sort->stack_b[1])
	{
		ft_swap(sort->stack_b, sort->size_b);
		write(1, "ss\n", 3);
	}
	else
		write(1, "sa\n", 3);
}

void	phase_four_plus(t_sort *sort)
{
	ft_rotate(sort->stack_a, sort->size_a);
	ft_push(sort->stack_b, sort->stack_a, &sort->size_b, &sort->size_a);
	write(1, "ra\npb\n", 6);
}
