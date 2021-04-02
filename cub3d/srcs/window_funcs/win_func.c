/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:31 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:21 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void		start_win(t_window *window, t_game_v *game_v)
{
	window->game_v = game_v;
	where_is_the_player(window->game_v->map, window->player);
	clean_keys(window->keys);
	window->mlx = mlx_init();
	resize_to_screen_size(window->game_v, window);
	window->mlx_win = mlx_new_window(window->mlx, game_v->res_w_nu,
										game_v->res_h_nu, "ROOM");
}

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		new_image(t_data *image, t_window *window, int width, int height)
{
	image->img = mlx_new_image(window->mlx, width, height);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
									&image->line_length, &image->endian);
}

static void	free_win(t_window *window)
{
	free(window->textures->e_texture->addr);
	free(window->textures->n_texture->addr);
	free(window->textures->s_textture->addr);
	free(window->textures->w_texture->addr);
	free(window->textures->sprite_texture->addr);
	if (window->game_v->bonus)
		free(window->textures->skybox->addr);
}

int			close_game(t_window *window)
{
	mlx_destroy_window(window->mlx, window->mlx_win);
	free_game_v(window->game_v);
	free_win(window);
	exit(0);
	return (0);
}
