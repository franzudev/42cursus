/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:07:43 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	expand_exit_code(char *buf, t_ast **token)
{
	char	*nbr;

	if (g_sig.dollar_quote)
	{
		nbr = ft_itoa(g_sig.exit_status);
		ft_strcat(buf, nbr);
		free(nbr);
	}
	else
		ft_strcat(buf, (*token)->value);
}

int	handle_variables(char *buf, t_ast **token, t_env *env_lst)
{
	char	tmp[BUF_SIZE];

	ft_bzero(tmp, BUF_SIZE);
	if ((*token)->type == VAR)
	{
		ft_strlcpy(tmp, (*token)->value, ft_strlen((*token)->value) + 1);
		expand_var(tmp, env_lst, token);
		if ((*token)->value)
		{
			if (have_whitespaces((*token)->value))
				return (1);
			if ((*token) && (*token)->type != VAR)
				ft_strcat(buf, (*token)->value);
		}
	}
	else if ((*token)->type == QUEST)
		expand_exit_code(buf, token);
	return (0);
}
