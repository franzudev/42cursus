/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 09:49:57 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/11/29 18:50:17 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int str_size;
	int counter;

	str_size = 1;
	counter = 0;
	while (str[counter])
	{
		write(1, &str[counter++], 1);
	}
}
