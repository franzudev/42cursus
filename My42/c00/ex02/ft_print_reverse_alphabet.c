/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:51:50 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/11/26 14:10:59 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 **	unistd.h needed to use the write() function
*/

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char ch;

	ch = 'z';
	while (ch >= 'a')
	{
		write(1, &ch, 1);
		ch--;
	}
}
