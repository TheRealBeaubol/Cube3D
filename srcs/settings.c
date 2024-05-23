/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:04:57 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/23 16:20:20 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_keys_images(t_cube *cube)
{
	void	*keys_image;

	keys_image = get_key_images(cube, cube->player_settings->move_forward);
	if (!keys_image)
		exit(1);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
keys_image, 671, 392);
	keys_image = get_key_images(cube, cube->player_settings->move_backward);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
keys_image, 671, 461);
	keys_image = get_key_images(cube, cube->player_settings->move_left);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
keys_image, 671, 530);
	keys_image = get_key_images(cube, cube->player_settings->move_right);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
keys_image, 671, 599);
}

void	open_settings(t_cube *cube)
{
	mlx_clear_window(cube->mlx_ptr, cube->window_ptr);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->start_background, 0, 0);
	open_keybinds_menu(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_button, ((WIDTH - \
cube->menu->settings_menu->button_width) / 2) - \
cube->menu->settings_menu->button_width * 1.25, 70);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->video_settings_button, (WIDTH - \
cube->menu->settings_menu->button_width) / 2, 70);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->music_and_sounds_button, ((WIDTH - \
cube->menu->settings_menu->button_width) / 2) + \
cube->menu->settings_menu->button_width * 1.25, 70);
	put_keys_images(cube);
}

void	open_video_settings_menu(t_cube *cube)
{
	cube->menu->settings_menu->is_in_keybinds_menu = 0;
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->video_settings_menu, (WIDTH - \
cube->menu->settings_menu->settings_menu_width) / 2, (HEIGHT - \
cube->menu->settings_menu->settings_menu_height) / 2);
}

void	open_keybinds_menu(t_cube *cube)
{
	cube->menu->settings_menu->is_in_keybinds_menu = 1;
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
	cube->menu->settings_menu->keybinds_menu, (WIDTH - \
	cube->menu->settings_menu->settings_menu_width) / 2, (HEIGHT - \
	cube->menu->settings_menu->settings_menu_height) / 2);
}

void	open_music_and_sounds_menu(t_cube *cube)
{
	cube->menu->settings_menu->is_in_keybinds_menu = 0;
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
	cube->menu->settings_menu->music_and_sounds_menu, (WIDTH - \
	cube->menu->settings_menu->settings_menu_width) / 2, (HEIGHT - \
	cube->menu->settings_menu->settings_menu_height) / 2);
}
