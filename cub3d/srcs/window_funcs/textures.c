/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:31 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:21 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	texture_filler(t_texture *texture, t_window *window, char *text_name)
{
	texture->img = mlx_xpm_file_to_image(window->mlx, text_name,
									&texture->img_width, &texture->img_height);
	texture->addr = (int *)mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
}

void	textures_filler(t_window *window)
{
	t_game_v *game_v;

	game_v = window->game_v;
	texture_filler(window->textures->n_texture, window, game_v->no_texture);
	texture_filler(window->textures->s_textture, window, game_v->so_texture);
	texture_filler(window->textures->w_texture, window, game_v->we_texture);
	texture_filler(window->textures->e_texture, window, game_v->ea_texture);
	texture_filler(window->textures->sprite_texture, window,
					game_v->sprite_texture);
	if (window->game_v->skybox)
		texture_filler(window->textures->skybox, window, game_v->skybox);
}
