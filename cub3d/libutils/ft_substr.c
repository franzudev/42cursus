/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:32 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:26 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s)
		return (NULL);
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	sub = (char *)ft_calloc((len + 1), sizeof(char));
	if (!sub)
		return (0);
	if (start >= ft_strlen(s))
		return (sub);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
