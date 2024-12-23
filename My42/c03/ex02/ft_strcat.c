/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:56:42 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/03 15:57:21 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int d;
	int s;

	d = 0;
	s = 0;
	while (dest[d])
	{
		d++;
	}
	while (src[s] != '\0')
	{
		dest[d] = src[s++];
		d++;
	}
	dest[d] = '\0';
	return (dest);
}
