/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:50:05 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/01 14:51:38 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_print_memory(void *addr, unsigned int size)
{
	int counter;

	counter = 0;
	if (!size)
		return (*addr);
	while (addr[counter])
	{
		counter++;
	}
}
