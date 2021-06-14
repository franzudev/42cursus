/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:08:59 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	has_redirection(t_cmd *cmd_lst)
{
	int	i;

	i = 0;
	while (cmd_lst->type[i])
	{
		if (cmd_lst->type[i] == REDIR || cmd_lst->type[i] == INPUT
			|| cmd_lst->type[i] == APPEND)
			return (true);
		i++;
	}
	return (false);
}

void	get_redir(t_state *st, t_cmd *cmd_lst, char **buffer)
{
	int		i;
	char	**ptr;

	i = 0;
	ptr = cmd_lst->args;
	while (cmd_lst->type[i])
	{
		if (cmd_lst->type[i] == ARG)
		{
			*ptr = ft_strdup(buffer[i]);
			ptr++;
		}
		if (cmd_lst->type[i] == REDIR || cmd_lst->type[i] == APPEND)
		{
			redir_append(st, &buffer[i], cmd_lst->type[i]);
			i++;
		}
		if (cmd_lst->type[i] == INPUT)
		{
			if (input(st, &buffer[i]))
				return ;
			i++;
		}
		i++;
	}
}

void	parse_redirection(t_state *st, t_cmd *cmd_lst)
{
	char	*buffer[BUF_SIZE];
	int		i;

	i = 0;
	if (has_redirection(cmd_lst))
	{
		ft_bzero(buffer, BUF_SIZE);
		while (cmd_lst->args[i])
		{
			buffer[i] = ft_strdup(cmd_lst->args[i]);
			free(cmd_lst->args[i]);
			cmd_lst->args[i] = NULL;
			i++;
		}
		get_redir(st, cmd_lst, buffer);
		i = 0;
		while (buffer[i])
		{
			free(buffer[i]);
			i++;
		}
	}
}
