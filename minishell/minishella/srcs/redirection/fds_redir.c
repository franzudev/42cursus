/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:08:49 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/15 17:38:02 by lincerpi         ###   ########.fr       */
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

static int	check_eof(char *args, int fd, char buff, int i)
{
	char	tmp[BUF_SIZE];

	tmp[0] = buff;
	i = 1;
	while (read(1, &buff, 1) > 0 && args[i])
	{
		if (buff == args[i])
			tmp[i] = buff;
		else
		{
			tmp[i] = buff;
			tmp[i + 1] = '\0';
			write(1, "> ", 2);
			write(fd, tmp, i + 1);
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (args[i] != '\0')
	{
		tmp[i] = '\0';
		write(fd, tmp, i);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	grande_puffo(char **args, int fd)
{
	int		start;
	char	buff;

	start = 0;
	while (read(1, &buff, 1) > 0)
	{
		if (buff == args[0][0] && start == 0)
		{
			if (!check_eof(args[0], fd, buff, start))
				break ;
			else
				continue ;
		}
		if (buff == '\n')
		{
			start = -1;
			write(1, "> ", 2);
		}
		if (write(fd, &buff, 1) < 0)
			return (EXIT_FAILURE);
		start++;
	}
	return (EXIT_SUCCESS);
}

static int	minchia(t_state *st, char **args)
{
	int		fd;

	fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		return (EXIT_FAILURE);
	write(1, "> ", 2);
	if (grande_puffo(args, fd))
		return (EXIT_FAILURE);
	close(fd);
	st->fdin = open(".heredoc", O_RDONLY, S_IRWXU);
	dup2(st->fdin, STDIN);
	ft_close(st->fdin);
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
			ft_putstr_fd("lsh: ", STDERR);
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
