/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:59:02 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/25 16:38:47 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	manage_player_moves(t_cube *cube, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;
	double	movespeed;
	double	rotspeed;
	
	movespeed = 0.1;
	rotspeed = 0.1;
if (keycode == cube->player_settings->move_forward)
	{
		if (cube->map->map[(int)cube->player_settings->pos.y][(int)(cube->player_settings->pos.x + cube->player_settings->dir_x /*/ cube->map->size_case*/ * movespeed)] != '1')
			cube->player_settings->pos.x += cube->player_settings->dir_x * movespeed;
		if (cube->map->map[(int)(cube->player_settings->pos.y + cube->player_settings->dir_y /*/ cube->map->size_case*/ * movespeed)][(int)cube->player_settings->pos.x] != '1')
			cube->player_settings->pos.y += cube->player_settings->dir_y * movespeed;
	}
	if (keycode == cube->player_settings->move_backward)
	{
		if (cube->map->map[(int)cube->player_settings->pos.y][(int)(cube->player_settings->pos.x - cube->player_settings->dir_x /*/ cube->map->size_case*/ * movespeed)] != '1')
			cube->player_settings->pos.x -= cube->player_settings->dir_x * movespeed;
		if (cube->map->map[(int)(cube->player_settings->pos.y - cube->player_settings->dir_y /*/ cube->map->size_case*/ * movespeed)][(int)cube->player_settings->pos.x] != '1')
			cube->player_settings->pos.y -= cube->player_settings->dir_y * movespeed;
	}
	if (keycode == cube->player_settings->move_left)
	{
		if (cube->map->map[(int)(cube->player_settings->pos.y - cube->player_settings->dir_x /*/ cube->map->size_case*/ * movespeed)][(int)cube->player_settings->pos.x] != '1')
			cube->player_settings->pos.y -= cube->player_settings->dir_x * movespeed;
		if (cube->map->map[(int)cube->player_settings->pos.y][(int)(cube->player_settings->pos.x + cube->player_settings->dir_y /*/ cube->map->size_case*/ * movespeed)] != '1')
			cube->player_settings->pos.x += cube->player_settings->dir_y * movespeed;
	}
	if (keycode == cube->player_settings->move_right)
	{
		if (cube->map->map[(int)(cube->player_settings->pos.y + cube->player_settings->dir_x /*/ cube->map->size_case*/ * movespeed)][(int)cube->player_settings->pos.x] != '1')
			cube->player_settings->pos.y += cube->player_settings->dir_x * movespeed;
		if (cube->map->map[(int)cube->player_settings->pos.y][(int)(cube->player_settings->pos.x - cube->player_settings->dir_y /*/ cube->map->size_case*/ * movespeed)] != '1')
			cube->player_settings->pos.x -= cube->player_settings->dir_y * movespeed;
	}
	if (keycode == ARROW_LEFT)
	{
		old_dir_x = cube->player_settings->dir_x;
		cube->player_settings->dir_x = cube->player_settings->dir_x * cos(-rotspeed) - cube->player_settings->dir_y * sin(-rotspeed);
		cube->player_settings->dir_y = old_dir_x * sin(-rotspeed) + cube->player_settings->dir_y * cos(-rotspeed);
		old_plane_x = cube->player_settings->plane.x;
		cube->player_settings->plane.x = cube->player_settings->plane.x * cos(-rotspeed) - cube->player_settings->plane.y * sin(-rotspeed);
		cube->player_settings->plane.y = old_plane_x * sin(-rotspeed) + cube->player_settings->plane.y * cos(-rotspeed);
	}
	if (keycode == ARROW_RIGHT)
	{
		old_dir_x = cube->player_settings->dir_x;
		cube->player_settings->dir_x = cube->player_settings->dir_x * cos(rotspeed) - cube->player_settings->dir_y * sin(rotspeed);
		cube->player_settings->dir_y = old_dir_x * sin(rotspeed) + cube->player_settings->dir_y * cos(rotspeed);
		old_plane_x = cube->player_settings->plane.x;
		cube->player_settings->plane.x = cube->player_settings->plane.x * cos(rotspeed) - cube->player_settings->plane.y * sin(rotspeed);
		cube->player_settings->plane.y = old_plane_x * sin(rotspeed) + cube->player_settings->plane.y * cos(rotspeed);
	}
	mlx_clear_window(cube->mlx_ptr, cube->window_ptr);
	check_and_do_portal(cube);
	#include <stdio.h>
	render_cube(cube);
}

void	handle_game_hook(t_cube *cube, int keycode)
{
	if (keycode == cube->player_settings->move_forward || keycode == \
cube->player_settings->move_backward || keycode == \
cube->player_settings->move_left || keycode == \
cube->player_settings->move_right || keycode == ARROW_LEFT || keycode == \
ARROW_RIGHT)
		manage_player_moves(cube, keycode);
}
