/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 08:27:54 by franzu            #+#    #+#             */
/*   Updated: 2021/02/08 08:27:57 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_per(t_flags f, int *printed)
{
	t_arg	arg;

	arg.chr = '%';
	*printed += 1;
	if (f.left_justify)
		ft_putchar_fd(arg.chr, 1);
	if (f.width)
		while (f.width - 1)
		{
			if (f.zero_pad && !f.left_justify)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			*printed += 1;
			f.width--;
		}
	if (!(f.left_justify))
		ft_putchar_fd(arg.chr, 1);
}
