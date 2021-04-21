/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:49:51 by lincerpi          #+#    #+#             */
/*   Updated: 2021/04/21 15:49:56 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicate(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->size_a)
	{
		j = -1;
		while (++j < i)
		{
			if (data->stack_a[i] == data->stack_a[j])
				ft_exit(ERR, data);
		}
	}
}

static void	check_number(char *number, t_data *data)
{
	int	i;

	i = -1;
	while (number[++i])
	{
		if (!((number[i] >= 48 && number[i] <= 57) || \
			number[i] == 45 || number[i] == 43))
			ft_exit(ERR, data);
	}
}

static void	fill_stack_a(t_data *data, char **str, int i)
{
	int	nb;

	if (i == -1)
	{
		while (++i < data->size_a)
		{
			check_number(str[i], data);
			nb = ft_atoi_2(str[i], data);
			data->stack_a[i] = nb;
			free(str[i]);
			str[i] = NULL;
		}
		free(str);
	}
	else
	{
		while (++i <= data->size_a)
		{
			check_number(str[i], data);
			nb = ft_atoi_2(str[i], data);
			data->stack_a[i - 1] = nb;
		}
	}
	check_duplicate(data);
}

static char	**check_size(int argc, char **argv, t_data *data)
{
	char	**shit;
	int		i;

	if (argc == 2)
	{
		shit = ft_split(argv[1], ' ');
		i = 0;
		while (shit[i])
			i++;
		data->size_a = i;
		return (shit);
	}
	else
		data->size_a = argc - 1;
	return (NULL);
}

void	check_args(t_data *data, int argc, char **argv)
{
	char	**shit;

	shit = check_size(argc, argv, data);
	data->size_b = 0;
	data->stack_a = (int *)malloc(sizeof(int) * data->size_a);
	data->stack_b = (int *)malloc(sizeof(int) * data->size_a);
	if (!data->stack_a || !data->stack_b)
		ft_exit(ERR, data);
	if (argc == 2)
		fill_stack_a(data, shit, -1);
	else
		fill_stack_a(data, argv, 0);
}
