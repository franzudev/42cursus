#include "include/ft_printf.h"
#include "include/libft.h"

static void print_byte(int *printed)
{
	if (!*printed)
	{
		ft_putstr_fd("0x", 1);
		*printed = 1;
	}
}

static void print(char *str, int *printed, int precision)
{
        print_byte(printed);
        if (precision != 0)
            ft_putstr_fd(str, 1);
}

void	print_p(va_list args, t_flags f, int *printed)
{
	t_arg		arg;
	t_helpers	h;

	arg.pdigit = va_arg(args, void *);
    arg.str = ft_itoa_base((long)arg.pdigit, "0123456789abcdef");
	h.arg_len = ft_strlen(arg.str) + 2;
	h.s_printed = 0;
	h.width = f.width;
	h.prec = f.prec;
	*printed += ((f.prec != 0) ? h.arg_len : --h.arg_len);
	if (f.left_justify)
	    print(arg.str, &h.s_printed, f.prec);
	if (f.prec > f.width && f.prec > h.arg_len)
		print_byte(&h.s_printed);
	while (f.width > h.arg_len && f.width >= f.prec)
	{
		ft_putchar_fd(' ', 1);
		*printed += 1;
		f.width--;
	}
	while (f.prec > h.arg_len || f.prec > h.width + 1)
	{
		ft_putchar_fd('0', 1);
		*printed += 1;
		f.prec--;
	}
	if (!f.left_justify)
	    print(arg.str, &h.s_printed, f.prec);
}
