/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:48:37 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/02/05 16:48:39 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "include/libft.h"

void	print_pad(t_flags f, int arg_len, int *printed)
{
	if ((f.width && f.width - arg_len > 0) || (f.prec && f.prec - arg_len > 0))
		while (f.width - arg_len > 0)
		{
			ft_putchar_fd(f.zero_pad && !f.left_justify ? '0' : ' ', 1);
			*printed += 1;
			f.width--;
		}
}

void	delptr(int alloc, char *str, int len)
{
	if (alloc)
	{
		ft_memset(str, '\0', len);
		free(str);
		str = NULL;
	}
}

void	print_s(va_list args, t_flags f, int *printed)
{
	t_arg	arg;
	int		arg_len;
	int		alloc;

	alloc = 0;
	arg.digit = 0;
	arg.str = va_arg(args, char *);
	if (!arg.str)
		arg.str = "(null)\0";
	else if (*arg.str == '\0' && f.prec != -1 && !f.width)
		return ;
	if (f.prec > -1)
	{
		arg.str = ft_substr(arg.str, 0, f.prec);
		alloc = 1;
	}
	arg_len = ft_strlen(arg.str);
	*printed += arg_len;
	if (f.left_justify && arg_len)
		ft_putstr_fd(arg.str, 1);
	print_pad(f, arg_len, printed);
	if (!(f.left_justify) && arg_len)
		ft_putstr_fd(arg.str, 1);
	delptr(alloc, arg.str, arg_len);
}
