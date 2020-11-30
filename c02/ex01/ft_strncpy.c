/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:59:57 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/11/30 16:19:28 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int counter;
	unsigned int src_counter;

	counter = 0;
	src_counter = 0;
	while (src[src_counter++] != '\0');
	src_counter -= 1;

	while(counter < src_counter && counter < n)
	{
		dest[counter] = src[counter];
		counter++;
	}

	while (counter < n)
	{
		printf(" %s ", "here");
		dest[counter] = 'a';
		counter++;
	}

	return (dest);
}

int main()
{
	unsigned int n = 13;
	char str[13];
	char st[] = "asdfkjjfdsd";

	ft_strncpy(str, st, n);

	int i = 0;
	while(str[i])
	{
		printf("%c", str[i++]);
	}
	return (0);
}
