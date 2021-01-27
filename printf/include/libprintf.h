#ifndef LIBPRINTF_H
# define LIBPRINTF_H

#include <stdarg.h>

typedef struct	s_flags {
	int	left_justify;
	int	zero_pad;
	int	width;
	int precision;
}				t_flags;

typedef union 	u_arg {
	char			chr;
	char			*str;
	int				digit;
	unsigned int 	udigit;
}				t_arg;

int		parse_format(const char *str, va_list *args, int *printed);
int				ft_printf(const char* str, ...);

#endif
