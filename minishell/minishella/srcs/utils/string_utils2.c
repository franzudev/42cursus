/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:10:40 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:23:32 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	tab_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	ft_isblank(int c)
{
	if (c >= 0)
	{
		if (c == ' ' || c == '\t')
			return (1);
		else
			return (0);
	}
	return (0);
}

bool	is_empty(char *str)
{
	bool	ret;

	ret = true;
	while (*str)
	{
		if (ft_isblank(*str))
			str++;
		else
		{
			ret = false;
			break ;
		}
	}
	return (ret);
}

static void	concat_env2(t_env *env_lst, char *env)
{
	ft_strlcat(env, env_lst->key, BUF_SIZE);
	ft_strlcat(env, "=", BUF_SIZE);
	ft_strlcat(env, env_lst->value, BUF_SIZE);
	if (env_lst->next)
		ft_strcat(env, "\n");
}

char	*concat_env(t_env *env_lst)
{
	int		n;
	t_env	*ptr;
	char	*env;

	n = 0;
	ptr = env_lst;
	while (ptr)
	{
		if (ptr->key && ptr->value)
			n = n + ft_strlen(ptr->key) + ft_strlen(ptr->value) + 2;
		ptr = ptr->next;
	}
	env = ft_calloc(n, sizeof(char));
	while (env_lst)
	{
		if (env_lst->key && env_lst->value)
			concat_env2(env_lst, env);
		env_lst = env_lst->next;
	}
	return (env);
}
