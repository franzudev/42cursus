#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# define ERR "Error\n"

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_data {
	int		*stack_a;
	int		size_a;
	int		*stack_b;
	int		size_b;
	char	operation[4];
}			t_data;

int		ft_atoi_2(const char *str, t_data *data);
void	print_result(t_data *data);
void	ft_exit(char *str, t_data *data);
void	check_args(t_data *data, int argc, char**argv);
void	push(int **stack_dest, int **stack_source, int size_dest, int size_source);
void	r_rotate_a(t_data *data);
void	r_rotate_b(t_data *data);
void	r_rotate_r(t_data *data);
int		get_next_line(char **line);
int	check_instruction(char *instruction);

#endif