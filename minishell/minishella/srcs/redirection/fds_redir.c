/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:08:49 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:21:50 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redir_append(t_state *st, char **args, enum e_type type)
{
	args++;
	if (type == REDIR)
	{
		st->fdout = open(*args, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		if (st->fdout == -1)
		{
			error_fd(*args);
			return ;
		}
	}
	else if (type == APPEND)
	{
		st->fdout = open(*args, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
		if (st->fdout == -1)
		{
			error_fd(*args);
			return ;
		}
	}
	dup2(st->fdout, STDOUT);
	ft_close(st->fdout);
}

static int michia(t_state *st, char **argv)
{
	int fd;
	char buff;

	fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC);
	if (fd < 0)
		return (EXIT_FAILURE);
	write(1, "> ", 2);
	while (read(1, &buff, 1) > 0)
	{
		if (buff == '\n')
			write(1, "> ", 2);
		// aggiungere argv == EOF
		if (write(fd, &buff, 1) < 0)
			return (EXIT_FAILURE);
	}
	st->fdin = open(".heredoc", O_RDONLY, S_IRWXU);
	dup2(st->fdin, STDIN);
	ft_close(st->fdin);
	close(fd);
	return (EXIT_SUCCESS);
}

int	input(t_state *st, char **args, enum e_type type)
{
	args++;
	if (type == INPUT)
	{
		st->fdin = open(*args, O_RDONLY, S_IRWXU);
		if (st->fdin == -1)
		{
			ft_putstr_fd("msh: ", STDERR);
			ft_putstr_fd(*args, STDERR);
			ft_putendl_fd(": No such file or directory", STDERR);
			g_sig.exit_status = 1;
			return (1);
		}
		dup2(st->fdin, STDIN);
		ft_close(st->fdin);
	}
	else if (type == MINCHIA)
		minchia(st, args);
	return (0);
}
