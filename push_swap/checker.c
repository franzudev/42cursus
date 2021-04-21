/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:50:04 by lincerpi          #+#    #+#             */
/*   Updated: 2021/04/21 15:50:06 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 1)
		exit(0);
	check_args(&data, argc, argv);
	while (get_next_line(&data.operation) > 0)
	{
		check_instruction(&data);
		exec_instruction(&data);
		free(data.operation);
	}
	free(data.operation);
	print_result(&data);
	return (0);
}
