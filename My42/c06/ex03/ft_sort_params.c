/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:29:20 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 10:29:22 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap_argv(char *argv[], int a, int b, int size)
{
	char *temp;

	temp = argv[a];
	if (b < size)
	{
		if (ft_strcmp(argv[a], argv[b]) > 0)
		{
			argv[a] = argv[b];
			argv[b] = temp;
			ft_swap_argv(argv, 1, 2, size);
		}
		ft_swap_argv(argv, ++a, ++b, size);
	}
}

void	ft_sort_argv(char *tab[], int size)
{
	ft_swap_argv(tab, 1, 2, size);
}

int		main(int argc, char *argv[])
{
	int i;
	int g;

	i = 1;
	g = 0;
	ft_sort_argv(argv, argc);
	while (i < argc)
	{
		while (argv[i][g] != '\0')
			write(1, &argv[i][g++], 1);
		write(1, "\n", 1);
		g = 0;
		i++;
	}
}
