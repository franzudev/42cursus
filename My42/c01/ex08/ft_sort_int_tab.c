/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:02:45 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/11/29 19:13:03 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_array(int *arr, int a, int b, int size)
{
	int temp;

	if (b < size)
	{
		if (arr[a] > arr[b])
		{
			temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
			ft_swap_array(arr, 0, 1, size);
		}
		ft_swap_array(arr, ++a, ++b, size);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_swap_array(tab, 0, 1, size);
}
