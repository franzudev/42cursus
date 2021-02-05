#include "include/ft_printf.h"
#include "include/libft.h"

static void	print_sign(int *s_printed)
{
	ft_putchar_fd('-', 1);
	*s_printed = 1;
}

static void	print_pad(int ch, int *printed, int *len)
{
	ft_putchar_fd(ch, 1);
	*printed += 1;
	*len -= 1;
}

void	print_num()
{

}

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
	if (f.prec > f.width) {
//		f.width = (sign) ? ++f.prec : f.prec;
		(sign) ? ++f.prec : f.prec;
		f.zero_pad = 1;
	}
	if (f.prec > f.width && f.prec > arg_len)
		f.zero_pad = 1;
	if ((sign && f.prec > arg_len && f.prec > f.width) || (sign && f.width > arg_len && f.zero_pad))
		print_sign(&s_printed);
	*printed += arg_len;
	if (f.left_justify)
	{
		if (!s_printed && sign)
			print_sign(&s_printed);
		if ((arg_len < f.prec || f.left_justify))
			ft_putstr_fd(arg.str, 1);
	}
	arg_len2 = (f.prec > arg_len) ? f.prec : arg_len;
	while (f.width - arg_len2 > 0)
		if (f.zero_pad)
			print_pad('0', printed, &f.width);
		else
			print_pad(' ', printed, &f.width);
	if (!s_printed && sign && !f.left_justify && f.zero_pad && f.prec < 0)
	{
        ft_putchar_fd('-', 1);
        s_printed = 1;
    }
	while (f.prec - arg_len > 0)
		print_pad('0', printed, &f.prec);
	if (!(f.left_justify))
	{
		if (sign && !s_printed)
			ft_putchar_fd('-', 1);
		ft_putstr_fd(arg.str, 1);
	}
}