/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:30:48 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/02 17:35:08 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char str)
{
	if (str == '\t' || str == '\n' || str == '\v' ||
		str == '\f' || str == '\r' || str == ' ')
	{
		return (1);
	}
	return (0);
}

int	is_char_int(char str)
{
	if (str >= '0' && str <= '9')
	{
		return (1);
	}
	return (0);
}

int	is_char(char str)
{
	if (str >= 'A' && str <= 'Z')
	{
		return (1);
	}
	if (str >= 'a' && str <= 'z')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int negative;
	int res;

	res = 0;
	negative = 1;
	while (*str && ft_isspace(*str))
	{
		str++;
	}
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
		{
			negative *= -1;
		}
		str++;
	}
	while (*str && is_char_int(*str))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * negative);
}
