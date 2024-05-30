/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:09:50 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/30 14:14:08 by lboiteux         ###   ########.fr       */
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
}

void	handle_settings_hook(t_cube *cube, int keycode)
{
	if ((keycode >= 4 && keycode <= 39) || keycode == 43 || keycode == \
44 || (keycode >= 84 && keycode <= 87) || (keycode >= 89 && keycode <= 98) || \
keycode == 224 || keycode == 225)
	{
		cube->menu->settings_menu->key = keycode;
		edit_player_settings(cube);
		open_settings(cube);
		cube->menu->settings_menu->keybind_menu_indice = 0;
		cube->menu->settings_menu->waiting_for_key = 0;
	}
	else
		cube->menu->settings_menu->waiting_for_key = 0;
}
