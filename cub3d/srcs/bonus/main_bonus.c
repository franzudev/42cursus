/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:23 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:11 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"
#include "libcub_bonus.h"

int		update(t_window *window)
{
	t_data		image;

	player_movement_b(window->keys, window->player, window->game_v->map);
	mouse_rot(window);
	new_image(&image, window,
				window->game_v->res_w_nu, window->game_v->res_h_nu);
	cast_ray(window->player, window->game_v, &image, window);
	minimap_img(&image, window, window->player, 4);
	mlx_put_image_to_window(window->mlx, window->mlx_win, image.img, 0, 0);
	mlx_destroy_image(window->mlx, image.img);
	if (window->keys->esc)
		close_game(window);
	if (window->game_v->save)
		screenshot(window, &image);
	return (1);
}

void	engine_starter(t_window *window)
{
	mlx_hook(window->mlx_win, 06, 0L, mouse_pos_mov, window);
	mlx_hook(window->mlx_win, 02, 0L, key_hook_in, window);
	mlx_hook(window->mlx_win, 03, 0L, key_hook_out, window);
	mlx_hook(window->mlx_win, 17, 0L, close_game, window);
	mlx_loop_hook(window->mlx, update, window);
	mlx_loop(window->mlx);
}

int		ret_error(void)
{
	printf("Error\nwrong number of arguments, or wrong arguments");
	return (-1);
}

int		fillers(t_game_v *game_v, char *filename, t_window *window)
{
	if (!game_v_filler(game_v, filename))
		return (-1);
	window->game_v = game_v;
	game_v->bonus = 1;
	clean_window_struct(window);
	start_win(window, game_v);
	if (!validator(game_v))
		return (-1);
	textures_filler(window);
	engine_starter(window);
	return (1);
}

int		main(int argc, char **argv)
{
	t_game_v	game_v[1];
	t_window	window;

	if (argc > 1)
	{
		game_v_cleaner(game_v);
		if (argc > 2 && check_string(argv[2], "--save"))
			game_v->save = 1;
		if (check_suffix(argv[1], ".cub"))
		{
			if (fillers(game_v, argv[1], &window) < 0)
				return (-1);
		}
		else
			return (ret_error());
	}
	return (ret_error());
}
