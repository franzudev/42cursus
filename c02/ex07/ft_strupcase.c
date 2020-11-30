/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:34:14 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/11/30 19:40:27 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strupcase(char *str)
{
	char *t;

	t = str;

	while (*t != '\0')
	{
		if (*t >= 'a' && *t <= 'z')
			*t -= 32; 
		write(1, t, 1);
		t++;
	}

	return (str);
}
