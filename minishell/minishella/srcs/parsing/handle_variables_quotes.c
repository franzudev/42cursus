/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_variables_quotes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:07:31 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_variables_quotes(char *buf, t_ast **token, t_env *env_lst)
{
	char	tmp[BUF_SIZE];

	ft_bzero(tmp, BUF_SIZE);
	if ((*token)->type == VAR)
	{
		ft_strlcpy(tmp, (*token)->value, ft_strlen((*token)->value) + 1);
		expand_var(tmp, env_lst, token);
		if ((*token) && (*token)->type != VAR)
			ft_strcat(buf, (*token)->value);
	}
	else if ((*token)->type == QUEST)
	{
		expand_exit_code(buf, token);
		g_sig.dollar_quote = false;
	}
}
