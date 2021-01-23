#include "include/libprintf.h"
#include "libft/libft.h"
#include "helpers.c"
#include <stdio.h>

int ft_printf(const char* str, ...)
{
	va_list	args;
	void	*arg;
	int args_count = arg_count(str);
	if (ft_strchr(str, '%'))
	{
		ft_putstr(str);
		return (0);
	}
	va_start(args, str);
	while (*str)
	{
		if (*str == 's')
		{
			arg = (char *)va_arg(args, char *);
			printf("%s", arg);
		}
		str++;
	}
	va_end(args);
	return 1;
}

int main()
{
	char *str = "pd";
	ft_printf("s", str);
	return 0;
}