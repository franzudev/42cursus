/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:02:25 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parse_nl_param(char **arg, int i)
{
	int	j;

	while (arg[i] && arg[i][0] == '-')
	{
		j = 1;
		while (arg[i][j])
		{
			if (arg[i][j] != 'n')
				return (i - 1);
			j++;
		}
		i++;
	}
	return (i - 1);
}

int	builtin_echo(char **arg, t_cmd *cmd_lst)
{
	int		i;
	int		isn;

	(void)cmd_lst;
	isn = 0;
	i = 1;
	if (arg[i] && !ft_strncmp(arg[i], "-n", 2))
		isn = parse_nl_param(arg, i);
	i += isn;
	while (arg[i])
	{
		if (*arg[i] != '\0')
			ft_putstr_fd(arg[i], STDOUT);
		if (arg[i + 1] && ((arg[i][0] == '\0' && cmd_lst->type[i] != VAR)
			|| (arg[i][0] != '\0' && cmd_lst->type[i] == VAR)
			|| cmd_lst->type[i] != VAR))
			write(STDOUT, " ", 1);
		i++;
	}
	if (!isn)
		write(STDOUT, "\n", 1);
	return (0);
}
