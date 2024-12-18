/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:19:58 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/01 10:23:18 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char *t;

	t = str;
	while (*t != '\0')
	{
		if (*t >= 'A' && *t <= 'Z')
			*t += 32;
		t++;
	}
	return (str);
}