/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:08:42 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_fds(t_state **st)
{
	(*st)->fdin = -1;
	(*st)->fdout = -1;
}

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	reset_std(t_state *st)
{
	dup2(st->in, STDIN);
	dup2(st->out, STDOUT);
}

void	close_fds(t_state *st)
{
	ft_close(st->fdin);
	ft_close(st->fdout);
}
