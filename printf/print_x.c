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

#include "ft_printf.h"
#include "libft.h"

static void	ufh(t_helpers *h, t_arg *arg, t_flags *f, int *p)
{
	h->arg_len = ft_strlen(arg->str);
	update_flags(f, h);
	*p += h->arg_len;
}

void		print_x(char str, va_list args, t_flags f, int *printed)
{
	t_arg		arg;
	t_helpers	h;

	h.sign = 0;
	h.alloc = 0;
	arg.udigit = va_arg(args, unsigned int);
	if (arg.udigit == 0 && f.prec == 0)
		arg.str = "";
	else
	{
		h.alloc = 1;
		arg.str = ft_itoa_base(arg.udigit, str == 'x' ? "0123456789abcdef" :
		"0123456789ABCDEF");
	}
	ufh(&h, &arg, &f, printed);
	if (f.left_justify)
		print_num(arg.str, f, &h, printed);
	while ((f.prec == -1 && f.width > h.arg_len) || (f.prec != -1 && f.width
	> f.prec))
		print_pad(f.zero_pad && f.prec == -1 ? '0' : ' ', printed, &f.width);
	while (h.prec != -1 && h.prec + h.sign > h.arg_len && !f.left_justify)
		print_pad('0', printed, &h.prec);
	if (!f.left_justify)
		print_num(arg.str, f, &h, printed);
	delptr(h.alloc, arg.str, h.arg_len);
}
