/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dbl_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:07:19 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_dbl_quotes(t_ast **token, char *buf, t_env *env_lst)
{
	if ((*token)->type == VAR
		|| (g_sig.dollar_quote && (*token)->type == QUEST))
		handle_variables_quotes(buf, token, env_lst);
	else if ((*token)->type == ESCAPE && (*token)->right
		&& ((*token)->right->value[0] == '\''
			|| (*token)->right->value[0] == ' '))
		ft_strcat(buf, (*token)->value);
	else if ((*token)->type != DOLLAR
		&& (g_sig.dollar_quote || (*token)->type != ESCAPE)
		&& (*token)->type != DBLQUOTE)
		ft_strcat(buf, (*token)->value);
}
