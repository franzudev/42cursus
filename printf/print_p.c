#include "include/libprintf.h"
#include "include/libft.h"

void	print_p(va_list args, t_flags f, int *printed)
{
	t_arg	arg;
	int		arg_len;

	arg.str = ft_itoa_base((long)va_arg(args, void *), "0123456789abcdef");
	arg_len = ft_strlen(arg.str) + 2;
	*printed += arg_len;
	if (f.left_justify)
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(arg.str, 1);
	}
	if (f.width && f.width - arg_len > 0)
		while (f.width - arg_len)
		{
			ft_putchar_fd(' ', 1);
			*printed += 1;
			f.width--;
		}
	if (!(f.left_justify))
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(arg.str, 1);
	}
}

