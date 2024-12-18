/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:22:29 by ffrancoi          #+#    #+#             */
/*   Updated: 2020/12/11 13:54:45 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int ctrl;
	unsigned int dst_len;
	unsigned int dst_len_temp;
	unsigned int i;

	dst_len = 0;
	i = 0;
	while (dest[dst_len] != '\0')
	{
		dst_len++;
	}
	dst_len_temp = dst_len;
	ctrl = size - dst_len;
	if (ctrl < 0)
	{
		return (size + dst_len);
	}
	while (src[i] != '\0' && i < ctrl - 1)
		dest[dst_len++] = src[i++];
	dest[dst_len] = '\0';
	while (src[i] != '\0')
		i++;
	return (i + dst_len_temp);
}
