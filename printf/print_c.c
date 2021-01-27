#include "include/libprintf.h"
#include "include/libft.h"

void	print_c(va_list args, t_flags f, int *printed)
{
	t_arg	arg;

	arg.chr = va_arg(args, int);
	*printed += 1;
	if (f.left_justify)
		ft_putchar_fd(arg.chr, 1);
	if (f.width)
		while (f.width - 1)
		{
			ft_putchar_fd(' ', 1);
			*printed += 1;
			f.width--;
		}
	if (!(f.left_justify))
		ft_putchar_fd(arg.chr, 1);
}