#include "include/libprintf.h"
#include "include/libft.h"

static t_flags	init_flag(void)
{
	t_flags flags;

	flags.width = 0;
	flags.left_justify = 0;
	flags.precision = -1;
	flags.zero_pad = 0;

	return (flags);
}

static void		print_conversion(char str, va_list args, t_flags flags, int
*printed)
{
	t_arg	arg;
	int		arg_len;

	if (str == 'c')
	{
		arg.chr = va_arg(args, int);
		*printed += 1;
		if (flags.left_justify)
			ft_putchar_fd(arg.chr, 1);
		if (flags.width)
			while (flags.width - 1)
			{
				ft_putchar_fd(' ', 1);
				*printed += 1;
				flags.width--;
			}
		if (!(flags.left_justify))
			ft_putchar_fd(arg.chr, 1);
	}
	else if (str == 's')
	{
		arg.str = va_arg(args, char *);
		if (!arg.str)
			arg.str = "(null)";
		if (flags.precision > -1)
			arg.str = ft_substr(arg.str, 0, flags.precision);
		arg_len = ft_strlen(arg.str);
		*printed += arg_len;
		if (flags.left_justify)
			ft_putstr_fd(arg.str, 1);
		if (flags.width && flags.width - arg_len > 0)
			while (flags.width - arg_len)
			{
				ft_putchar_fd(' ', 1);
				*printed += 1;
				flags.width--;
			}
		if (!(flags.left_justify))
			ft_putstr_fd(arg.str, 1);
	}
	else if (str == '%')
	{
		arg.chr = '%';
		*printed += 1;
		if (flags.left_justify)
			ft_putchar_fd(arg.chr, 1);
		if (flags.width)
			while (flags.width - 1)
			{
				if (flags.zero_pad && !flags.left_justify)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
				*printed += 1;
				flags.width--;
			}
		if (!(flags.left_justify))
			ft_putchar_fd(arg.chr, 1);
	}
	else if (ft_strchr("di", str))
	{
		arg.str = ft_itoa(va_arg(args, int));
		arg_len = ft_strlen(arg.str);
		*printed += arg_len;
		if (flags.left_justify)
			ft_putstr_fd(arg.str, 1);
		if (flags.width)
			while (flags.width - arg_len > 0)
			{
				if (flags.zero_pad && !flags.left_justify && flags.precision < 0)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
				*printed += 1;
				flags.width--;
			}
		if (!(flags.left_justify))
			ft_putstr_fd(arg.str, 1);
	}
	else if (str == 'u')
	{
		arg.str = ft_itoa(va_arg(args, unsigned int));
		arg_len = ft_strlen(arg.str);
		*printed += arg_len;
		if (flags.left_justify)
			ft_putstr_fd(arg.str, 1);
		if (flags.width)
			while (flags.width - arg_len > 0)
			{
				if (flags.zero_pad && !flags.left_justify && flags.precision < 0)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
				*printed += 1;
				flags.width--;
			}
		if (!(flags.left_justify))
			ft_putstr_fd(arg.str, 1);
	}
	else if (str == 'x' || str == 'X')
	{
		if (str == 'x')
			arg.str = ft_itoa_base(va_arg(args, unsigned int), "0123456789abcdef");
		else
			arg.str = ft_itoa_base(va_arg(args, unsigned int), "0123456789ABCDEF");
		arg_len = ft_strlen(arg.str);
		*printed += arg_len;
		if (flags.left_justify)
			ft_putstr_fd(arg.str, 1);
		if (flags.width)
			while (flags.width - arg_len > 0)
			{
				if (flags.zero_pad && !flags.left_justify && flags.precision < 0)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
				*printed += 1;
				flags.width--;
			}
		if (!(flags.left_justify))
			ft_putstr_fd(arg.str, 1);
	}
	else if (str == 'p')
	{
		arg.str = ft_itoa_base((long)va_arg(args, void *), "0123456789abcdef");
		arg_len = ft_strlen(arg.str) + 2;
		*printed += arg_len;
		if (flags.left_justify)
		{
			ft_putstr_fd("0x", 1);
			ft_putstr_fd(arg.str, 1);
		}
		if (flags.width && flags.width - arg_len > 0)
			while (flags.width - arg_len)
			{
				ft_putchar_fd(' ', 1);
				*printed += 1;
				flags.width--;
			}
		if (!(flags.left_justify))
		{
			ft_putstr_fd("0x", 1);
			ft_putstr_fd(arg.str, 1);
		}
	}
	else
		*printed = -1;
}

static int		parse_flag(const char *str, va_list *args, t_flags *flags)
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
		else if (*str == '0' && (!ft_isdigit(*(str - 1)) || *(str - 1) == '0'))
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

static int		print_parameter(const char *str, va_list *args, int *printed)
{
	t_flags flags;
	int 	forward;

	forward = 0;
	flags = init_flag();
	if ((ft_strchr("-0.*", *str) || ft_isdigit(*str)))
		forward = parse_flag(str, args, &flags);
	print_conversion(*(str + forward++), *args, flags, printed);
	return (*printed == -1 ? -1 : ++forward);
}

int		parse_format(const char *str, va_list *args, int *printed)
{
	while(*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			*printed += 1;
			return (1);
		}
		else if(*str == '%')
			return print_parameter(++str, args, printed);
		str++;
	}
	return (0);
}