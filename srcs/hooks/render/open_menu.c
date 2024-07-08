/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:48:47 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/08 23:41:35 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	open_settings(t_cube *cube)
{
	mlx_clear_window(cube->mlx.ptr, cube->mlx.win);
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, \
cube->menu.background, 0, 0);
	open_keybinds_menu(cube);
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, \
cube->menu.keybinds_button.img, ((WIDTH - cube->menu.keybinds_button.width) / \
2) - cube->menu.keybinds_button.width * 1.25, 70);
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, \
cube->menu.video_settings_button.img, ((WIDTH - \
cube->menu.video_settings_button.width) / 2), 70);
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, \
cube->menu.music_and_sounds_button.img, ((WIDTH - \
cube->menu.music_and_sounds_button.width) / 2 + \
cube->menu.music_and_sounds_button.width * 1.25), 70);
	put_keys_images(cube, cube->mlx.ptr, cube->mlx.win);
}

void	open_keybinds_menu(t_cube *cube)
{
	cube->menu.keybinds_menu.status = 1;
	cube->menu.video_settings_menu.status = 0;
	cube->menu.music_and_sounds_menu.status = 0;
	cube->menu.keybind_menu_indice = 0;
	cube->menu.waiting_for_key = 0;
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, \
cube->menu.keybinds_menu.img, (WIDTH - \
cube->menu.keybinds_menu.width) / 2, (HEIGHT - \
cube->menu.keybinds_menu.height) / 2);
}

void	open_video_settings_menu(t_cube *cube)
{
	cube->menu.keybinds_menu.status = 0;
	cube->menu.video_settings_menu.status = 1;
	cube->menu.music_and_sounds_menu.status = 0;
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, \
cube->menu.video_settings_menu.img, (WIDTH - \
cube->menu.video_settings_menu.width) / 2, (HEIGHT - \
cube->menu.video_settings_menu.height) / 2);
}

void	open_music_and_sounds_menu(t_cube *cube)
{
	cube->menu.keybinds_menu.status = 0;
	cube->menu.video_settings_menu.status = 0;
	cube->menu.music_and_sounds_menu.status = 1;
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, \
cube->menu.music_and_sounds_menu.img, (WIDTH - \
cube->menu.music_and_sounds_menu.width) / 2, (HEIGHT - \
cube->menu.music_and_sounds_menu.height) / 2);
}
