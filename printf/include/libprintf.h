#ifndef LIBPRINTF_H
# define LIBPRINTF_H

#include <stdarg.h>

int	arg_count(const char *str);

typedef struct	s_flags {
	int	left_justify;
	int	zero_pad;
	int	width;
	int precision;
}				t_flags;

#endif
