/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topolino.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <ffrancoi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:51:13 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/21 15:51:15 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	topolina(t_data *data)
{
	if (data->stack_a[0] > data->stack_a[2])
	{
		if (data->stack_a[1] < data->stack_a[2])
		{
			ft_rotate(data->stack_a, data->size_a);
			write(1, "ra\n", 3);
		}
		else
		{
			ft_swap(data->stack_a, data->size_a);
			ft_r_rotate(data->stack_a, data->size_a);
			write(1, "sa\nrra\n", 7);
		}
	}
	else
	{
		ft_swap(data->stack_a, data->size_a);
		write(1, "sa\n", 3);
	}
}

void	topolino(t_data *data)
{
	if (is_sorted_asc(data->stack_a, data->size_a))
		exit (0);
	else
	{
		if (data->stack_a[0] < data->stack_a[1])
		{
			if (data->stack_a[0] < data->stack_a[2])
			{
				ft_swap(data->stack_a, data->size_a);
				ft_rotate(data->stack_a, data->size_a);
				write(1, "sa\nra\n", 6);
			}
			else
			{
				ft_r_rotate(data->stack_a, data->size_a);
				write(1, "rra\n", 4);
			}
		}
		else
			topolina(data);
	}
}
