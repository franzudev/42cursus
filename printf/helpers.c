#include "include/libprintf.h"
#include "include/libft.h"

static void		ft_putstr(const char *str)
{
	while(*str)
		write(1, &(*(str++)), 1);
}

static int	in_str(char *str, char s)
{
	char *res;

	res = ft_strchr(str, s);
	if (!res)
		return 0;
	return 1;
}

int			arg_count(const char *str)
{
	int args = 0;
	int i = 0;

	while (*str)
	{
		if (ft_strchr(str, '%'))
		{
			str++;
			if (in_str("cspdiuxX%", *str))
			{
				i++;
				continue ;
			}
			else
			{
				find_flags("-0.*", *str);
				while(has_flags("-0.*", *str))
				{
				}
			}
		}
	}
	return args;
}