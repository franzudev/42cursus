/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:09:40 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:22:30 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ast_add(t_ast **token, t_ast *new_node)
{
	t_ast	*tmp;

	tmp = *token;
	if (!(*token))
		*token = new_node;
	else
	{
		while ((*token)->right != NULL)
			*token = (*token)->right;
		(*token)->right = new_node;
		new_node->left = *token;
		*token = tmp;
	}
}

t_ast	*create_node(char *buffer, enum e_type type)
{
	t_ast	*new_node;

	new_node = ft_calloc(1, sizeof(t_ast));
	new_node->type = type;
	new_node->right = NULL;
	new_node->value = buffer;
	return (new_node);
}

void	ast_init(t_ast **token, char **buffer)
{
	t_ast	*new_node;
	int		i;

	i = 0;
	while (buffer[i])
	{
		new_node = create_node(buffer[i], ARG);
		ast_add(token, new_node);
		i++;
	}
	ast_check_type(token);
}

void	free_ast(t_ast **token)
{
	t_ast	*ptr;
	t_ast	*tmp;

	ptr = *token;
	while (ptr)
	{
		tmp = ptr->right;
		if (ptr->value)
			free(ptr->value);
		free(ptr);
		ptr = tmp;
	}
	*token = NULL;
}
