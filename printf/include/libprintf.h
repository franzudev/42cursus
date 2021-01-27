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

int				parse_format(const char *str, va_list *args, int *printed);
void			print_c(va_list args, t_flags f, int *printed);
void			print_s(va_list args, t_flags f, int *printed);
void			print_per(t_flags f, int *printed);
void			print_di(va_list args, t_flags f, int *printed);
void			print_u(va_list args, t_flags f, int *printed);
void			print_x(char str, va_list args, t_flags f, int *printed);
void			print_p(va_list args, t_flags f, int *printed);
int				ft_printf(const char* str, ...);

#endif
