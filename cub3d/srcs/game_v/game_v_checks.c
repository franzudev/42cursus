/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_v_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:23 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:18 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

int		is_color_filled(t_color *color)
{
	if (color->red && color->green && color->blue)
	{
		if (ft_atoi(color->red) > 255)
			return (0);
		if (ft_atoi(color->green) > 255)
			return (0);
		if (ft_atoi(color->blue) > 255)
			return (0);
		color->n_color = (1 << 24 | ft_atoi(color->red) << 16 |
							ft_atoi(color->green) << 8 | ft_atoi(color->blue));
		return (1);
	}
	return (0);
}

int		is_map_moment(t_game_v *game_v)
{
	if (game_v->res_h && game_v->res_w &&
		game_v->no_texture && game_v->so_texture &&
		game_v->we_texture && game_v->ea_texture &&
		game_v->sprite_texture &&
		is_color_filled(game_v->floor_color))
	{
		if (game_v->bonus)
		{
			if (game_v->skybox)
				return (1);
		}
		else
		{
			if (is_color_filled(game_v->ceiling_color))
				return (1);
		}
	}
	return (0);
}

int		is_texture_valid(char *text_name)
{
	if (check_suffix(text_name, ".xpm"))
	{
		if (open((const char *)text_name, 00) >= 0)
		{
			close(*text_name);
			return (1);
		}
	}
	printf("Error\ntexture %s not valid\n", text_name);
	return (0);
}

int		validator(t_game_v *game_v)
{
	if (is_texture_valid(game_v->no_texture))
		if (is_texture_valid(game_v->so_texture))
			if (is_texture_valid(game_v->we_texture))
				if (is_texture_valid(game_v->ea_texture))
					if (is_texture_valid(game_v->sprite_texture))
					{
						if (ft_strlen(game_v->skybox))
						{
							if (is_texture_valid(game_v->skybox))
								return (1);
							else
								return (0);
						}
						return (1);
					}
	return (0);
}

int		are_game_v_ok(t_game_v *game_v)
{
	if (is_map_moment(game_v) &&
		is_map_valid(game_v->map) &&
		validator(game_v))
	{
		mat_size(game_v);
		return (1);
	}
	return (0);
}
