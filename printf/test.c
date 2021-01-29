#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	// unsigned int n = 4294967295;
	// int m = -2147483648;
	// 	char *str = "%-10.% f %-*.3s\n";
//	 ft_printf("%-010% f %4.3s\n%p\nciao\n%-10c\n%-20.3di\n%020.3ii\n%020ui\n%030.4xi\n%50p\n",
	// 			"prova", &n,'Z', 2147483647, m, n, n, &n);
	// printf("hello, %-09s.\n", NULL);
//	ft_printf("%10.5i", -216);
//	ft_printf("%2p", NULL);
	ft_printf("%p\n", -2147483648);
	return 0;
}