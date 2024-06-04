/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:59:02 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/04 14:25:07 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	manage_player_moves(t_cube *cube, int keycode)
{
	if (keycode == cube->player_settings->move_forward)
	{
		cube->player_settings->pos.x += cube->player_settings->dir_x;
		cube->player_settings->pos.y += cube->player_settings->dir_y;
	}
	else if (keycode == cube->player_settings->move_backward)
	{
		cube->player_settings->pos.x -= cube->player_settings->dir_x;
		cube->player_settings->pos.y -= cube->player_settings->dir_y;
	}
	else if (keycode == cube->player_settings->move_left)
	{
		cube->player_settings->looking_angle -= 0.1;
		if (cube->player_settings->looking_angle < 0)
			cube->player_settings->looking_angle += 2 * PI;
		cube->player_settings->dir_x = cos(cube->player_settings->looking_angle) * 5;
		cube->player_settings->dir_y = sin(cube->player_settings->looking_angle) * 5;
	}
	else if (keycode == cube->player_settings->move_right)
	{
		cube->player_settings->looking_angle += 0.1;
		if (cube->player_settings->looking_angle > 2 * PI)
			cube->player_settings->looking_angle -= 2 * PI;
		cube->player_settings->dir_x = cos(cube->player_settings->looking_angle) * 5;
		cube->player_settings->dir_y = sin(cube->player_settings->looking_angle) * 5;
	}
	mlx_clear_window(cube->mlx_ptr, cube->window_ptr);
	print_map(cube->map->map, cube);
}

void	handle_game_hook(t_cube *cube, int keycode)
{
	if (keycode == cube->player_settings->move_forward || keycode == \
cube->player_settings->move_backward || keycode == \
cube->player_settings->move_left || keycode == \
cube->player_settings->move_right)
		manage_player_moves(cube, keycode);
}
