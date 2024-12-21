/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <ffrancoi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:50:55 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/21 15:50:56 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 1)
		exit(0);
	check_args(&data, argc, argv);
	if (data.size_a > 50)
		paperino(&data);
	else
	{
		if (data.size_a == 3)
			topolino(&data);
		else
			pincopallino(&data);
	}
	free_pointer(data.stack_a);
	free_pointer(data.stack_b);
	return (0);
}
