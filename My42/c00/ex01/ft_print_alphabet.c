/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:42:26 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/11/26 14:03:49 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** unistd.h needed to use the write() function
*/

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char ch;

	ch = 'a';
	while (ch <= 'z')
	{
		write(1, &ch, 1);
		ch++;
	}
}
