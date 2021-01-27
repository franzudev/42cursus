#include "include/libprintf.h"
#include "include/libft.h"

void	print_s(va_list args, t_flags f, int *printed)
{
	t_arg	arg;
	int		arg_len;

	arg.str = va_arg(args, char *);
	if (!arg.str)
		arg.str = "(null)";
	if (f.precision > -1)
		arg.str = ft_substr(arg.str, 0, f.precision);
	arg_len = ft_strlen(arg.str);
	*printed += arg_len;
	if (f.left_justify)
		ft_putstr_fd(arg.str, 1);
	if (f.width && f.width - arg_len > 0)
		while (f.width - arg_len)
		{
			ft_putchar_fd(f.zero_pad && !f.left_justify ? '0' : ' ', 1);
			*printed += 1;
			f.width--;
		}
	if (!(f.left_justify))
		ft_putstr_fd(arg.str, 1);
}