/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:10:29 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:26:20 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sig_init(char *cmd)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
	g_sig.pipe = 0;
	g_sig.pid = 0;
	if (!cmd || ft_strncmp(cmd, "exit", 5))
		g_sig.exit_status = 0;
}

void	sig_int(void)
{
	if (g_sig.pid == 0 && g_sig.pipe == 0)
		print_prompt("\nLillo ❯ ");
	else
		ft_putstr_fd("\n", STDERR);
	ft_bzero(g_sig.buf, BUF_SIZE);
	g_sig.exit_status = 130;
}

void	sig_quit(void)
{
	if (g_sig.pid != 0)
	{
		ft_putstr_fd("Quit\n", STDERR);
		g_sig.exit_status = 131;
		g_sig.sigquit = 1;
	}
}

void	handle_signal(int signal)
{
	if (signal == SIGINT)
		sig_int();
	if (signal == SIGQUIT)
		sig_quit();
}

void	catch_signal(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}
