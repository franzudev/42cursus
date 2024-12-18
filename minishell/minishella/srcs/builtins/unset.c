/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:06:11 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_unset(char **variables, t_env **env_lst)
{
	int		i;
	t_env	*tmp;

	i = 1;
	while (variables[i])
	{
		if (!ft_strncmp((*env_lst)->key, variables[i],
				ft_strlen(variables[i]) + 1))
		{
			tmp = (*env_lst)->next;
			if ((*env_lst)->key)
				free((*env_lst)->key);
			if ((*env_lst)->value)
				free((*env_lst)->value);
			free(*env_lst);
			*env_lst = tmp;
		}
		else
			env_lst_remove(*env_lst, variables[i]);
		i++;
	}
}
