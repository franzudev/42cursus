#include "include/libprintf.h"
#include "libft/libft.h"
#include <stdio.h>

int ft_printf(const char* str, ...)
{
	int printed;
	int ret;

	printed = 0;
	ret = 0;
	va_list	args;
	if (!ft_strchr(str, '%')) {
		ft_putstr_fd((char *)str, 1);
		return ft_strlen(str);
	}
	va_start(args, str);
	while (*str){
		ret = parse_format(str, &args, &printed);
		if (ret == -1)
			return (-1);
		str += ret;
	}
	va_end(args);
	return (printed);
}

/* int main()
{
	unsigned int n = 4294967295;
	int m = -2147483648;
		char *str = "%-10.% f %-*.3s\n";
	ft_printf("%-010% f %05 %4.3s\n%p\nciao\n%-10c\n%-20.3di\n%020.3ii\n%020ui\n%030.4xi\n%50p\n",
				"prova", &n,'Z', 2147483647, m, n, n, &n);
		printf("hello, %s.\n", NULL);
		ft_printf("hello, %s.", NULL);
	return 0;
} */