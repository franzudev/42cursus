/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:10:35 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:23:24 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = *stringp;
	if (*stringp == NULL)
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (delim[j])
		{
			if (tmp[i] == delim[j])
			{
				tmp[i] = '\0';
				*stringp += (i + 1);
				return (tmp);
			}
			j++;
		}
		i++;
	}
	*stringp = NULL;
	return (tmp);
}

void	check_buffer_overflow(char *buf, char *tmp)
{
	if (buf[BUF_SIZE - 1] != 0)
	{
		error_syntax(&buf[BUF_SIZE - 1]);
		ft_bzero(buf, BUF_SIZE);
		ft_strlcpy(buf, "\0", BUF_SIZE);
	}
	ft_strlcat(tmp, buf, BUF_SIZE);
}

void	print_prompt(char *prompt)
{
	ft_putstr_fd(prompt, STDERR);
}

int	have_whitespaces(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (ft_isblank(buf[i]))
			return (1);
		i++;
	}
	return (0);
}
