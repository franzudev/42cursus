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

static void print_num(char *num, t_flags f, int sign, int *s_printed, int *printed)
{
	int len;
	len = ft_strlen(num);
	if (sign && !*s_printed)
		print_sign(s_printed);
	if (f.prec < f.width && f.left_justify)
		while (f.prec > len)
			print_pad('0', printed, &f.prec);
	ft_putstr_fd(num, 1);
}

static void	update_flags(t_flags *f, int *s_p, int len, int sign)
{
	if (f->left_justify && f->zero_pad)
		f->zero_pad = 0;
	if (f->prec > len)
		f->zero_pad = 1;
	else
		f->prec = -1;
	if (f->prec > f->width && f->prec > len)
		f->zero_pad = 1;
	if ((sign && f->prec > len && f->prec > f->width) || (sign && f->width > f->prec && f->prec < len && f->zero_pad))
		print_sign(s_p);
}

void		print_di(va_list args, t_flags f, int *printed)
{
	t_arg	arg;
	int		arg_len;
	int		sign;
	int		s_printed;
	int		width;
	int		prec;

	arg.digit = va_arg(args, int);
	s_printed = 0;
	sign = arg.digit < 0;
	if (arg.digit == 0 && f.prec == 0)
		arg.str = "";
	else
		arg.str = ft_itoa(sign ? (arg.digit *= -1) : arg.digit);
	arg_len = (sign) ? ft_strlen(arg.str) + 1 : ft_strlen(arg.str);
	update_flags(&f, &s_printed, arg_len, sign);
	width = f.width;
	prec = f.prec;
	*printed += arg_len;
	if (f.left_justify)
		print_num(arg.str, f, sign, &s_printed, printed);
	while ((f.prec == -1 && f.width > arg_len) || (!sign && f.prec != -1 && f.width > f.prec) || ((sign && f.prec != -1 && f.width > f.prec + sign)))
		print_pad(f.zero_pad && f.prec == -1 ? '0' : ' ', printed, &f.width);
	if (sign && !s_printed && f.prec < width && !f.left_justify)
		print_sign(&s_printed);
	while (prec + sign > arg_len && !f.left_justify)
		print_pad('0', printed, &prec);
	if (!f.left_justify)
		print_num(arg.str, f, sign, &s_printed, printed);
}