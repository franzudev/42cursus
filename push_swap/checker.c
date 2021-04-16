#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	int i;

	if (argc == 1)
		exit(0);
	check_args(&data, argc, argv);
	while (get_next_line(&data.operation) > 0)
	{
		check_instruction(&data);
		exec_instruction(&data);
		i = -1;
		while (++i < data.size_a)
			printf("A: %d\n", data.stack_a[i]);
		i = -1;
		while (++i < data.size_b)
			printf("B: %d\n", data.stack_b[i]);
		free(data.operation);
	}
	print_result(&data);
	free_pointer(&data);
	return (0);
}
