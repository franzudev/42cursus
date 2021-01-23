/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:38:47 by franzu            #+#    #+#             */
/*   Updated: 2021/01/02 16:38:51 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*st1 = s1;
	const unsigned char	*st2 = s2;
	size_t				i;

	i = 0;
	while (st1[i] == st2[i] && i < n)
		i++;
	return (st1[i] - st2[i]);
}
