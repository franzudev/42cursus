#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 1)
		exit(0);
	check_args(&data, argc, argv);
	if (data.size_a > 99)
		paperino(&data);
	else
		pincopallino(&data);
	free_pointer(data.stack_a);
	free_pointer(data.stack_b);
	return (0);
}
