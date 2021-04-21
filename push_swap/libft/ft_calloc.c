/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:47:32 by lincerpi          #+#    #+#             */
/*   Updated: 2021/04/21 15:47:36 by lincerpi         ###   ########.fr       */
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
