/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:43:07 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/07 14:43:10 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int res;
	int num;

	if (nb < 0)
		return (0);
	res = 1;
	num = nb;
	while (nb)
	{
		res *= nb--;
	}
	return (res);
}
