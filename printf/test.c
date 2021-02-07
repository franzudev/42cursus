#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>


int main()
{
	ft_printf(" %*.s %.1s ", 10, "123", "4567");
//	ft_printf("%2.9p\n", 1234);
//	ft_printf("%.5p\n", 0);
//	printf("%2.9p\n", 1234);
//	printf("%.5p", 0);
	return 0;
}