#include "push_swap.h"

int	ft_find_nb(int *stack, int size, int nb)
{
	int	index;

	index = 0;
	while (stack[index] != nb)
		index++;
	if (index > size / 2)
		return (1);
	return (0);
}

int	ft_find_stack(int *stack, int size, int check)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (stack[index] == check)
			return (1);
		index++;
	}
	return (0);
}

void	generate_index_array(t_data *data, t_sort *sort)
{
	int	*copy;
	int	i;
	int	j;

	i = 0;
	copy = (int *)malloc(sizeof(int) * data->size_a);
	sort->stack_a = (int *)malloc(sizeof(int) * data->size_a);
	if (!copy || !sort->stack_a)
		exit(1);
	copy = ft_memmove(copy, data->stack_a, sizeof(int) * data->size_a);
	ft_quicksort(copy, 0, data->size_a - 1);
	while (i < data->size_a)
	{
		j = 0;
		while (data->stack_a[i] != copy[j] && j < data->size_a)
			j++;
		sort->stack_a[i] = j + 1;
		i++;
	}
	free(copy);
	sort->stack_b = (int *)malloc(sizeof(int) * data->size_a);
	sort->size_a = data->size_a;
	sort->size_b = 0;
}

int	check_mediana(int *stack, int size)
{
	int	i;
	int	somma;
	int	media;

	somma = 0;
	i = -1;
	while (++i < size)
		somma += stack[i];
	media = somma / size;
	return (media);
}
