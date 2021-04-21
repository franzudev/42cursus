/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <ffrancoi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:51:08 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/21 15:51:10 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	void	ft_swap_nums(int *a, int i, int j)
{
	int	temp;

	if (i < j)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

void	ft_quicksort(int *a, int first, int last)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (a[i] <= a[pivot] && i < last)
				i++;
			while (a[j] > a[pivot])
				j--;
			ft_swap_nums(a, i, j);
		}
		temp = a[pivot];
		a[pivot] = a[j];
		a[j] = temp;
		ft_quicksort(a, first, j - 1);
		ft_quicksort(a, j + 1, last);
	}
}
