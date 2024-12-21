/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:15:51 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/01/12 11:15:53 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (((const unsigned char *)s1)[i] == ((const unsigned char *)s2)[i]
	&& i < n - 1)
		i++;
	return (((const unsigned char *)s1)[i] - ((const unsigned char *)s2)[i]);
}
