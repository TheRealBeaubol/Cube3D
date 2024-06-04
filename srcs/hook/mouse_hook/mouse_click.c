/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:47:23 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/04 13:55:48 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_mouse_press_in_menu(t_cube *cube, int key)
{
	if (cube->menu->play_button_status && key)
	{
		cube->menu->is_in_menu = 0;
		cube->is_in_game = 1;
		mlx_clear_window(cube->mlx_ptr, cube->window_ptr);
		print_map(cube->map->map, cube);
	}
	if (cube->menu->settings_button_status && key)
	{
		cube->menu->is_in_menu = 0;
		cube->menu->settings_menu->is_in_settings_menu = 1;
		open_settings(cube);
	}
	if (cube->menu->exit_button_status && key)
		free_and_destroy(cube);
}

void	handle_mouse_press_in_settings_menu(t_cube *cube, int key)
{
	if (cube->menu->settings_menu->keybinds_button_status && key)
		open_keybinds_menu(cube);
	if (cube->menu->settings_menu->video_settings_button_status && key)
		open_video_settings_menu(cube);
	if (cube->menu->settings_menu->music_and_sounds_button_status && key)
		open_music_and_sounds_menu(cube);
	if (cube->menu->settings_menu->keybinds_define_button_status && key)
		cube->menu->settings_menu->waiting_for_key = 1;
}

int	mouse_release(int keycode, void *cube_void)
{
	(void)cube_void;
	(void)keycode;
	return (0);
}

int	mouse_press(int key, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (cube->menu->is_in_menu)
		handle_mouse_press_in_menu(cube, key);
	if (cube->menu->settings_menu->is_in_settings_menu)
		handle_mouse_press_in_settings_menu(cube, key);
	return (0);
}
