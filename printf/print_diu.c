/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:35:21 by franzu            #+#    #+#             */
/*   Updated: 2021/02/07 21:28:38 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "include/libft.h"

void	set_arg(t_arg *arg, t_flags *f, t_helpers *h)
{
	if (arg->ldigit == 0 && f->prec > -1)
		arg->str = "";
	else
	{
		h->alloc = arg->ldigit ? 1 : 0;
		arg->str = ft_itoa(h->sign ? (arg->ldigit *= -1) : arg->ldigit);
	}
}

void	print_diu(va_list args, t_flags f, int *printed, int uns)
{
	t_arg		arg;
	t_helpers	h;

	arg.ldigit = (uns) ? va_arg(args, unsigned int) : (long)va_arg(args, int);
	h.s_printed = 0;
	h.sign = arg.ldigit < 0;
	h.alloc = 0;
	set_arg(&arg, &f, &h);
	h.arg_len = (h.sign) ? ft_strlen(arg.str) + 1 : ft_strlen(arg.str);
	update_flags(&f, &h);
	*printed += h.arg_len;
	if (f.left_justify)
		print_num(arg.str, f, &h, printed);
	while ((f.prec == -1 && f.width > h.arg_len)
	|| (!h.sign && f.prec != -1 && f.width > f.prec)
	|| (h.sign && f.prec != -1 && f.width > f.prec + h.sign))
		print_pad(f.zero_pad && h.prec == -1 ? '0' : ' ', printed, &f.width);
	if (h.sign && !h.s_printed && f.prec < h.width && !f.left_justify)
		print_sign(&h.s_printed);
	while (h.prec + h.sign > h.arg_len && !f.left_justify)
		print_pad('0', printed, &h.prec);
	if (!f.left_justify)
		print_num(arg.str, f, &h, printed);
	delptr(h.alloc, arg.str, h.arg_len);
}
