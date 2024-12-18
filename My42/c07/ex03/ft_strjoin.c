/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:34:24 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/10 09:35:01 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		separator_length(char *sep)
{
	int len;

	len = 0;
	while (sep[len])
		len++;
	return (len);
}

int		string_length(char **strs, char *sep, int size)
{
	int i;
	int j;
	int len;

	if (size == 0)
		return (0);
	i = 0;
	j = 0;
	len = 0;
	while (i < size)
	{
		while (strs[i][j++])
			len++;
		j = 0;
		i++;
	}
	len += (separator_length(sep) * (size - 1));
	len += 1;

	return (len);
}

char	*result(char *res, int len)
{
	res[len] = '\0';
	return (res);
}

char *empty_string(char *res)
{
	res = (char*)malloc(sizeof(char));
	res[0] = '\0';
	return res;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		g;
	int		len;
	int		sep_len;
	char	*res;

	len = string_length(strs, sep, size);
	if (!len)
		return empty_string(res);
	res = (char*)malloc(len * sizeof(char) + 1);
	i = 0;
	g = 0;
	len = 0;
	sep_len = 0;
	while (i < size)
	{
		while (strs[i][g])
			res[len++] = strs[i][g++];
		while (sep[sep_len] && i < size - 1)
			res[len++] = sep[sep_len++];
		g = 0;
		sep_len = 0;
		i++;
	}
	return (result(res, len));
}

int main ()
{
	char **strs;
	char *sep;

	strs = (char **)malloc(sizeof(char*) * 5);
	sep = ">";
	strs[0] = "Voglio";
	strs[1] = "asd";
	strs[2] = "al";
	strs[3] = "mare";
	strs[4] = "!";

	printf("%s", ft_strjoin(5, strs, sep));
	return (0);
}
