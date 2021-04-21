/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paperino.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:50:30 by lincerpi          #+#    #+#             */
/*   Updated: 2021/04/21 15:50:32 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	phase_one(t_sort *sort)
{
	int	mediana;

	while (!is_sorted_asc(sort->stack_a, sort->size_a))
	{
		mediana = check_mediana(sort->stack_a, sort->size_a);
		if (sort->stack_a[0] < mediana)
		{
			ft_push(sort->stack_b, sort->stack_a, &sort->size_b, &sort->size_a);
			write(1, "pb\n", 3);
		}
		else
		{
			ft_rotate(sort->stack_a, sort->size_a);
			write(1, "ra\n", 3);
		}
	}
}

static	void	phase_two(t_sort *sort)
{
	int	mediana;

	while (!is_sorted_desc(sort->stack_b, sort->size_b))
	{
		mediana = check_mediana(sort->stack_b, sort->size_b);
		if (sort->stack_b[0] > mediana)
		{
			ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
			write(1, "pa\n", 3);
		}
		else
		{
			ft_rotate(sort->stack_b, sort->size_b);
			write(1, "rb\n", 3);
		}
	}
}

static	void	phase_four(t_sort *sort)
{
	int	count;
	int	size;

	size = sort->size_a;
	count = 0;
	while (count < size)
	{
		if (sort->stack_a[0] + 1 == sort->stack_a[1])
		{
			ft_rotate(sort->stack_a, sort->size_a);
			write(1, "ra\n", 3);
			count++;
		}
		else if (sort->stack_a[0] < sort->stack_a[1])
		{
			ft_swap(sort->stack_a, sort->size_a);
			write(1, "sa\n", 3);
		}
		else
		{
			phase_four_plus(sort);
			count += 2;
		}
	}
}

static	void	phase_seven(t_sort *sort)
{
	int	check;

	ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
	write(1, "pa\n", 3);
	check = 1;
	while (!is_sorted_asc(sort->stack_a, sort->size_a))
	{
		if (sort->stack_a[0] == check)
		{
			ft_rotate(sort->stack_a, sort->size_a);
			write(1, "ra\n", 3);
			check++;
		}
		else if (sort->stack_a[0] > sort->stack_a[1])
			phase_seven_plus(sort);
		else
			phase_seven_three(sort, check);
	}
}

void	paperino(t_data *data)
{
	t_sort	sort;

	if (is_sorted_asc(data->stack_a, data->size_a))
		exit (0);
	generate_index_array(data, &sort);
	phase_one(&sort);
	phase_two(&sort);
	phase_four(&sort);
	phase_seven(&sort);
	free_pointer(sort.stack_a);
	free_pointer(sort.stack_b);
}
