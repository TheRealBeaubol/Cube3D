/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:08:52 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/18 19:04:36 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	manage_player_moves(t_cube *cube, int keycode)
{
	if (keycode <= 256)
		cube->player_settings->key_tab[keycode] = 1;
}

static void	handle_game_hook(t_cube *cube, int keycode)
{
	if (keycode == cube->player_settings->move_forward || keycode == \
cube->player_settings->move_backward || keycode == \
cube->player_settings->move_left || keycode == \
cube->player_settings->move_right || keycode == ARROW_LEFT || keycode == \
ARROW_RIGHT)
		manage_player_moves(cube, keycode);
}

int	key_hook(int keycode, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (cube->is_in_game)
		handle_game_hook(cube, keycode);
	if (cube->menu->settings_menu->waiting_for_key)
		handle_settings_hook(cube, keycode);
	if (keycode == ESCAPE)
		free_and_destroy(cube);
	return (0);
}

int	key_release(int keycode, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (keycode <= 256)
		cube->player_settings->key_tab[keycode] = 0;
	return (0);
}
