/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:06:50 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_hist(t_hist *history)
{
	if (history && history->value)
		ft_putstr_fd(history->value, STDOUT);
}

static void	hist_add(t_hist **history, t_hist *new_node)
{
	if (!(*history))
		*history = new_node;
	else
	{
		while ((*history)->next != NULL)
			*history = (*history)->next;
		(*history)->next = new_node;
		new_node->previous = *history;
		*history = (*history)->next;
	}
}

void	hist_update(t_hist **history, char *buffer)
{
	t_hist	*new_node;

	new_node = ft_calloc(1, sizeof(t_ast));
	new_node->next = NULL;
	new_node->value = ft_strdup(buffer);
	hist_add(history, new_node);
}

void	free_hist(t_hist **history)
{
	t_hist	*ptr;
	t_hist	*tmp;

	ptr = *history;
	while (ptr)
	{
		tmp = ptr->previous;
		if (ptr->value)
			free(ptr->value);
		free(ptr);
		ptr = tmp;
	}
	history = NULL;
}
