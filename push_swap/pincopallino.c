#include "push_swap.h"

//check A is sorted
static void	check_sort(t_data *data)
{
	if (is_sorted_asc(data->stack_a, data->size_a))
	{
		write(1, "OK...gia sortata\n", 17);
		exit (0);
	}
}
//crea stack_ok 
static void	create_stack_sort(t_data *data, t_sort *sort)
{
	int i;

	sort->stack = (int*)malloc(sizeof(int) * data->size_a);
	i = -1;
	while (++i < data->size_a)
		sort->stack[i] = data->stack_a[i];
	ft_quicksort(sort->stack, 0, data->size_a - 1);
	sort->size = data->size_a;
}
//prendi mediana
static void	check_mediana(t_sort *sort)
{
	sort->index_mediana = sort->size / 2;
	sort->mediana = sort->stack[sort->index_mediana];
}
//ordina due stack....	stackA numeri maggiori di mediana		ordinamento CRESCENTE
//						stackB numeri minori di mediana			ordinamento DECRECENTE 
//fase1 dividi stack ... check se ss e pb se minore mediana (pb x volte size/2) ad ogni pb check se stack a e stack b ordinato
//	stampa mosse	
static int		check_ss(t_data *data)
{
	if ((data->size_b > 1) && (data->stack_a[0] > data->stack_a[1]) && (data->stack_b[0] < data->stack_b[1]))
		return (1);
	return (0);
}
static void	phase_one(t_data *data, t_sort *sort)
{
	int num_pb;

	num_pb = 0;
	while (num_pb < sort->index_mediana && !(is_sorted_asc(data->stack_a, data->size_a) && is_sorted_desc(data->stack_b, data->size_b)))  
	{
		if (check_ss(data)) // puoi inserire in check_ss
		{
			ft_swap(data->stack_a, data->size_a);
			ft_swap(data->stack_b, data->size_b);
			write(1, "ss\n", 3);
		}
		else if (data->stack_a[0] < sort->mediana) // prova anche a levare else
		{
			ft_push(data->stack_b, data->stack_a, &data->size_b, &data->size_a);
			write(1, "pb\n", 3);
			num_pb++;
		}
		else
		{
			ft_rotate(data->stack_a, data->size_a);
			write(1, "ra\n", 3);
		}
	}
}
//fase2 ordina stack (proviamo con A poi al max implementimao doppio ordinamento e selezioniamo quello con mosse <)
//		check ordinato stacks
// se trova numero minore cambia direzione !!! ra fino al MAX rra fino al min
// stampa mosse
static void	phase_two(t_data *data, t_sort *sort)
{
	int raffaello;

	raffaello = 0;

	while (!is_sorted_asc(data->stack_a, data->size_a))
	{
		//printf("stack_a[0]%d\n stack_a[1]%d\n mediana%d\n", data->stack_a[0], data->stack_a[1],sort->mediana);
		if (data->stack_a[0] > data->stack_a[1]) 
		{
			if (data->stack_a[0] == sort->stack[sort->size - 1])
				raffaello = 1;
			if (data->stack_a[0] == sort->mediana)
				raffaello = 0;
			ft_swap(data->stack_a, data->size_a);
			if (data->stack_b[0] < data->stack_b[1])
			{
				ft_swap(data->stack_b, data->size_b);
				write(1, "ss\n", 3);
			}
			else
				write(1, "sa\n", 3);
		}
		else
		{	//grazie raffaello!! aggiungere anche a fase3!!
			if (data->stack_a[0] == sort->stack[sort->size - 1])
				raffaello = 1;
			if (data->stack_a[0] == sort->mediana)
				raffaello = 0;
		
			if (raffaello == 0)
			{
				ft_rotate(data->stack_a, data->size_a);
				if (!is_sorted_desc(data->stack_b, data->size_b))
				{
					ft_rotate(data->stack_b, data->size_b);
					write(1, "rr\n", 3);
				}
				else
					write(1, "ra\n", 3);
			}
			if (raffaello == 1)
			{
				ft_r_rotate(data->stack_a, data->size_a);
				if (!is_sorted_desc(data->stack_b, data->size_b))
				{
					ft_r_rotate(data->stack_b, data->size_b);
					write(1, "rrr\n", 4);
				}
				else
					write(1, "rra\n", 4);
			}
		}
	}
}
//fase3 ordina seconda stack
static void	phase_three(t_data *data, t_sort *sort)
{
	int michelangelo;

	michelangelo = 0;
	while (!is_sorted_desc(data->stack_b, data->size_b))
	{
		//printf("stack_b[0]%d\n stack_b[1]%d\n mediana%d\n", data->stack_b[0], data->stack_b[1],sort->stack[sort->index_mediana - 1]);
		if (data->stack_b[0] < data->stack_b[1])
		{
			if (data->stack_b[0] == sort->stack[0])
				michelangelo = 1;
			if (data->stack_b[0] == sort->stack[sort->index_mediana - 1])
					michelangelo = 0;
			ft_swap(data->stack_b, data->size_b);
			write(1, "sb\n", 3);
		}
		else
		{
			if (data->stack_b[0] == sort->stack[0])
				michelangelo = 1;
			if (data->stack_b[0] == sort->stack[sort->index_mediana - 1])
					michelangelo = 0;
			if (michelangelo == 0)
			{
				ft_rotate(data->stack_b, data->size_b);
				write(1, "rb\n", 3);
			}
			if (michelangelo == 1)
			{
				ft_r_rotate(data->stack_b, data->size_b);
				write(1, "rrb\n", 4);
			}
		}
	}
}
//fase4 pa
static void	phase_four(t_data *data)
{
	while(data->size_b)
	{
		ft_push(data->stack_a, data->stack_b, &data->size_a, &data->size_b);
		write(1, "pa\n", 3);
	}
}
//stampa mosse sempre!
void	pincopallino(t_data *data)
{
	t_sort	sort;

	check_sort(data);
	create_stack_sort(data, &sort);
	check_mediana(&sort);
	phase_one(data, &sort);
	phase_two(data, &sort);
	phase_three(data, &sort);
	phase_four(data);
}