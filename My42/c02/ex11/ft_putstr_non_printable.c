/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:06:12 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/03 15:00:30 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	ft_print_hexa(char np)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (np > 16)
	{
		ft_print_hexa(np / 10);
		ft_print_hexa(np % 10);
	}
	else
		print(hex[(int)np]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 32 && str[i] >= 0) || str[i] >= 127)
		{
			print('\\');
			if (str[i] < 16)
				print('0');
			ft_print_hexa(str[i]);
		}
		else
			print(str[i]);
		i += 1;
	}
}
