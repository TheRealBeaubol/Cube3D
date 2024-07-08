/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 04:52:12 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/09 00:14:15 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_mouse_press_in_menu(t_cube *cube, int key)
{
	if (cube->menu.play_button.status && key)
	{
		cube->is_in_menu = 0;
		cube->is_in_game = 1;
		render_cube(cube);
	}
	if (cube->menu.settings_button.status && key)
	{
		cube->is_in_menu = 0;
		cube->is_in_settings = 1;
		open_settings(cube);
	}
	if (cube->menu.exit_button.status && key)
		free_destroy_and_exit(cube);
}

void	handle_mouse_press_in_settings(t_cube *cube, int key)
{
	if (cube->menu.keybinds_button.status && key)
		open_keybinds_menu(cube);
	if (cube->menu.video_settings_button.status && key)
		open_video_settings_menu(cube);
	if (cube->menu.music_and_sounds_button.status && key)
		open_music_and_sounds_menu(cube);
	if (cube->menu.keybinds_define_button.status && key)
		cube->menu.waiting_for_key = 1;
}

int	mouse_press(int key, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (cube->is_in_menu)
		handle_mouse_press_in_menu(cube, key);
	if (cube->is_in_settings)
		handle_mouse_press_in_settings(cube, key);
	return (0);
}
