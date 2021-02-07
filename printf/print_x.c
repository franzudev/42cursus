/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:15:29 by franzu            #+#    #+#             */
/*   Updated: 2021/02/07 16:15:31 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "include/libft.h"

static void	print_pad(int ch, int *printed, int *len)
{
	ft_putchar_fd(ch, 1);
	*printed += 1;
	*len -= 1;
}

static void	print_num(char *num, t_flags f, int *printed)
{
	int len;

	len = ft_strlen(num);
	if (f.prec < f.width && f.left_justify)
		while (f.prec > len)
			print_pad('0', printed, &f.prec);
	ft_putstr_fd(num, 1);
}

void	update_flags(t_flags *f, t_helpers *h, int len)
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
	h->width = f->width;
	h->prec = f->prec;
}

void		print_x(char str, va_list args, t_flags f, int *printed)
{
	t_arg		arg;
	t_helpers	h;
	int			alloc;

	arg.udigit = va_arg(args, unsigned int);
	if (arg.udigit == 0 && f.prec == 0)
		arg.str = "";
	else
	{
		h.sign = arg.udigit < 0;
		alloc = arg.udigit ? 1 : 0;
		arg.str = ft_itoa_base(arg.udigit, str == 'x' ? "0123456789abcdef" :
		"0123456789ABCDEF");
	}
	h.arg_len = (h.sign) ? ft_strlen(arg.str) + 1 : ft_strlen(arg.str);
	update_flags(&f, &h, h.arg_len);
	*printed += h.arg_len;
	if (f.left_justify)
		print_num(arg.str, f, printed);
	while ((f.prec == -1 && f.width > h.arg_len)
			|| (!h.sign && f.prec != -1 && f.width > f.prec)
			|| (h.sign && f.prec != -1 && f.width > f.prec + h.sign))
		print_pad(f.zero_pad && f.prec == -1 ? '0' : ' ', printed, &f.width);
	while (h.prec != -1 && h.prec + h.sign > h.arg_len && !f.left_justify)
		print_pad('0', printed, &h.prec);
	if (!f.left_justify)
		print_num(arg.str, f, printed);
	delptr(alloc, arg.str, h.arg_len);
}
