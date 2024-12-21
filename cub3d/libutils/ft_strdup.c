/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:31 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:25 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicated;
	size_t	lenght;

	lenght = ft_strlen(s1) + 1;
	duplicated = (char *)ft_calloc(lenght, sizeof(char));
	ft_strlcpy(duplicated, s1, lenght);
	return (duplicated);
}
