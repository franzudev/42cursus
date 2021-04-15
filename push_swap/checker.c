#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 1)
		exit(0);

	check_args(&data, argc, argv);
	while (get_next_line(&data.operation) > 0)
	{
		check_instruction(&data);
		exec_instruction(&data);
	}
	print_result(&data);
	return (0);
}
