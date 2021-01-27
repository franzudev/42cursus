#include "include/libprintf.h"
#include "libft/libft.h"

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
