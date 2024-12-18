/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:05:48 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:20:44 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_cwd(void)
{
	char	buf[BUF_SIZE];

	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);
}
