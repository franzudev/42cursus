#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 1)
		exit(0);
	check_args(&data, argc, argv);
	sort_array(&data);
	free_pointer(data.stack_a);
	free_pointer(data.stack_b);
	return (0);
}
