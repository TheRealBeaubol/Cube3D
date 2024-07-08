/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:15:35 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/09 00:29:07 by lboiteux         ###   ########.fr       */
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
	if (cube->menu.keybind_menu_indice == 5)
		cube->settings.sprint = key;
	if (cube->menu.keybind_menu_indice == 6)
		cube->settings.show_map = key;
	if (cube->menu.keybind_menu_indice == 7)
		cube->settings.show_fps = key;
	printf("cube->menu.keybind_menu_indice = %d\n", cube->menu.keybind_menu_indice);
}

void	handle_settings_hook(t_cube *cube, int key)
{
	if ((key >= 4 && key <= 39) || key == 43 || key == \
44 || (key >= 84 && key <= 87) || (key >= 89 && key <= 98) || \
key == 224 || key == 225)
	{
		edit_player_settings(cube, key);
		edit_settings_file(cube);
		open_settings(cube);
		cube->menu.keybind_menu_indice = 0;
	}
	cube->menu.waiting_for_key = 0;
}

void	open_in_game_settings(t_cube *cube, void *mlx_ptr, void *win_ptr)
{
	mlx_mouse_show();
	mlx_clear_window(mlx_ptr, win_ptr);
	start_game(cube, mlx_ptr, win_ptr);
}

void	handle_game_hook(t_cube *cube, int key)
{
	if (key == SDL_SCANCODE_ESCAPE)
		open_in_game_settings(cube, cube->mlx.ptr, cube->mlx.win);
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
	printf("cube->is_in_menu = %d\n", cube->is_in_menu);
	printf("cube->is_in_game = %d\n", cube->is_in_game);
	printf("cube->is_in_settings = %d\n", cube->is_in_settings);
	printf("=====================================\n");
	if (cube->is_in_menu)
	{
		if (key == SDL_SCANCODE_ESCAPE)
			free_destroy_and_exit(cube);
	}
	if (cube->is_in_settings)
	{
		if (key == SDL_SCANCODE_ESCAPE)
		{
			mlx_clear_window(cube->mlx.ptr, cube->mlx.win);
			cube->menu.keybinds_menu.status = 0;
			cube->menu.video_settings_menu.status = 0;
			cube->menu.music_and_sounds_menu.status = 0;
			start_game(cube, cube->mlx.ptr, cube->mlx.win);
		}
		if (cube->menu.waiting_for_key)
			handle_settings_hook(cube, key);
	}
	if (cube->is_in_game)
		handle_game_hook(cube, key);
	return (0);
}
