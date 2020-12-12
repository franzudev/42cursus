/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:44:34 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/10 11:54:27 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int		ft_sqrt(int nb)
{
	int result;

	if (nb == 1)
		return (1);
	result = 0;
	while (result < nb / 2 && result < 46341)
	{
		if (result * result == nb)
			return (result);
		else
			result++;
	}
	return (0);
}

int main()
{
	printf("%d", ft_sqrt(4));
	return (0);
}