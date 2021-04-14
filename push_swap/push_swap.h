#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct s_data {
	int		*stack_a;
	int		size_a;
	int		*stack_b;
	int		size_b;
	char	operation[4];
}			t_data;

#define ERR "Error\n"

#endif