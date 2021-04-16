#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 1)
		exit(0);
	check_args(&data, argc, argv);
	calculate_moves(&data);
	free_pointer(&data);
	return (0);
}
