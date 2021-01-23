#include "include/libprintf.h"
#include "include/libft.h"

t_flags init_flag(void)
{
	t_flags flags;

	flags.width = 0;
	flags.left_justify = 0;
	flags.precision = 0;
	flags.zero_pad = 0;

	return (flags);
}

void	print_conversion(char str, va_list args, t_flags flags)
{
	t_arg arg;

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
	else if (str == 'd' || str == 'i')
	{

	}
	else if (str == '%')
		ft_putchar_fd('%', 1);
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
			while (ft_isdigit(*(str++)));
		}
		else if (*str == '0' && !ft_isdigit(*(str - 1)) && !flags->left_justify)
			flags->zero_pad = 1;
		else if (*str == '.')
			flags->precision = 1;
		else if (*str == '*')
			flags->width = va_arg(*args, int);
		else
		break;
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