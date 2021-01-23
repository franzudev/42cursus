#include "include/libprintf.h"
#include "libft/libft.h"
#include <stdio.h>

int ft_printf(const char* str, ...)
{
	va_list	args;
	if (!ft_strchr(str, '%')) {
		ft_putstr_fd((char *)str, 1);
		return (0);
	}
	va_start(args, str);
	while (*str)
	    str += parse_format(str, &args);
	va_end(args);
	return 1;
}

int main()
{
	char *str = "porco dio";
	ft_printf("%c f\n", *str);
	return 0;
}