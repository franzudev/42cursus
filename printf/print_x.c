#include "include/ft_printf.h"
#include "include/libft.h"


void	print_x(char str, va_list args, t_flags f, int *printed)
{
	t_arg	arg;
	int		arg_len;

	arg.udigit = va_arg(args, unsigned int);
	arg.str = ft_itoa_base(
		arg.udigit, str == 'x' ?
		"0123456789abcdef" : "0123456789ABCDEF");
	arg_len = ft_strlen(arg.str);
	*printed += arg_len;
	if (f.left_justify)
		ft_putstr_fd(arg.str, 1);
	if (f.width)
		while (f.width - arg_len > 0)
		{
			if (f.zero_pad && !f.left_justify && f.precision < 0)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			*printed += 1;
			f.width--;
		}
	if (!(f.left_justify))
		ft_putstr_fd(arg.str, 1);
}

