/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:08:52 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/23 16:02:53 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	edit_player_settings(t_cube *cube)
{
	if (cube->menu->settings_menu->keybind_menu_indice == 1)
		cube->player_settings->move_forward = cube->menu->settings_menu->key;
	else if (cube->menu->settings_menu->keybind_menu_indice == 2)
		cube->player_settings->move_backward = cube->menu->settings_menu->key;
	else if (cube->menu->settings_menu->keybind_menu_indice == 3)
		cube->player_settings->move_left = cube->menu->settings_menu->key;
	else if (cube->menu->settings_menu->keybind_menu_indice == 4)
		cube->player_settings->move_right = cube->menu->settings_menu->key;
	cube->menu->settings_menu->keybind_menu_indice = 0;
}

int	key_hook(int keycode, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (cube->is_in_game)
	{
		if (keycode == cube->player_settings->move_forward)
			cube->player_settings->dir_y -= 10;
		else if (keycode == cube->player_settings->move_backward)
			cube->player_settings->dir_y += 10;
		else if (keycode == cube->player_settings->move_left)
			cube->player_settings->dir_x -= 10;
		else if (keycode == cube->player_settings->move_right)
			cube->player_settings->dir_x += 10;
		print_map(parsing(cube->map), cube);
	}
	if (cube->menu->settings_menu->waiting_for_key)
	{
		if ((keycode >= 4 && keycode <= 39) || keycode == 43 || keycode == \
44 || (keycode >= 84 && keycode <= 87) || (keycode >= 89 && keycode <= 98) || \
keycode == 224 || keycode == 225)
		{
			cube->menu->settings_menu->key = keycode;
			edit_player_settings(cube);
			open_settings(cube);
			cube->menu->settings_menu->waiting_for_key = 0;
		}
		else
			cube->menu->settings_menu->waiting_for_key = 0;
	}
	if (keycode == ESCAPE)
		free_and_destroy(cube);
	return (0);
}
