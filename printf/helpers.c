/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 08:20:37 by franzu            #+#    #+#             */
/*   Updated: 2021/02/08 08:20:38 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static t_flags	init_flag(void)
{
	t_flags flags;

	flags.width = 0;
	flags.left_justify = 0;
	flags.prec = -1;
	flags.zero_pad = 0;
	return (flags);
}

/*
**	pc = print_conversion -> norminette adaptation
*/

static void		pc(char str, va_list args, t_flags f, int *printed)
{
	if (str == 'c')
		print_c(args, f, printed);
	else if (str == 's')
		print_s(args, f, printed);
	else if (str == '%')
		print_per(f, printed);
	else if (str == 'i' || str == 'd' || str == 'u')
		print_diu(args, f, printed, str == 'u');
	else if (str == 'x' || str == 'X')
		print_x(str, args, f, printed);
	else if (str == 'p')
		print_p(args, f, printed);
	else
		*printed = -1;
}

static int		parse_flag(const char *str, va_list *args, t_flags *flags)
{
	if (!flags)
		return (0);
	return (flag_parser(str, flags, args));
}

static int		print_parameter(const char *str, va_list *args, int *printed)
{
	t_flags	flags;
	int		forward;

	forward = 0;
	flags = init_flag();
	if (*str == '\0')
	{
		*printed = -1;
		return (0);
	}
	if ((ft_strchr("-0.*", *str) || ft_isdigit(*str)))
		forward = parse_flag(str, args, &flags);
	pc(*(str + forward++), *args, flags, printed);
	return (*printed == -1 ? -1 : ++forward);
}

int				parse_format(const char *str, va_list *args, int *printed)
{
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			*printed += 1;
			return (1);
		}
		else if (*str == '%')
			return (print_parameter(++str, args, printed));
		str++;
	}
	return (0);
}
