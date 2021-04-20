#include "push_swap.h"

static void	check_sort(t_data *data)
{
	if (is_sorted_asc(data->stack_a, data->size_a))
	{
		write(1, "OK...gia sortata\n", 17);
		exit (0);
	}
}

static	void	generate_index_array(t_data *data, t_sort *sort)
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
	sort->stack_b = data->stack_b;
	sort->size_a = data->size_a;
	sort->size_b = data->size_b;
}

static int check_mediana(int *stack, int size)
{
	int i;
	int somma;
	int media;

	somma = 0;
	i = -1;
	while (++i < size)
		somma += stack[i];
	media = somma / size;
	return (media);	
}

static void phase_one(t_sort *sort)
{
	int mediana;
	int raffaello;

	raffaello = 0;

	while (!is_sorted_asc(sort->stack_a, sort->size_a))
	{
		mediana = check_mediana(sort->stack_a, sort->size_a);
		if (sort->stack_a[0] < mediana)
		{
			ft_push(sort->stack_b, sort->stack_a, &sort->size_b, &sort->size_a);
			write(1, "pb\n", 3);
		}
		else
		{
			ft_rotate(sort->stack_a, sort->size_a);
			write(1, "ra\n", 3);
		}
	}
}

static void phase_two(t_sort *sort)
{
	int mediana;

	while (!is_sorted_desc(sort->stack_b, sort->size_b))
	{
		mediana = check_mediana(sort->stack_b, sort->size_b);
		if (sort->stack_b[0] > mediana)
		{
			ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
			write(1, "pa\n", 3);
		}
		else
		{
			ft_rotate(sort->stack_b, sort->size_b);
			write(1, "rb\n", 3);
		}
	}
}
// static void	phase_three(t_sort *sort)
// {
// 	while (sort->size_b != 0)
// 	{
// 		ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
// 		write(1, "pa\n", 3);
// 	}
// }

 static void phase_four(t_sort *sort)
{
	int	count;
	int size;

	size = sort->size_a;
	count = 0;
	while (count < size)
	{
		if(sort->stack_a[0] + 1 == sort->stack_a[1])
		{
			ft_rotate(sort->stack_a, sort->size_a);
			write(1, "ra\n", 3);
			count++;
		}
		else
		{
			ft_rotate(sort->stack_a, sort->size_a);
			ft_push(sort->stack_b, sort->stack_a, &sort->size_b, &sort->size_a);
			write(1, "ra\n", 4);
			write(1, "pb\n", 3);
			count += 2;
		}
	}
}

// static void phase_five(t_sort *sort)
// {
// 	int count;
// 	int size;

// 	count = -1;
// 	ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
// 	write(1, "pa\n", 3);
// 	size = sort->size_a;
// 	while (++count < size)
// 	{
// 		if (sort->stack_b[0] < sort->stack_b[1])
// 			{
// 				ft_swap(sort->stack_b, sort->size_b);
// 				write(1, "sb\n", 3);
// 			}
// 		if (sort->stack_a[0] > sort->stack_a[1] && !(sort->stack_a[0] == sort->size_a + sort->size_b))
// 		{
// 			ft_swap(sort->stack_a, sort->size_a);
// 			if (sort->stack_b[0] < sort->stack_b[1])
// 			{
// 				ft_swap(sort->stack_b, sort->size_b);
// 				write(1, "ss\n", 3);
// 			}
// 			else
// 				write(1, "sa\n", 3);
// 		}
// 		ft_r_rotate(sort->stack_a, sort->size_a);
// 		write(1, "rra\n", 4);
// 		if (sort->stack_b[0] < sort->stack_a[0] && sort->stack_b[0] > sort->stack_a[sort->size_a - 1])
// 		{
// 			ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
// 			write(1, "pa\n", 3);
// 		}

// 	}

// }

// static void phase_six(t_sort *sort)
// {
// 	int count;
// 	int size;

// 	count = -1;
// 	size = sort->size_a;
// 	while (++count < size)
// 	{
// 		if (sort->stack_b[0] < sort->stack_b[1])
// 			{
// 				ft_swap(sort->stack_b, sort->size_b);
// 				write(1, "sb\n", 3);
// 			}
// 		if (sort->stack_a[0] > sort->stack_a[1] && !(sort->stack_a[0] == sort->size_a + sort->size_b))
// 		{
// 			ft_swap(sort->stack_a, sort->size_a);
// 			if (sort->stack_b[0] < sort->stack_b[1])
// 			{
// 				ft_swap(sort->stack_b, sort->size_b);
// 				write(1, "ss\n", 3);
// 			}
// 			else
// 				write(1, "sa\n", 3);
// 		}
// 		ft_r_rotate(sort->stack_a, sort->size_a);
// 		write(1, "rra\n", 4);
// 		if (sort->stack_b[0] < sort->stack_a[0] && sort->stack_b[0] > sort->stack_a[sort->size_a - 1])
// 		{
// 			ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
// 			write(1, "pa\n", 3);
// 		}

// 	}

//  }

//	scorri stack A
//			check se [0] > [1] senno swap
//			check se consegutivo se troppo distante(tipo 3) push in b
// 			senno scorri stack B (costo rrotate o rotate) 
// 			trova numero e push in a
static int ft_find_nb(int *stack, int size, int nb)
{
	int index;
	
	index = 0;
	while (stack[index] != nb)
		index++;
	if (index > size / 2)
		return (1);
	return (0);
}

static int ft_find_stack(int *stack, int size, int check)
{
	int index;

	index = 0;
	while (index < size)
	{
		if (stack[index] == check)
			return (1);
		index++;
	}
	return (0);
}

