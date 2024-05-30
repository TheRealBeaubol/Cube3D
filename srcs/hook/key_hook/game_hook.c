/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:59:02 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/30 14:02:31 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	manage_player_moves(t_cube *cube, int keycode)
{
	if (keycode == cube->player_settings->move_forward)
		cube->player_settings->dir_y -= 2;
	else if (keycode == cube->player_settings->move_backward)
		cube->player_settings->dir_y += 2;
	else if (keycode == cube->player_settings->move_left)
		cube->player_settings->dir_x -= 2;
	else if (keycode == cube->player_settings->move_right)
		cube->player_settings->dir_x += 2;
	mlx_clear_window(cube->mlx_ptr, cube->window_ptr);
	print_map(parsing(cube->map), cube);
}

void	handle_game_hook(t_cube *cube, int keycode)
{
	if (keycode == cube->player_settings->move_forward || keycode == \
cube->player_settings->move_backward || keycode == \
cube->player_settings->move_left || keycode == \
cube->player_settings->move_right)
		manage_player_moves(cube, keycode);
}
