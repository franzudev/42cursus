/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:25:18 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/05 18:25:22 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_char_int(char str)
{
	if (str >= '0' && str <= '9')
	{
		return (1);
	}
	return (0);
}

int		is_upchar(char str)
{
	if (str >= 'A' && str <= 'Z')
	{
		return (1);
	}
	return (0);
}

int		is_char(char str)
{
	if (str >= 'a' && str <= 'z')
	{
		return (1);
	}
	return (0);
}

void	set_char_up(char *s, int i)
{
	if (!is_char(s[i - 1]) && !is_char_int(s[i - 1]) && !is_upchar(s[i - 1]))
	{
		if (is_char(s[i]))
		{
			s[i] -= 32;
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_upchar(str[i]))
		{
			str[i] += 32;
		}
		set_char_up(str, i);
		i++;
	}
	return (str);
}
