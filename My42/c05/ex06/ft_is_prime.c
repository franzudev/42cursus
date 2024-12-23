/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:49:09 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/07 14:51:08 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int num;
	int i;

	num = nb;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	i = 3;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	if (nb % 2 == 0 && nb != 2)
		return (0);
	return (1);
}
