/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 04:58:33 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/23 10:48:13 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*get_key_images(t_cube *cube, int key)
{
	int	i;

	i = 0;
	while (i <= 54)
	{
		if (cube->settings.key_map[i].key_value == key)
			return (cube->menu.keys[i].img);
		i++;
	}
	return (NULL);
}

void	put_keys_images(t_cube *cube, void *mlx_ptr, void *mlx_win)
{
	void	*keys_image;

	keys_image = get_key_images(cube, cube->settings.move_forward);
	mlx_put_image_to_window(mlx_ptr, mlx_win, \
keys_image, 671, 392);
	keys_image = get_key_images(cube, cube->settings.move_backward);
	mlx_put_image_to_window(mlx_ptr, mlx_win, \
keys_image, 671, 461);
	keys_image = get_key_images(cube, cube->settings.move_left);
	mlx_put_image_to_window(mlx_ptr, mlx_win, \
keys_image, 671, 530);
	keys_image = get_key_images(cube, cube->settings.move_right);
	mlx_put_image_to_window(mlx_ptr, mlx_win, \
keys_image, 671, 599);
}

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
