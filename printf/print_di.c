#include "include/libprintf.h"
#include "include/libft.h"

void	print_di(va_list args, t_flags f, int *printed)
{
	t_arg	arg;
	int		arg_len;
	int		sign = 0;
	int		s_printed = 0;

	arg.digit = va_arg(args, int);
	sign = arg.digit < 0;
	arg.str = ft_itoa(sign ? (arg.digit *= -1) : arg.digit);
	arg_len = (sign) ? ft_strlen(arg.str) + 1 : ft_strlen(arg.str);
	if (f.precision > f.width) {
		f.width = (sign) ? ++f.precision : f.precision;
		f.zero_pad = 1;
	}
	if (f.precision > f.width && f.width > arg_len && !f.zero_pad)
		f.zero_pad = 1;
	if (sign && f.zero_pad)
	{
		s_printed = 1;
		ft_putchar_fd('-', 1);
	}
	*printed += arg_len;
	if (f.left_justify)
	{
		if (!s_printed && sign)
			ft_putchar_fd('-', 1);
		ft_putstr_fd(arg.str, 1);
	}
	if (f.width)
	{
		while (f.width - f.precision - arg_len > 0 && arg_len < f.precision)
		{
			if (f.zero_pad && !f.left_justify)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			*printed += 1;
			f.width--;
		}
	}
	if (!(f.left_justify))
	{
		if (!s_printed && sign)
			ft_putchar_fd('-', 1);
		ft_putstr_fd(arg.str, 1);
	}

}