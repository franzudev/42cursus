#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 1)
		exit(0);
	if (!argv[0])
		exit(0);
	// check_args(&data, argc, argv);
	while (get_next_line((char **)&(data.operation)) > 0)
	{
		printf("%s|\n", data.operation);
		printf("%d\n", check_instruction(data.operation));
			// exec_instruction(&data);
	}
	// print_result(&data);
	return (0);
}
