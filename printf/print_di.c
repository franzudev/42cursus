/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:35:21 by franzu            #+#    #+#             */
/*   Updated: 2021/02/07 15:35:25 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "include/libft.h"

static void	print_sign(int *s_printed)
{
	ft_putchar_fd('-', 1);
	*s_printed = 1;
}

static void	print_pad(int ch, int *printed, int *len)
{
	ft_putchar_fd(ch, 1);
	*printed += 1;
	*len -= 1;
}

static void	print_num(char *num, t_flags f, t_helpers *h, int *printed)
{
	int len;

	len = ft_strlen(num);
	if (h->sign && !h->s_printed)
		print_sign(&h->s_printed);
	if (f.prec < f.width && f.left_justify)
		while (f.prec > len)
			print_pad('0', printed, &f.prec);
	ft_putstr_fd(num, 1);
}

static void	update_flags(t_flags *f, t_helpers *h, int len, int sign)
{
	if (f->left_justify && f->zero_pad)
		f->zero_pad = 0;
	if (f->zero_pad && f->prec < len && f->prec < f->width && f->prec != -1)
		f->zero_pad = 0;
	if (f->prec > len)
		f->zero_pad = 1;
	else
		f->prec = -1;
	if (f->prec > f->width && f->prec > len)
	{
		f->zero_pad = 1;
		f->left_justify = 0;
	}
	if ((sign && f->prec > len && f->prec > f->width) ||
	(sign && f->width > f->prec && f->prec < len && f->zero_pad))
		print_sign(&h->s_printed);
	h->width = f->width;
	h->prec = f->prec;
}

void		print_di(va_list args, t_flags f, int *printed)
{
	t_arg		arg;
	t_helpers	h;

	arg.digit = va_arg(args, int);
	h.s_printed = 0;
	h.sign = arg.digit < 0;
	if (arg.digit == 0 && f.prec == 0)
		arg.str = "";
	else
		arg.str = ft_itoa(h.sign ? (arg.digit *= -1) : arg.digit);
	h.arg_len = (h.sign) ? ft_strlen(arg.str) + 1 : ft_strlen(arg.str);
	update_flags(&f, &h, h.arg_len, h.sign);
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
