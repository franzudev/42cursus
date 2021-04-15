#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	data;
	int i;

	if (argc == 1)
		exit(0);
	check_args(&data, argc, argv);
	//while (get_next_line((char **)&data.operation) > 0)
	//{
		// check_instruction(data.operation);
		// exec_instruction(&data);
	//}
	printf("%d\n", data.size_b);
	ft_push(data.stack_b, data.stack_a, &data.size_b, &data.size_a);
	ft_push(data.stack_b, data.stack_a, &data.size_b, &data.size_a);
	i = 0;
	while (i < data.size_a)
	{
		printf("A:%d\n", data.stack_a[i]);
		i++;
	}
	i = 0;
	printf("%d\n", data.size_b);
	while (i < data.size_b)
	{
		printf("B:%d\n", data.stack_b[i]);
		i++;
	}
	print_result(&data);
	return (0);
}
