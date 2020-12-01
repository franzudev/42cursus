/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:29:19 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/01 11:29:24 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_char(char str)
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

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && is_char(str[i]))
		{
			str[i] -= 32;
			i++;
			continue;
		}
		if (!is_char(str[i]))
		{
			if (is_char(str[i + 1]))
			{
				str[i + 1] -= 32;
			}
		}
		i++;
	}
	return (str);
}
