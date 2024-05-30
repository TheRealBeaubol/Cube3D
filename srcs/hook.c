/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:08:52 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/30 15:04:05 by mhervoch         ###   ########.fr       */
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

int	key_hook(int keycode, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (cube->is_in_game)
	{
		if (keycode == cube->player_settings->move_forward || keycode == \
cube->player_settings->move_backward || keycode == cube->player_settings->move_left || \
keycode == cube->player_settings->move_right)
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
			print_map(cube->map_data->map, cube);
		}
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
			if (cube->menu->settings_menu->keybind_menu_indice > 4)
			{
				mlx_clear_window(cube->mlx_ptr, cube->window_ptr);
				cube->menu->is_in_menu = 1;
				cube->menu->settings_menu->waiting_for_key = 0;
				cube->menu->settings_menu->is_in_settings_menu = 0;
				cube->menu->settings_menu->is_in_keybinds_menu = 0;
				mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
			cube->menu->start_background, 0, 0);
				mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
			cube->menu->play_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - \
			cube->menu->button_height) / 2) - 200);
				mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
			cube->menu->settings_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - \
			cube->menu->button_height) / 2));
				mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
			cube->menu->exit_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - \
			cube->menu->button_height) / 2) + 200);
			}
			cube->menu->settings_menu->keybind_menu_indice = 0;
			cube->menu->settings_menu->waiting_for_key = 0;
		}
		else
			cube->menu->settings_menu->waiting_for_key = 0;
	}
	if (keycode == ESCAPE)
		free_and_destroy(cube);
	return (0);
}
