/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:23 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:18 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static void	color_to_char(int color, int fd)
{
	U_C rgb[4];

	rgb[0] = (U_C)color;
	rgb[1] = (U_C)(color >> 8);
	rgb[2] = (U_C)(color >> 16);
	rgb[3] = (U_C)(color >> 24);
	write(fd, rgb, 4);
}

static void	write_pixels(t_window *window, t_data *img, int fd)
{
	int *address;
	int x;
	int y;
	int color;

	address = (int *)img->addr;
	y = window->game_v->res_h_nu - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < window->game_v->res_w_nu)
		{
			color = address[(y * window->game_v->res_w_nu) + x];
			color_to_char(color, fd);
			x++;
		}
		y--;
	}
}

static void	write_header(t_window *window, int fd, t_data *img)
{
	U_C				buffer[54];
	t_game_v		*game_v;

	ft_bzero(buffer, 54);
	game_v = window->game_v;
	buffer[0] = 'B';
	buffer[1] = 'M';
	buffer[2] = (U_C)(54 + game_v->res_w_nu * game_v->res_h_nu * 4);
	buffer[3] = (U_C)(54 + game_v->res_w_nu * game_v->res_h_nu * 4) >> 8;
	buffer[4] = (U_C)(54 + game_v->res_w_nu * game_v->res_h_nu * 4) >> 16;
	buffer[5] = (U_C)(54 + game_v->res_w_nu * game_v->res_h_nu * 4) >> 24;
	buffer[10] = (U_C)54;
	buffer[14] = (U_C)40;
	buffer[18] = (U_C)game_v->res_w_nu;
	buffer[19] = (U_C)(game_v->res_w_nu >> 8);
	buffer[20] = (U_C)(game_v->res_w_nu >> 16);
	buffer[21] = (U_C)(game_v->res_w_nu >> 24);
	buffer[22] = (U_C)(game_v->res_h_nu);
	buffer[23] = (U_C)(game_v->res_h_nu >> 8);
	buffer[24] = (U_C)(game_v->res_h_nu >> 16);
	buffer[25] = (U_C)(game_v->res_h_nu >> 24);
	buffer[26] = (U_C)1;
	buffer[28] = (U_C)img->bits_per_pixel;
	write(fd, buffer, 54);
}

void		screenshot(t_window *window, t_data *img)
{
	int fd;

	if ((fd = open("screenshot.bmp",
			O_WRONLY | O_APPEND | O_CREAT | O_TRUNC,
			S_IRWXU)) <= 0)
		close_game(window);
	write_header(window, fd, img);
	write_pixels(window, img, fd);
	close(fd);
	close_game(window);
}
