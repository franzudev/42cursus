#include "push_swap.h"

void quicksort(int *a, int primo, int ultimo)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	if (primo < ultimo)
	{
		pivot = primo;
		i = primo;
		j = ultimo;
		while (i < j)
		{
			while (a[i] <= a[pivot] && i < ultimo)
				i++;
			while (a[j] > a[pivot])
				j--;
			if (i<j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = a[pivot];
		a[pivot] = a[j];
		a[j] = temp;
		quicksort(a, primo, j - 1);
		quicksort(a, j + 1, ultimo);
	}
}

void	calculate_moves(t_data *data)
{
	int i;

	printf("size args: %d\n", data->size_a);
	i = -1;
	while (++i < data->size_a)
		printf("A: %d\n", data->stack_a[i]);
	quicksort(data->stack_a, 0, data->size_a - 1);
	printf("###################\n#####################\n##################\n");
	i = -1;
	while (++i < data->size_a)
		printf("A: %d\n", data->stack_a[i]);

}