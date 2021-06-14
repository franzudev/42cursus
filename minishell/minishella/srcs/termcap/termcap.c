/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:09:25 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:22:13 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	enable_raw_mode(t_state *st)
{
	ft_bzero(&st->termios_new, sizeof(struct termios));
	tcgetattr(STDIN_FILENO, &st->termios_backup);
	st->termios_new = st->termios_backup;
	st->termios_new.c_lflag &= ~(ICANON | ECHO);
	st->termios_new.c_cc[VMIN] = 1;
	st->termios_new.c_cc[VTIME] = 0;
	st->raw_mode = true;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &st->termios_new);
	return ;
}

void	disable_raw_mode(t_state *st)
{
	if (st->raw_mode)
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &st->termios_backup);
}
