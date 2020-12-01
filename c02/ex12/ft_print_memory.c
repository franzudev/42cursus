/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:10:43 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/01 14:43:34 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_print_hexa(char np)
{
    char    *hex;

    hex = "0123456789abcdef";
    if (np > 16)
    {
        ft_print_hexa(np / 10);
        ft_print_hexa(np % 10);
    }
    else
        print(hex[(int)np]);
}

void *ft_print_memory(void *addr, unsigned int size)
{
	int counter;

	counter = 0;
	if (!size)
		return;
	while(addr[counter])
	{

	}
}
