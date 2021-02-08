/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:39:18 by franzu            #+#    #+#             */
/*   Updated: 2021/02/07 15:39:20 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_u(va_list args, t_flags f, int *printed)
{
	t_arg		arg;
	t_helpers	h;

	arg.ldigit = va_arg(args, unsigned int);
	h.s_printed = 0;
	h.sign = arg.ldigit < 0;
	if (arg.ldigit == 0 && f.prec == 0)
		arg.str = "";
	else
		arg.str = ft_itoa(h.sign ? (arg.ldigit *= -1) : arg.ldigit);
	h.arg_len = (h.sign) ? ft_strlen(arg.str) + 1 : ft_strlen(arg.str);
	update_flags(&f, &h);
	*printed += h.arg_len;
	if (f.left_justify)
		print_num(arg.str, f, &h, printed);
	while ((f.prec == -1 && f.width > h.arg_len)
			|| (!h.sign && f.prec != -1 && f.width > f.prec)
			|| (h.sign && f.prec != -1 && f.width > f.prec + h.sign))
		print_pad(f.zero_pad && f.prec == -1 ? '0' : ' ', printed, &f.width);
	if (h.sign && !h.s_printed && f.prec < h.width && !f.left_justify)
		print_sign(&h.s_printed);
	while (h.prec + h.sign > h.arg_len && !f.left_justify)
		print_pad('0', printed, &h.prec);
	if (!f.left_justify)
		print_num(arg.str, f, &h, printed);
}
