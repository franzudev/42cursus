/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:23 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:20 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

t_texture	*texture_selector(t_window *window, t_caster *caster)
{
	if (caster->side == 0)
	{
		if (caster->ray_dir_x > 0)
			return (window->textures->e_texture);
		else
			return (window->textures->w_texture);
	}
	else
	{
		if (caster->ray_dir_y > 0)
			return (window->textures->s_textture);
		else
			return (window->textures->n_texture);
	}
}

void		texturer(t_caster *caster, t_player *player,
					t_game_v *game_v, t_window *window)
{
	t_texture *texture;

	texture = texture_selector(window, caster);
	if (caster->side == 0)
		caster->wall_x = player->pos_y + caster->perp_wall_dist *
							caster->ray_dir_y;
	else
		caster->wall_x = player->pos_x + caster->perp_wall_dist *
							caster->ray_dir_x;
	caster->wall_x -= floor((caster->wall_x));
	caster->tex_x = (int)(caster->wall_x * (double)(texture->img_width));
	if (caster->side == 0 && caster->ray_dir_x > 0)
		caster->tex_x = texture->img_width - caster->tex_x - 1;
	if (caster->side == 1 && caster->ray_dir_y < 0)
		caster->tex_x = texture->img_width - caster->tex_x - 1;
	caster->step = 1.0 * texture->img_height / caster->line_height;
	caster->tex_pos = (caster->draw_start - game_v->res_h_nu / 2 +
						caster->line_height / 2) * caster->step;
}
