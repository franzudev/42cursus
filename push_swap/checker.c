#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	int i;
	int y;
	int z;

	if (argc == 1)
		exit(0);
	check_args(&data, argc, argv);
	z = 1;
	while (get_next_line(&data.operation) > 0)
	{
		check_instruction(&data);
		exec_instruction(&data);
		i = y = 0;
		printf("hai fatto ben %d mosse!kudos!\n", z);
		printf("--A--   --B--\n");
		while (i < data.size_a || y < data.size_b)
		{
			if(i < data.size_a && y < data.size_b)
				printf("%5d  %5d\n", data.stack_a[i], data.stack_b[y]);
			else if (i < data.size_a && y >= data.size_b)
				printf("%5d\n", data.stack_a[i]);
			else if (i >= data.size_a && y < data.size_b)
				printf("       %5d\n", data.stack_b[y]);
			i++;
			y++;
		}
		z++;
		free(data.operation);
	}
	print_result(&data);
	free_pointer(&data);
	return (0);
}
