/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:26:28 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/01/12 11:26:30 by ffrancoi         ###   ########.fr       */
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
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
