#include "include/ft_printf.h"
#include "include/libft.h"

static void print(char *str, int precision)
{
        ft_putstr_fd("0x", 1);
        if (precision != 0)
            ft_putstr_fd(str, 1);
}

void	print_p(va_list args, t_flags f, int *printed)
{
	t_arg	arg;
	int	arg_len;

	arg.pdigit = va_arg(args, void *);
    arg.str = ft_itoa_base((long)arg.pdigit, "0123456789abcdef");
	arg_len = ft_strlen(arg.str) + 2;
	*printed += ((f.prec != 0) ? arg_len : --arg_len);
	if (f.left_justify)
	    print(arg.str, f.prec);
	if (f.width && f.width - arg_len > 0)
	{
        while (f.width - arg_len && f.width >= f.prec)
        {
            ft_putchar_fd(' ', 1);
            *printed += 1;
            f.width--;
        }
        while (f.prec - arg_len - 2 >= 0)
        {
            ft_putchar_fd('0', 1);
            *printed += 1;
            f.prec--;
        }
    }
	if (!f.left_justify)
	    print(arg.str, f.prec);
}
