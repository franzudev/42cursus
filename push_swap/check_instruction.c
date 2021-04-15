#include "push_swap.h"

static int	is_valid_instruction(char *str)
{
	if (!str && !*str)
		return (0);
	if (ft_strcmp(str, "sa") == 0
		|| ft_strcmp(str, "sb") == 0
		|| ft_strcmp(str, "ss") == 0
		|| ft_strcmp(str, "pa") == 0
		|| ft_strcmp(str, "pb") == 0
		|| ft_strcmp(str, "ra") == 0
		|| ft_strcmp(str, "rb") == 0
		|| ft_strcmp(str, "rr") == 0
		|| ft_strcmp(str, "rra") == 0
		|| ft_strcmp(str, "rrb") == 0
		|| ft_strcmp(str, "rrr") == 0)
		return (1);
	return (0);
}

int	check_instruction(t_data *data)
{
	if (!is_valid_instruction(data->operation))
		ft_exit(ERR, data);
	return (1);
}
