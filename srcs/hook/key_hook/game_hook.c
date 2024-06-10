/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:59:02 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/10 19:22:55 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	manage_player_moves(t_cube *cube, int keycode)
{
	//double	old_dir_x;
	//double	old_dir_x;
	double	movespeed;
	//double	rotspeed;
	
	movespeed = 1;
	//rotspeed = 2;
	if (keycode == cube->player_settings->move_forward)
	{
		if (cube->map->map[(int)(cube->player_settings->pos.x + cube->player_settings->dir_x / cube->map->size_case * movespeed)][(int)cube->player_settings->pos.y] != '1')
			cube->player_settings->pos.x += cube->player_settings->dir_x;
		if (cube->map->map[(int)cube->player_settings->pos.x][(int)(cube->player_settings->pos.y + cube->player_settings->dir_y / cube->map->size_case * movespeed)] != '1')
			cube->player_settings->pos.y += cube->player_settings->dir_y;
	}
	if (keycode == cube->player_settings->move_backward)
	{
		if (cube->map->map[(int)(cube->player_settings->pos.x - cube->player_settings->dir_x / cube->map->size_case * movespeed)][(int)cube->player_settings->pos.y] != '1')
			cube->player_settings->pos.x -= cube->player_settings->dir_x;
		if (cube->map->map[(int)cube->player_settings->pos.x][(int)(cube->player_settings->pos.y - cube->player_settings->dir_y / cube->map->size_case * movespeed)] != '1')
			cube->player_settings->pos.y -= cube->player_settings->dir_y;
	}
	if (keycode == cube->player_settings->move_left)
	{
		cube->player_settings->pos.x += cube->player_settings->dir_y;
		cube->player_settings->pos.y -= cube->player_settings->dir_x;
		cube->player_settings->move = 2;
	}
	if (keycode == cube->player_settings->move_right)
	{
		cube->player_settings->pos.x -= cube->player_settings->dir_y;
		cube->player_settings->pos.y += cube->player_settings->dir_x;
		cube->player_settings->move = 3;
	}
	if (keycode == ARROW_RIGHT)
	{
	}
	if (keycode == ARROW_LEFT)
	{
	}
	mlx_clear_window(cube->mlx_ptr, cube->window_ptr);
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
