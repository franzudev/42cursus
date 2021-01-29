#include "include/ft_printf.h"
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
	else if (ft_strchr("di", str))
		print_di(args, f, printed);
	else if (str == 'u')
		print_u(args, f, printed);
	else if (str == 'x' || str == 'X')
		print_x(str, args, f, printed);
	else if (str == 'p')
		print_p(args, f, printed);
	else
		*printed = -1;
}

static int		parse_flag(const char *str, va_list *args, t_flags *flags)
{
	int	i;

	if (!flags)
		return (0);
	i = 0;
	while (*str)
	{
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
	t_flags	flags;
	int		forward;

	forward = 0;
	flags = init_flag();
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
