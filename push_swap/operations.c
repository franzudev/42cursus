/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:50:19 by lincerpi          #+#    #+#             */
/*   Updated: 2021/04/21 15:50:21 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *stack, int size)
{
	int	temp;

	if (size < 2)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	ft_push(int *dest, int *source, int *size_dest, int *size_source)
{
	int	i;

	if (*size_source == 0)
		return ;
	i = *size_dest;
	while (i > 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	dest[0] = source[0];
	i = 0;
	while (++i < *size_source)
		source[i - 1] = source[i];
	*size_source -= 1;
	*size_dest += 1;
}

void	ft_rotate(int *stack, int size)
{
	int	i;
	int	temp;

	if (size == 0)
		return ;
	i = 0;
	temp = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
}

void	ft_r_rotate(int *stack, int size)
{
	int	tmp;
	int	i;

	i = size - 1;
	tmp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}
