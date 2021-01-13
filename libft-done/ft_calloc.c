/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:14:38 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/01/12 11:14:40 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*res;

	i = 0;
	res = (void *)malloc(size * count);
	if (!res)
		return (0);
	while (i < count * size)
		((unsigned char *)res)[i++] = 0;
	return (res);
}
