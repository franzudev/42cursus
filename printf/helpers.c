#include "include/libprintf.h"
#include "include/libft.h"
#include <stdio.h>

t_flags init_flag(void)
{
	t_flags flags;

	flags.width = 0;
	flags.left_justify = 0;
	flags.precision = -1;
	flags.zero_pad = 0;

	return (flags);
}

void	print_conversion(char str, va_list args, t_flags flags)
{
	t_arg	arg;
	int		arg_len;

	if (str == 'c')
	{
		arg.chr = va_arg(args, int);
		if (flags.left_justify)
			ft_putchar_fd(arg.chr, 1);
		if (flags.width)
			while (flags.width - 1)
			{
				ft_putchar_fd(' ', 1);
				flags.width--;
			}
		if (!(flags.left_justify))
			ft_putchar_fd(arg.chr, 1);
	}
	else if (str == 's')
	{
		arg.str = va_arg(args, char *);
		if (flags.precision > -1)
			arg.str = ft_substr(arg.str, 0, flags.precision);
		arg_len = ft_strlen(arg.str);
		if (flags.left_justify)
			ft_putstr_fd(arg.str, 1);
		if (flags.width && flags.width - arg_len > 0)
			while (flags.width - arg_len)
			{
				ft_putchar_fd(' ', 1);
				flags.width--;
			}
		if (!(flags.left_justify))
			ft_putstr_fd(arg.str, 1);
	}
	else if (str == '%')
	{
		arg.chr = '%';
		if (flags.left_justify)
			ft_putchar_fd(arg.chr, 1);
		if (flags.width)
			while (flags.width - 1)
			{
				if (flags.zero_pad && !flags.left_justify)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
				flags.width--;
			}
		if (!(flags.left_justify))
			ft_putchar_fd(arg.chr, 1);
	}
	else if (str == 'd' || str == 'i')
	{
		arg.digit = va_arg(args, int);
		ft_putstr_fd(ft_itoa(arg.digit), 1);
	}
	else if (str == 'u')
	{
		arg.udigit = va_arg(args, unsigned int);
		ft_putstr_fd(ft_itoa(arg.udigit), 1);
	}
}

int		parse_flag(const char *str, va_list *args, t_flags *flags)
{
	int	i;

	if (!flags)
		return (0);
	i = 0;
	while (*str) {
		if (*str == '-')
			flags->left_justify = 1;
		else if (*str != '0' && ft_isdigit(*str))
		{
			flags->width = ft_atoi(str);
			while (ft_isdigit(*str))
			{
				str++;
				i++;
			}
			continue ;
		}
		else if (*str == '0' && !ft_isdigit(*(str - 1)))
			flags->zero_pad = 1;
		else if (*str == '.')
		{
			if (!ft_isdigit(*(++str)))
				flags->precision = 0;
			else
				flags->precision = ft_atoi(str);
			++i;
			while (ft_isdigit(*str))
			{
				str++;
				i++;
			}
			continue ;
		}
		else if (*str == '*')
			flags->width = va_arg(*args, int);
		else
			break ;
		i++;
		str++;
	}
	return (i);
}

int		print_parameter(const char *str, va_list *args)
{
	t_flags flags;
	int 	forward;

	forward = 0;
	flags = init_flag();
	if ((ft_strchr("-0.*", *str) || ft_isdigit(*str)))
		forward = parse_flag(str, args, &flags);
	print_conversion(*(str + forward++), *args, flags);
	return (++forward);
}

int		parse_format(const char *str, va_list *args)
{
	while(*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			return (1);
		}
		else if(*str == '%')
			return print_parameter(++str, args);
		str++;
	}
	return (0);
}