#include "include/libprintf.h"
#include "include/libft.h"

void	print_di(va_list args, t_flags f, int *printed)
{
	t_arg	arg;
	int		arg_len;
	int		sign = 0;
	int		s_printed = 0;
	int		arg_len2;

	arg.digit = va_arg(args, int);
	sign = arg.digit < 0;
	arg.str = ft_itoa(sign ? (arg.digit *= -1) : arg.digit);
	arg_len = (sign) ? ft_strlen(arg.str) + 1 : ft_strlen(arg.str);
	if (f.precision > f.width) {
//		f.width = (sign) ? ++f.precision : f.precision;
		(sign) ? ++f.precision : f.precision;
		f.zero_pad = 1;
	}
	if (f.precision > f.width && f.precision > arg_len)
		f.zero_pad = 1;
	if (sign && f.precision > arg_len && f.precision > f.width)
	{
		s_printed = 1;
		ft_putchar_fd('-', 1);
	}
	*printed += arg_len;
	if (f.left_justify)
	{
		if (!s_printed && sign)
		{
			ft_putchar_fd('-', 1);
			s_printed = 1;
		}
		if (arg_len < f.precision || f.left_justify)
			ft_putstr_fd(arg.str, 1);
	}
	arg_len2 = (f.precision > arg_len) ? f.precision : arg_len;
	while (f.width - arg_len2 > 0)
	{
		ft_putchar_fd(f.zero_pad ? '0' : ' ', 1);
		*printed += 1;
		f.width--;
	}
	if (!s_printed && sign && !f.left_justify && f.zero_pad && f.precision < 0)
		ft_putchar_fd('-', 1);
	while (f.precision - arg_len > 0)
	{
		ft_putchar_fd('0', 1);
		*printed += 1;
		f.precision--;
	}
	if (!(f.left_justify))
	{
		if (sign && !s_printed)
			ft_putchar_fd('-', 1);
		ft_putstr_fd(arg.str, 1);
	}

}