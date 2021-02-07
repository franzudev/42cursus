#include "include/libft.h"
#include "include/ft_printf.h"


/*static int	precision(const char *str, t_flags *flags, va_list *args)
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
}*/

int			flag_parser(const char *str, t_flags *flags, va_list *args)
{
	int i;

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
			continue ;
		}
		else if (*str == '*')
		{
			flags->width = va_arg(*args, int);
			if (flags->width < 0)
			{
				flags->left_justify = 1;
				flags->width *= -1;
			}
		}
		else
			break ;
		i++;
		str++;
	}
	return (i);
}