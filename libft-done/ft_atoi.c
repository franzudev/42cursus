/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:14:15 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/01/12 11:14:22 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int			ft_atoi(const char *str)
{
	int s;
	int f;
	int res;

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
	while (is_char_int(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * s);
}
