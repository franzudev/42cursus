/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:05:11 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env_lst(t_env *env_lst)
{
	char	env[BUF_SIZE];

	ft_bzero(env, BUF_SIZE);
	while (env_lst)
	{
		if (env_lst->value)
		{
			ft_strlcat(env, env_lst->key, BUF_SIZE);
			ft_strlcat(env, "=", BUF_SIZE);
			ft_strlcat(env, env_lst->value, BUF_SIZE);
			ft_putendl_fd(env, STDOUT);
			ft_bzero(env, BUF_SIZE);
		}
		env_lst = env_lst->next;
	}
}
