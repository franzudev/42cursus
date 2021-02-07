#ifndef LIBPRINTF_H
# define LIBPRINTF_H

#include <stdarg.h>

typedef struct	s_flags {
	int	left_justify;
	int	zero_pad;
	int	width;
	int prec;
}				t_flags;

typedef struct	s_helpers {
	int		arg_len;
	int		sign;
	int		s_printed;
	int		width;
	int		prec;
}				t_helpers;

typedef union 	u_arg {
	char			chr;
	char			*str;
	unsigned int 	udigit;
	long			ldigit;
	void            *pdigit;
}				t_arg;

int				parse_format(const char *str, va_list *args, int *printed);
void			print_c(va_list args, t_flags f, int *printed);
void			print_s(va_list args, t_flags f, int *printed);
void			print_per(t_flags f, int *printed);
void			print_diu(va_list args, t_flags f, int *printed, int unsignd);
void			print_x(char str, va_list args, t_flags f, int *printed);
void			print_p(va_list args, t_flags f, int *printed);
void			delptr(int alloc, char *str, int len);
int				ft_printf(const char* str, ...);

#endif
