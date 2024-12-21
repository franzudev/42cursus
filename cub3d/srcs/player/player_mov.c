/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:51:23 by ffrancoi          #+#    #+#             */
/*   Updated: 2021/04/01 14:52:18 by ffrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void		decrement_degree(float *inclination, float degree, t_plane *plane)
{
	double old_dir_x;
	double old_plane_x;

	if (*inclination + degree >= 2 * M_PI)
		*inclination = 0;
	else
		*inclination += degree;
	old_dir_x = plane->dir_x;
	plane->dir_x = plane->dir_x * cos(ONE_D) - plane->dir_y * sin(ONE_D);
	plane->dir_y = old_dir_x * sin(ONE_D) + plane->dir_y * cos(ONE_D);
	old_plane_x = plane->plane_x;
	plane->plane_x = plane->plane_x * cos(ONE_D) - plane->plane_y * sin(ONE_D);
	plane->plane_y = old_plane_x * sin(ONE_D) + plane->plane_y * cos(ONE_D);
}

void		increment_degree(float *inclination, float degree, t_plane *plane)
{
	double old_dir_x;
	double old_plane_x;

	if (*inclination - degree < 0)
	{
		*inclination = (2 * M_PI) - ONE_D;
	}
	else
		*inclination -= degree;
	old_dir_x = plane->dir_x;
	plane->dir_x = plane->dir_x * cos(-ONE_D) - plane->dir_y * sin(-ONE_D);
	plane->dir_y = old_dir_x * sin(-ONE_D) + plane->dir_y * cos(-ONE_D);
	old_plane_x = plane->plane_x;
	plane->plane_x = plane->plane_x * cos(-ONE_D) - plane->plane_y *
						sin(-ONE_D);
	plane->plane_y = old_plane_x * sin(-ONE_D) + plane->plane_y * cos(-ONE_D);
}

static void	straight_mov(t_player *player, char dir, char **map)
{
	t_plane *plane;

	plane = player->plane;
	if (dir == 'B')
	{
		if (map[(int)(player->pos_y)]
				[(int)(player->pos_x + plane->dir_x * player->speed)] != '1')
			player->pos_x += plane->dir_x * player->speed;
		if (map[(int)(player->pos_y + plane->dir_y * player->speed)]
				[(int)(player->pos_x)] != '1')
			player->pos_y += plane->dir_y * player->speed;
	}
	else if (dir == 'F')
	{
		if (map[(int)(player->pos_y)]
				[(int)(player->pos_x - plane->dir_x * player->speed)] != '1')
			player->pos_x -= plane->dir_x * player->speed;
		if (map[(int)(player->pos_y - plane->dir_y * player->speed)]
				[(int)(player->pos_x)] != '1')
			player->pos_y -= plane->dir_y * player->speed;
	}
}

static void	side_mov(t_player *player, int dir, char **map)
{
	if (dir == 'R')
	{
		if (map[(int)player->pos_y][(int)(player->pos_x - player->plane->plane_x
		* 5 * player->speed)] != '1')
			player->pos_x -= (player->plane->plane_x * player->speed);
		if (map[(int)(player->pos_y - player->plane->plane_y
		* 5 * player->speed)][(int)player->pos_x] != '1')
			player->pos_y -= (player->plane->plane_y * player->speed);
	}
	else if (dir == 'L')
	{
		if (map[(int)player->pos_y][(int)(player->pos_x + player->plane->plane_x
		* 5 * player->speed)] != '1')
			player->pos_x += (player->plane->plane_x * player->speed);
		if (map[(int)(player->pos_y + player->plane->plane_y
		* 5 * player->speed)][(int)player->pos_x] != '1')
			player->pos_y += (player->plane->plane_y * player->speed);
	}
}

void		player_movement(t_keys *keys, t_player *player, char **map)
{
	if (keys->shift)
		player->speed = RUNNING_SPEED;
	else if (!keys->shift)
		player->speed = NORMAL_SPEED;
	if (keys->right_arrow)
		decrement_degree(&P_INCL, ONE_D, player->plane);
	if (keys->left_arrow)
		increment_degree(&P_INCL, ONE_D, player->plane);
	if (keys->w_key)
		straight_mov(player, 'B', map);
	if (keys->a_key)
		side_mov(player, 'L', map);
	if (keys->s_key)
		straight_mov(player, 'F', map);
	if (keys->d_key)
		side_mov(player, 'R', map);
}
