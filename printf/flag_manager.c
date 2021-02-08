/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 21:47:21 by franzu            #+#    #+#             */
/*   Updated: 2021/02/07 21:47:22 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	print_sign(int *s_printed)
{
	ft_putchar_fd('-', 1);
	*s_printed = 1;
}

void	print_pad(int ch, int *printed, int *len)
{
	ft_putchar_fd(ch, 1);
	*printed += 1;
	*len -= 1;
}

void	print_num(char *num, t_flags f, t_helpers *h, int *printed)
{
	int len;

	len = ft_strlen(num);
	if (h->sign && !h->s_printed)
		print_sign(&h->s_printed);
	if (f.prec <= f.width && f.left_justify)
		while (f.prec > len)
			print_pad('0', printed, &f.prec);
	ft_putstr_fd(num, 1);
}

void	update_flags(t_flags *f, t_helpers *h)
{
	h->width = f->width;
	h->prec = f->prec;
	if (f->left_justify && f->zero_pad)
		f->zero_pad = 0;
	if (f->zero_pad && f->prec < h->arg_len && f->prec < f->width &&
		f->prec != -1)
		f->zero_pad = 0;
	if (f->prec >= h->arg_len)
		f->zero_pad = 1;
	else
		f->prec = -1;
	if (f->prec > f->width && f->prec > h->arg_len)
	{
		f->zero_pad = 1;
		f->left_justify = 0;
	}
	if ((h->sign && f->prec > h->arg_len && f->prec >= f->width) ||
		(h->sign && f->width > f->prec && f->prec < h->arg_len && f->zero_pad))
		print_sign(&h->s_printed);
}
