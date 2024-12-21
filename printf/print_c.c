/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 21:19:37 by franzu            #+#    #+#             */
/*   Updated: 2021/02/07 21:19:38 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_c(va_list args, t_flags f, int *printed)
{
	t_arg	arg;

	arg.chr = va_arg(args, int);
	*printed += 1;
	if (f.left_justify)
		ft_putchar_fd(arg.chr, 1);
	if (f.width)
		while (f.width - 1)
		{
			ft_putchar_fd(' ', 1);
			*printed += 1;
			f.width--;
		}
	if (!(f.left_justify))
		ft_putchar_fd(arg.chr, 1);
}
