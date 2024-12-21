/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:32 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:26 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	src_i;
	size_t	fnd_i;

	src_i = 0;
	fnd_i = 0;
	if (*needle == 0)
		return ((char *)str);
	while (str[src_i] && src_i < len)
	{
		fnd_i = 0;
		while (str[src_i + fnd_i] == needle[fnd_i] &&
			(src_i + fnd_i < len))
		{
			if (!needle[fnd_i + 1])
				return ((char *)&str[src_i]);
			fnd_i++;
		}
		src_i++;
	}
	return (0);
}