static void phase_seven(t_sort *sort)
{
	int check;
	int giri;

	ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
 	write(1, "pa\n", 3);
	check = 1;
	while(!is_sorted_asc(sort->stack_a, sort->size_a))
	{
		if (sort->stack_a[0] == check)
		{
			ft_rotate(sort->stack_a, sort->size_a);
			write(1, "ra\n", 3);
			check++;
		}
		else if (sort->stack_a[0] > sort->stack_a[1])
		{
			ft_swap(sort->stack_a, sort->size_a);
			if (sort->stack_b[0] < sort->stack_b[1])
			{
				ft_swap(sort->stack_b, sort->size_b);
				write(1, "ss\n", 3);
			}
			else
				write(1, "sa\n", 3);
		}
		else
		{
			if (ft_find_stack(sort->stack_a, sort->size_a, check))
			{
				giri = 0;
				while (sort->stack_a[0] != check)
				{
					ft_rotate(sort->stack_a, sort->size_a);
					write(1, "ra\n", 3);
					
					giri++;
				}
				ft_push(sort->stack_b, sort->stack_a, &sort->size_b, &sort->size_a);
				write(1, "pb\n", 3);
				while (giri > 0)
				{
					ft_r_rotate(sort->stack_a, sort->size_a);
					write(1, "rrb\n", 4);
					
					giri--;
				}
				ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
				write(1, "pa\n", 3);

			}
			else
			{
				if (ft_find_nb(sort->stack_b, sort->size_b, check))
				{
					while (sort->stack_b[0] != check)
					{
						ft_r_rotate(sort->stack_b, sort->size_b);
						write(1, "rrb\n", 4);
					}
					ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
					write(1, "pa\n", 3);
				}
				else
				{
					while (sort->stack_b[0] != check)
					{
						ft_rotate(sort->stack_b, sort->size_b);
						write(1, "rb\n", 3);
						
					}
					ft_push(sort->stack_a, sort->stack_b, &sort->size_a, &sort->size_b);
					write(1, "pa\n", 3);
				}
			}
		}
	}
}

void paperino(t_data *data)
{
	t_sort sort;
	int i ,y;
	i = y = 0;
	
	check_sort(data);
	generate_index_array(data, &sort);

	phase_one(&sort);
	// printf("--A--   --B--\n");
	// 	while (i < sort.size_a || y < sort.size_b)
	// 	{
	// 		if(i < sort.size_a && y < sort.size_b)
	// 			printf("%5d  %5d\n", sort.stack_a[i], sort.stack_b[y]);
	// 		else if (i < sort.size_a && y >= sort.size_b)
	// 			printf("%5d\n", sort.stack_a[i]);
	// 		else if (i >= sort.size_a && y < sort.size_b)
	// 			printf("       %5d\n", sort.stack_b[y]);
	// 		i++;
	// 		y++;
	// 	}

	phase_two(&sort);
	// i = y = 0;
	// printf("--A--   --B--\n");
	// 	while (i < sort.size_a || y < sort.size_b)
	// 	{
	// 		if(i < sort.size_a && y < sort.size_b)
	// 			printf("%5d  %5d\n", sort.stack_a[i], sort.stack_b[y]);
	// 		else if (i < sort.size_a && y >= sort.size_b)
	// 			printf("%5d\n", sort.stack_a[i]);
	// 		else if (i >= sort.size_a && y < sort.size_b)
	// 			printf("       %5d\n", sort.stack_b[y]);
	// 		i++;
	// 		y++;
	// 	}
	

	//phase_three(&sort);
	// i = y = 0;
	// printf("--A--   --B--\n");
	// 	while (i < sort.size_a || y < sort.size_b)
	// 	{
	// 		if(i < sort.size_a && y < sort.size_b)
	// 			printf("%5d  %5d\n", sort.stack_a[i], sort.stack_b[y]);
	// 		else if (i < sort.size_a && y >= sort.size_b)
	// 			printf("%5d\n", sort.stack_a[i]);
	// 		else if (i >= sort.size_a && y < sort.size_b)
	// 			printf("       %5d\n", sort.stack_b[y]);
	// 		i++;
	// 		y++;
	// 	}

	 phase_four(&sort);

	//  i = y = 0;
	// printf("--A--   --B--\n");
	// 	while (i < sort.size_a || y < sort.size_b)
	// 	{
	// 		if(i < sort.size_a && y < sort.size_b)
	// 			printf("%5d  %5d\n", sort.stack_a[i], sort.stack_b[y]);
	// 		else if (i < sort.size_a && y >= sort.size_b)
	// 			printf("%5d\n", sort.stack_a[i]);
	// 		else if (i >= sort.size_a && y < sort.size_b)
	// 			printf("       %5d\n", sort.stack_b[y]);
	// 		i++;
	// 		y++;
	// 	}

	 //phase_five(&sort);

	 //phase_six(&sort);

	phase_seven(&sort);

	i = y = 0;
	printf("--A--   --B--\n");
		while (i < sort.size_a || y < sort.size_b)
		{
			if(i < sort.size_a && y < sort.size_b)
				printf("%5d  %5d\n", sort.stack_a[i], sort.stack_b[y]);
			else if (i < sort.size_a && y >= sort.size_b)
				printf("%5d\n", sort.stack_a[i]);
			else if (i >= sort.size_a && y < sort.size_b)
				printf("       %5d\n", sort.stack_b[y]);
			i++;
			y++;
		}

}