/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:32 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:25 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	index = 0;
	if (!n)
		return (0);
	if (!(s1[index] || s2[index]))
		return (ft_memcmp(&s1[index], &s2[index], 1));
	while (s1[index] && s2[index] && index < n - 1)
	{
		if (ft_memcmp(&s1[index], &s2[index], 1) != 0)
			return (ft_memcmp(&s1[index], &s2[index], 1));
		index++;
	}
	return (ft_memcmp(&s1[index], &s2[index], 1));
}
