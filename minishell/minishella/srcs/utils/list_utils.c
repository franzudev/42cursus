/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:10:18 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:23:08 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_lst_add(t_env **env_lst, t_env *new_env)
{
	t_env	*tmp;

	if (env_lst != NULL)
	{
		if (*env_lst == NULL)
			*env_lst = new_env;
		else
		{
			tmp = *env_lst;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_env;
		}
	}
}

void	env_lst_remove(t_env *env_lst, char *key)
{
	t_env	*previous_node;

	previous_node = env_lst;
	while (env_lst)
	{
		if (!ft_strncmp(env_lst->key, key, ft_strlen(key) + 1))
		{
			if (env_lst->key)
				free(env_lst->key);
			if (env_lst->value)
				free(env_lst->value);
			previous_node->next = env_lst->next;
			free(env_lst);
			env_lst = previous_node;
		}
		previous_node = env_lst;
		env_lst = env_lst->next;
	}
}

char	*get_env(t_env *env_lst, char *key)
{
	while (env_lst)
	{
		if (!ft_strncmp(env_lst->key, key, ft_strlen(key) + 1))
		{
			return (env_lst->value);
		}
		env_lst = env_lst->next;
	}
	return (NULL);
}

void	cmd_lst_add(t_cmd **cmd_lst, t_cmd *new_cmd)
{
	t_cmd	*tmp;

	if (*cmd_lst == NULL || (*cmd_lst)->args == NULL)
		*cmd_lst = new_cmd;
	else
	{
		tmp = *cmd_lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_cmd;
	}
}

int	cmd_lst_size(t_cmd *cmd_lst)
{
	int		count;
	t_cmd	*tmp;

	count = 0;
	tmp = cmd_lst;
	if (!cmd_lst)
		return (0);
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
