/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:31 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:24 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	t_uc	*from;
	t_uc	*to;
	int		crement;
	size_t	index;

	to = (t_uc*)dst;
	from = (t_uc*)src;
	if (from == NULL && to == NULL)
		return (NULL);
	if (to > from)
	{
		index = len - 1;
		crement = -1;
	}
	else
	{
		index = 0;
		crement = 1;
	}
	while (index >= 0 && index < len)
	{
		to[index] = from[index];
		index += crement;
	}
	return (dst);
}
