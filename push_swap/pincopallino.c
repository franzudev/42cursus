#include "push_swap.h"

static void	create_stack_sort(t_data *data, t_sort *sort)
{
	int	i;

	sort->stack = (int *)malloc(sizeof(int) * data->size_a);
	i = -1;
	while (++i < data->size_a)
		sort->stack[i] = data->stack_a[i];
	ft_quicksort(sort->stack, 0, data->size_a - 1);
	sort->size = data->size_a;
}

static int	check_verse(t_data *data, t_sort *sort)
{
	int	count;
	int	pushare;

	pushare = 0;
	count = -1;
	while (++count < data->size_a && pushare < sort->index_mediana)
	{
		if (data->stack_a[count] < sort->mediana)
			pushare++;
	}
	if (pushare < sort->index_mediana)
		return (1);
	return (0);
}

static void	phase_one_plus(t_data *data, t_sort *sort)
{
	if (check_verse(data, sort))
	{
		ft_r_rotate(data->stack_a, data->size_a);
		write(1, "rra\n", 4);
	}
	else
	{
		ft_rotate(data->stack_a, data->size_a);
		write(1, "ra\n", 3);
	}
}

static void	phase_one(t_data *data, t_sort *sort)
{
	int	num_pb;

	num_pb = 0;
	while (num_pb < sort->index_mediana \
		&& !(is_sorted_asc(data->stack_a, data->size_a) \
		&& is_sorted_desc(data->stack_b, data->size_b)))
	{
		if (data->stack_a[0] < sort->mediana)
		{
			ft_push(data->stack_b, data->stack_a, &data->size_b, &data->size_a);
			write(1, "pb\n", 3);
			num_pb++;
		}
		else
			phase_one_plus(data, sort);
	}
}

void	pincopallino(t_data *data)
{
	t_sort	sort;

	if (is_sorted_asc(data->stack_a, data->size_a))
		exit (0);
	create_stack_sort(data, &sort);
	sort.index_mediana = sort.size / 2;
	sort.mediana = sort.stack[sort.index_mediana];
	phase_one(data, &sort);
	phase_magic(data, &sort);
	free(sort.stack);
}
