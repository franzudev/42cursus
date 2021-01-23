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
	char	chr;
	char	*str;
	int		digit;
}				t_arg;

t_flags	init_flag(void);
int		parse_flag(const char *str, va_list *args, t_flags *flags);
int		parse_format(const char *str, va_list *args);
int		print_parameter(const char *str, va_list *args);
void	print_conversion(char str, va_list args, t_flags flags);


#endif
