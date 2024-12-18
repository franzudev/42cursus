/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi_c_quoting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:07:00 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:21:24 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_ansi_c_quoting2(char **str, char c)
{
	if (c == 'r')
		*str = "\r";
	else if (c == 't')
		*str = "\t";
	else if (c == 'v')
		*str = "\v";
	else if (c == '\\')
		*str = "\\";
	else if (c == '\'')
		*str = "\'";
	else if (c == '\"')
		*str = "\"";
	else if (c == '\?')
		*str = "\?";
	if (!ft_strlen(*str))
		return (false);
	return (true);
}

bool	is_ansi_c_quoting(char **str, char c)
{
	if (c == 'a')
		*str = "\a";
	else if (c == 'b')
		*str = "\b";
	else if (c == 'e')
		*str = "\e";
	else if (c == 'E')
		*str = "\E";
	else if (c == 'f')
		*str = "\f";
	else if (c == 'n')
		*str = "\n";
	return (is_ansi_c_quoting2(str, c));
}
