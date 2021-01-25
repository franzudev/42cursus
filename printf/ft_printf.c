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
	return (1);
}

int main()
{
//	char *str = "%-10.% f %-*.3s\n";
	ft_printf("%-010% f %4.3s\nciao\n%-10c\n%d\n%i\n%u\n", "prova", 'Z',
	2147483647, -2147483648, 4147483649);
	printf("%-010% f %4.3s\nciao\n%-10c\n%d\n%i\n%u\n", "prova", 'Z',
		2147483647, -2147483647, 2147483647);
	return 0;
}