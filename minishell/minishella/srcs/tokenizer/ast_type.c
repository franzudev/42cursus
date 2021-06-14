/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:09:33 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_type(t_ast *ptr, enum e_type type)
{
	if (!ptr->left || (ptr->left && ptr->left->type != ESCAPE))
		ptr->type = type;
}

static void	set_redir_append(t_ast *ptr)
{
	if (ptr->value[0] == '>')
	{
		if (!ft_strncmp(ptr->value, ">>", 3))
			ptr->type = APPEND;
		else if (!ptr->left || (ptr->left && ptr->left->type != ESCAPE
				&& ptr->left->type != REDIR))
			ptr->type = REDIR;
	}
	else if (ptr->value[0] == '<')
	{
		if (!ft_strncmp(ptr->value, "<<", 3))
			ptr->type = MINCHIA;
		else
			ptr->type = INPUT;
	}
}

static void	set_escape(t_ast *ptr)
{
	if ((ptr->right && (ptr->right->value[0] == '$'
				|| ptr->right->value[0] == '\"' || ptr->right->value[0] == '\''
				|| ptr->right->value[0] == '>' || ptr->right->value[0] == '<'
				|| ptr->right->value[0] == '\\' || ptr->right->value[0] == '?'
				|| ptr->right->value[0] == ';' || ptr->right->value[0] == '|'
				|| ptr->right->value[0] == ' '))
		&& (ptr->left && ptr->left->type != ESCAPE))
		set_type(ptr, ESCAPE);
}

static void	ast_check_type2(t_ast *ptr)
{
	if (ptr->value[0] == '\'')
		set_type(ptr, QUOTE);
	else if (ptr->value[0] == '\"')
		set_type(ptr, DBLQUOTE);
	else if (ptr->value[0] == '<')
		set_redir_append(ptr);
	else if (ptr->value[0] == '>')
		set_redir_append(ptr);
	else if (ptr->left && ptr->left->type == DOLLAR)
		ptr->type = VAR;
}

void	ast_check_type(t_ast **token)
{
	t_ast	*ptr;

	ptr = *token;
	while (ptr)
	{
		if (ptr->value[0] == '\\')
			set_escape(ptr);
		else if (ptr->value[0] == ' ' || ptr->value[0] == '\t')
			set_type(ptr, WHITESPACE);
		else if (ptr->value[0] == '$')
		{
			if (ptr->right)
				set_type(ptr, DOLLAR);
		}
		else if (ptr->value[0] == ';')
			set_type(ptr, SEMICOLON);
		else if (ptr->value[0] == '|')
			set_type(ptr, PIPE);
		else if (ptr->value[0] == '?')
			set_type(ptr, QUEST);
		else
			ast_check_type2(ptr);
		ptr = ptr->right;
	}
}
