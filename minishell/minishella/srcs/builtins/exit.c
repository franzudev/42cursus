/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:05:23 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool	ft_isnum(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static void	free_exit(t_state *status, t_env *env_lst, t_cmd *cmd_lst)
{
	t_cmd	*tmp;

	if (status->envp)
		free_2darray(status->envp);
	free_hist(&status->history);
	free(status);
	free_env_lst(env_lst);
	while (cmd_lst)
	{
		tmp = cmd_lst->next;
		free_2darray(cmd_lst->args);
		free(cmd_lst);
		cmd_lst = tmp;
	}
}

int	exit_msh(t_state *status, t_env *env_lst, t_cmd *cmd_lst)
{
	ft_putstr_fd("exit\n", STDERR);
	if (cmd_lst->args && cmd_lst->args[1] && !ft_isnum(cmd_lst->args[1]))
	{
		g_sig.exit_status = 2;
		ft_putstr_fd("lsh: exit: ", STDERR);
		ft_putstr_fd(cmd_lst->args[1], STDERR);
		ft_putendl_fd(": numeric argument required", STDERR);
	}
	else if (cmd_lst->args && cmd_lst->args[1] && cmd_lst->args[2])
	{
		g_sig.exit_status = 1;
		ft_putstr_fd("lsh: exit: too many arguments\n", STDERR);
		return (1);
	}
	else if (cmd_lst->args && cmd_lst->args[1])
		g_sig.exit_status = ft_atoi(cmd_lst->args[1]);
	disable_raw_mode(status);
	free_exit(status, env_lst, cmd_lst);
	exit(g_sig.exit_status);
	return (g_sig.exit_status);
}
