/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:10:03 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:22:46 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	file_exists(char *filename)
{
	struct stat	buf;

	if (!filename)
		return (0);
	if (stat(filename, &buf))
		return (0);
	else
		return (1);
}
