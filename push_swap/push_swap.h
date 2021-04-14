#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# define ERR "Error\n"

# include "libft/libft.h"
# include <limits.h>

typedef struct s_data {
	int		*stack_a;
	int		size_a;
	int		*stack_b;
	int		size_b;
	char	operation[4];
}			t_data;

int	get_next_line(char **line);

#endif