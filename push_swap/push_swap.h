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
	char	*operation;
}			t_data;

int		ft_atoi_2(const char *str, t_data *data);
void	print_result(t_data *data);
void	ft_exit(char *str, t_data *data);
void	check_args(t_data *data, int argc, char**argv);
int		get_next_line(char **line);
int		check_instruction(t_data *data);
void	exec_instruction(t_data *data);
void	ft_push(int *stack_dest, int *stack_source, int *size_dest, int *size_source);
void	ft_swap(int *stack, int size);
void	ft_rotate(int *stack, int size);
void	r_rotate(int *stack, int size);

#endif