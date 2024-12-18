/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:10:13 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**free_2darray(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free((void *)array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	return (NULL);
}

void	free_env_lst(t_env *env_lst)
{
	t_env	*ptr_lst;
	t_env	*temp;

	ptr_lst = env_lst;
	while (ptr_lst)
	{
		if (ptr_lst->key)
			free(ptr_lst->key);
		if (ptr_lst->value)
			free(ptr_lst->value);
		temp = ptr_lst->next;
		free(ptr_lst);
		ptr_lst = temp;
	}
	env_lst = NULL;
}

/*
** clear multicommands, keeps one node in cmd_lst and cmd_lst->args = NULL
*/

void	clear_previous_cmd(t_cmd *cmd_lst, t_state *st)
{
	t_cmd	*ptr;
	t_cmd	*tmp;

	(void)st;
	free_2darray(cmd_lst->args);
	cmd_lst->args = NULL;
	ptr = cmd_lst->next;
	cmd_lst->next = NULL;
	while (ptr)
	{
		tmp = ptr->next;
		free_2darray(ptr->args);
		free(ptr);
		ptr = tmp;
	}
}
