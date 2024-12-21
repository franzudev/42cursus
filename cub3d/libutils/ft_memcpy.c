/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:31 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:23 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_uc *from;
	t_uc *to;

	from = (t_uc*)src;
	to = (t_uc*)dst;
	if (from == NULL && to == NULL)
		return (NULL);
	while (n-- > 0)
		*to++ = *from++;
	return (dst);
}
