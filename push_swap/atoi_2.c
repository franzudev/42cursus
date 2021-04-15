#include "push_swap.h"

static	int	ft_isspace(char c)
{
	if (c == '\n' || c == '\r' || c == '\f' || c == '\t' || c == '\v'
		|| c == ' ')
		return (1);
	return (0);
}

static	int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static	int	is_char_int(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static	int	get_result(const char *str, long res, int s, t_data *data)
{
	while (is_char_int(*str))
	{
		res = res * 10 + (*str - '0');
		if (s == -1 && res > 2147483648)
			ft_exit("max/min integer", data);
		if (s == 1 && res > 2147483647)
			ft_exit("max/min integer", data);
		str++;
	}
	return ((int)(res * s));
}

int	ft_atoi_2(const char *str, t_data *data)
{
	int		s;
	int		f;
	long	res;

	s = 1;
	f = 0;
	res = 0;
	while (ft_isspace(*str))
		str++;
	while (is_sign(*str))
	{
		if (!f)
		{
			if (*(str++) == '-')
				s = -1;
			break ;
		}
		str++;
	}
	return (get_result(str, res, s, data));
}
