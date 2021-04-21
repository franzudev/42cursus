/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:50:08 by lincerpi          #+#    #+#             */
/*   Updated: 2021/04/21 15:50:10 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	call_reverse_rotate(t_data *data)
{
	if (!ft_strcmp(data->operation, "rra"))
		ft_r_rotate(data->stack_a, data->size_a);
	else if (!ft_strcmp(data->operation, "rrb"))
		ft_r_rotate(data->stack_b, data->size_b);
	else if (!ft_strcmp(data->operation, "rrr"))
	{
		ft_r_rotate(data->stack_a, data->size_a);
		ft_r_rotate(data->stack_b, data->size_b);
	}
}

static	void	call_push(t_data *data)
{
	if (!ft_strcmp(data->operation, "pa"))
		ft_push(data->stack_a, data->stack_b, &data->size_a, &data->size_b);
	else if (!ft_strcmp(data->operation, "pb"))
		ft_push(data->stack_b, data->stack_a, &data->size_b, &data->size_a);
}

static	void	call_rotate(t_data *data)
{
	if (!ft_strcmp(data->operation, "ra"))
		ft_rotate(data->stack_a, data->size_a);
	else if (!ft_strcmp(data->operation, "rb"))
		ft_rotate(data->stack_b, data->size_b);
	else if (!ft_strcmp(data->operation, "rr"))
	{
		ft_rotate(data->stack_a, data->size_a);
		ft_rotate(data->stack_b, data->size_b);
	}
}

static	void	call_swap(t_data *data)
{
	if (!ft_strcmp(data->operation, "sa"))
		ft_swap(data->stack_a, data->size_a);
	else if (!ft_strcmp(data->operation, "sb"))
		ft_swap(data->stack_b, data->size_a);
	else if (!ft_strcmp(data->operation, "ss"))
	{
		ft_swap(data->stack_a, data->size_a);
		ft_swap(data->stack_b, data->size_b);
	}
}

void	exec_instruction(t_data *data)
{
	call_swap(data);
	call_push(data);
	call_rotate(data);
	call_reverse_rotate(data);
}
