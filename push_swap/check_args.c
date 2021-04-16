#include "push_swap.h"

static void	check_duplicate(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->size_a)
	{
		j = -1;
		while (++j < i)
		{
			if (data->stack_a[i] == data->stack_a[j])
				ft_exit("doppione", data);
		}
	}
}

static void	check_number(char *number, t_data *data)
{
	int	i;

	i = -1;
	while (number[++i])
	{
		if (!((number[i] >= 48 && number[i] <= 57) || \
			number[i] == 45 || number[i] == 43))
			ft_exit("non intero", data);
	}
}

static void	fill_stack_a(t_data *data, char **shit)
{
	int	i;
	int	nb;

	i = -1;
	while (++i <= data->size_a)
	{
		check_number(shit[i], data);
		nb = ft_atoi_2(shit[i], data);
		data->stack_a[i - 1] = nb;
	}
	check_duplicate(data);
}

static char **check_string(t_data *data, int argc, char **argv)
{
	char **shit;
	int i;

	if (argc == 2)
	{
		shit = ft_split(argv[1], ' ');
		i = 0;
		while(**shit)
			i++;
		data->size_a = i;
	}
	else
	{
		i = 1;
		while (*argv[i])
		{
			*shit[i - 1] = *argv[i];
			i++;
		}
			data->size_a = argc - 1;
	}
	return (shit);
}

void	check_args(t_data *data, int argc, char **argv)
{
	char **shit;

	shit = check_string(data, argc, argv);
	//data->size_a = argc - 1;
	data->size_b = 0;
	data->stack_a = (int *)malloc(sizeof(int) * data->size_a);
	data->stack_b = (int *)malloc(sizeof(int) * data->size_a);
	if (!data->stack_a || !data->stack_b)
		ft_exit(ERR, data);
	fill_stack_a(data, shit);
}
