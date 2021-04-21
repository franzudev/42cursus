/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:51:01 by lincerpi          #+#    #+#             */
/*   Updated: 2021/04/21 15:51:04 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_sort {
	int		*stack_a;
	int		*stack;
	int		*stack_b;
	int		size;
	int		size_a;
	int		size_b;
	int		index_mediana;
	int		mediana;
}			t_sort;

int		ft_atoi_2(const char *str, t_data *data);
void	print_result(t_data *data);
void	free_pointer(void *pointer);
void	ft_exit(char *str, t_data *data);
void	check_args(t_data *data, int argc, char**argv);
int		get_next_line(char **line);
int		check_instruction(t_data *data);
void	exec_instruction(t_data *data);
void	ft_push(int *dest, int *source, int *size_dest, int *size_source);
void	ft_swap(int *stack, int size);
void	ft_rotate(int *stack, int size);
void	ft_r_rotate(int *stack, int size);
int		is_sorted_asc(const int *stack, int size);
int		is_sorted_desc(const int *stack, int size);
void	ft_quicksort(int *a, int first, int last);
void	sort_array(t_data *data);
int		is_srp(int *stack, int index, int size);
int		is_sp(int *stack, int index, int size);
int		is_rp(int *stack, int index, int size);
int		is_swappable(int *stack, int index, int size);
int		is_rotatable(int *stack, int index, int size);
int		is_rev_rotatable(int *stack, int index, int size);
int		is_pushable(int *stack, int index, int size);
int		ft_find_nb(int *stack, int size, int nb);
int		ft_find_stack(int *stack, int size, int check);
void	generate_index_array(t_data *data, t_sort *sort);
int		check_mediana(int *stack, int size);
void	phase_seven_three(t_sort *sort, int check);
void	ft_print_and_inc(char *move, int *inc);
void	pincopallino(t_data *data);
void	phase_magic(t_data *data, t_sort *sort);
void	paperino(t_data *data);
void	phase_four_plus(t_sort *sort);
void	phase_seven_plus(t_sort *sort);
void	topolino(t_data *data);

#endif