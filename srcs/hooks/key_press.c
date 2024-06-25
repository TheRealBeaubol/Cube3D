/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:15:35 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/25 12:19:34 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	edit_player_settings(t_cube *cube, int key)
{
	if (cube->menu.keybind_menu_indice == 1)
		cube->settings.move_forward = key;
	if (cube->menu.keybind_menu_indice == 2)
		cube->settings.move_backward = key;
	if (cube->menu.keybind_menu_indice == 3)
		cube->settings.move_left = key;
	if (cube->menu.keybind_menu_indice == 4)
		cube->settings.move_right = key;
}

void	handle_settings_hook(t_cube *cube, int key)
{
	if ((key >= 4 && key <= 39) || key == 43 || key == \
44 || (key >= 84 && key <= 87) || (key >= 89 && key <= 98) || \
key == 224 || key == 225)
	{
		edit_player_settings(cube, key);
		open_settings(cube);
		cube->menu.keybind_menu_indice = 0;
	}
	cube->menu.waiting_for_key = 0;
}

void	handle_game_hook(t_cube *cube, int key)
{
	if (key == cube->settings.move_forward || \
key == cube->settings.move_backward || key == cube->settings.move_left || \
key == cube->settings.move_right || key == \
SDL_SCANCODE_LEFT || key == SDL_SCANCODE_RIGHT)
		cube->settings.key_tab[key] = 1;
}

int	key_press(int key, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (cube->is_in_game)
		handle_game_hook(cube, key);
	if (cube->menu.waiting_for_key)
		handle_settings_hook(cube, key);
	if (key == SDL_SCANCODE_ESCAPE)
		free_destroy_and_exit(cube);
	return (0);
}
