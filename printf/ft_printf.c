/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 21:18:39 by franzu            #+#    #+#             */
/*   Updated: 2021/02/07 21:18:40 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "include/libft.h"

int	ft_printf(const char *str, ...)
{
	int		printed;
	int		ret;
	va_list	args;

	printed = 0;
	ret = 0;
	if (!ft_strchr(str, '%'))
	{
		ft_putstr_fd((char *)str, 1);
		return (ft_strlen(str));
	}
	va_start(args, str);
	while (*str)
	{
		ret = parse_format(str, &args, &printed);
		if (printed == -1)
			return (-1);
		str += ret;
	}
	va_end(args);
	return (printed);
}
