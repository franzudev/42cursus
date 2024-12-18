/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:59:57 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/01 10:15:25 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int counter;
	unsigned int src_counter;

	counter = 0;
	src_counter = 0;
	while (src[src_counter] != '\0')
	{
		src_counter++;
	}
	src_counter -= 1;
	while (counter < src_counter && counter < n)
	{
		dest[counter] = src[counter];
		counter++;
	}
	while (counter < n)
	{
		dest[counter] = 'a';
		counter++;
	}
	return (dest);
}
