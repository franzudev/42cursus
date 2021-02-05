#include "include/ft_printf.h"
#include "include/libft.h"

/*void    delptr(char *str)
{
    free(str);
    str = NULL;
}*/

void	print_s(va_list args, t_flags f, int *printed)
{
	t_arg	arg;
	int		arg_len;
//	int     alloc;

	arg.digit = 0;
	arg.str = va_arg(args, char *);
	if (!arg.str)
        arg.str = "(null)\0";
	else if (*arg.str == '\0' && f.precision != -1 && !f.width)
	    return ;
	/*else if ((*arg.str == '\0' && f.precision == 0 ))
	{
	    *printed = -1;
        return;
    }*/
	if (f.precision > -1)
        arg.str = ft_substr(arg.str, 0, f.precision);
//	{
//        alloc = 1;
//    }
	arg_len = ft_strlen(arg.str);
	*printed += arg_len;
	if (f.left_justify && arg.str)
		ft_putstr_fd(arg.str, 1);
	if ((f.width && f.width - arg_len > 0) || (f.precision && f.precision - arg_len > 0))
	    while (f.width - arg_len > 0)
		{
			ft_putchar_fd(f.zero_pad && !f.left_justify ? '0' : ' ', 1);
			*printed += 1;
			f.width--;
		}
	if (!(f.left_justify) && arg_len)
		ft_putstr_fd(arg.str, 1);
//	if (alloc)
//	{
//	    ft_memset(arg.str, '\0', arg_len);
//        delptr(arg.str);
//    }
}