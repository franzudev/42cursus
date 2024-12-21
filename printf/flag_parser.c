/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 08:18:13 by franzu            #+#    #+#             */
/*   Updated: 2021/02/08 08:18:15 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	pw(t_flags *flags, const char *str)
{
	int i;

	i = 0;
	flags->width = ft_atoi(str);
	while (ft_isdigit(*str))
	{
		str++;
		i++;
	}
	return (i);
}

static int	precision(const char *str, t_flags *flags, va_list *args)
{
	int i;

	i = 0;
	if (*(++str) == '*')
	{
		i++;
		str++;
		flags->prec = va_arg(*args, int);
		if (flags->prec < 0)
			flags->prec = -1;
	}
	else if (!ft_isdigit(*str))
		flags->prec = 0;
	else
		flags->prec = ft_atoi(str);
	++i;
	while (ft_isdigit(*str))
	{
		str++;
		i++;
	}
	return (i);
}

static void	star_width(t_flags *flags, va_list *args)
{
	flags->width = va_arg(*args, int);
	if (flags->width < 0)
	{
		flags->left_justify = 1;
		flags->width *= -1;
	}
}

int			flag_parser(const char *str, t_flags *flags, va_list *args)
{
	int i;
	int tmp;

	i = 0;
	while (*str)
	{
		if (*str == '-')
			flags->left_justify = 1;
		else if ((*str != '0' && ft_isdigit(*str)) || *str == '.')
		{
			tmp = *str == '.' ? precision(str, flags, args) : pw(flags, str);
			i += tmp;
			str += tmp;
			continue ;
		}
		else if (*str == '0' && (!ft_isdigit(*(str - 1)) || *(str - 1) == '0'))
			flags->zero_pad = 1;
		else if (*str == '*')
			star_width(flags, args);
		else
			break ;
		i++;
		str++;
	}
	return (i);
}
