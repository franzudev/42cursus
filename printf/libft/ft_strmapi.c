/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 01:22:58 by franzu            #+#    #+#             */
/*   Updated: 2021/01/03 01:22:59 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*res;

	len = ft_strlen(s);
	i = 0;
	res = (char *)malloc(sizeof(char) * len);
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = f(s[i], s[i]);
		i++;
	}
	return (res);
}
