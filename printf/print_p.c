/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 08:27:23 by franzu            #+#    #+#             */
/*   Updated: 2021/02/08 08:27:25 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	print_byte(int *printed)
{
	if (!*printed)
	{
		ft_putstr_fd("0x", 1);
		*printed = 1;
	}
}

static void	print(char *str, int *printed, int precision)
{
	print_byte(printed);
	if (precision != 0)
		ft_putstr_fd(str, 1);
}

static void	print_ppad(char ch, int *printed, int *len)
{
	ft_putchar_fd(ch, 1);
	*printed += 1;
	*len -= 1;
}

void		print_p(va_list args, t_flags f, int *printed)
{
	t_arg		arg;
	t_helpers	h;

	arg.pdigit = (unsigned long long)va_arg(args, void *);
	arg.str = ft_itoa_base_ull(arg.pdigit, "0123456789abcdef");
	h.arg_len = ft_strlen(arg.str) + 2;
	h.s_printed = 0;
	h.width = f.width;
	h.prec = f.prec;
	*printed += ((f.prec != 0) ? h.arg_len : --h.arg_len);
	if (f.left_justify)
		print(arg.str, &h.s_printed, f.prec);
	if (f.prec > f.width && f.prec > h.arg_len)
		print_byte(&h.s_printed);
	while (f.width > h.arg_len && f.width >= f.prec)
		print_ppad(' ', printed, &f.width);
	while (f.prec > h.arg_len || f.prec > h.width + 1)
		print_ppad('0', printed, &f.prec);
	if (!f.left_justify)
		print(arg.str, &h.s_printed, f.prec);
	delptr(1, arg.str, h.arg_len);
}
