/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:02:45 by franzu            #+#    #+#             */
/*   Updated: 2021/01/02 23:02:47 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t h;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i])
	{
		h = 0;
		while (haystack[i + h] == needle[h] && needle[h] && i + h < len)
			h++;
		if (!needle[h])
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
