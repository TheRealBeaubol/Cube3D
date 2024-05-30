/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hover_button.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:57:04 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/30 15:23:55 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_hover_button_in_menu(t_cube *cube)
{
	if (cube->menu->play_button_status)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->play_button_hover, (WIDTH - cube->menu->button_width) / \
2, ((HEIGHT - cube->menu->button_height) / 2) - 200);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->play_button, (WIDTH - cube->menu->button_width) / \
2, ((HEIGHT - cube->menu->button_height) / 2) - 200);
	if (cube->menu->settings_button_status)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_button_hover, (WIDTH - cube->menu->button_width) / \
2, ((HEIGHT - cube->menu->button_height) / 2));
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_button, (WIDTH - cube->menu->button_width) / \
2, ((HEIGHT - cube->menu->button_height) / 2));
	if (cube->menu->exit_button_status)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->exit_button_hover, (WIDTH - cube->menu->button_width) / \
2, ((HEIGHT - cube->menu->button_height) / 2) + 200);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->exit_button, (WIDTH - cube->menu->button_width) / \
2, ((HEIGHT - cube->menu->button_height) / 2) + 200);
}

void	render_hover_button_in_settings_menu_next(t_cube *cube)
{
	if (cube->menu->settings_menu->music_and_sounds_button_status)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->music_and_sounds_button_hover, ((WIDTH - \
cube->menu->settings_menu->button_width) / 2) + \
cube->menu->settings_menu->button_width * 1.25, 70);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->music_and_sounds_button, ((WIDTH - \
cube->menu->settings_menu->button_width) / 2) + \
cube->menu->settings_menu->button_width * 1.25, 70);
}

void	render_hover_button_in_settings_menu(t_cube *cube)
{
	if (cube->menu->settings_menu->keybinds_button_status)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_button_hover, ((WIDTH - \
cube->menu->settings_menu->button_width) / 2) - \
cube->menu->settings_menu->button_width * 1.25, 70);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_button, ((WIDTH - \
cube->menu->settings_menu->button_width) / 2) - \
cube->menu->settings_menu->button_width * 1.25, 70);
	if (cube->menu->settings_menu->video_settings_button_status)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->video_settings_button_hover, (WIDTH - \
cube->menu->settings_menu->button_width) / 2, 70);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->video_settings_button, (WIDTH - \
cube->menu->settings_menu->button_width) / 2, 70);
	render_hover_button_in_settings_menu_next(cube);
}

void	render_hover_button(t_cube *cube)
{
	if (cube->menu->is_in_menu)
		render_hover_button_in_menu(cube);
	if (cube->menu->settings_menu->is_in_settings_menu)
		render_hover_button_in_settings_menu(cube);
	if (cube->menu->settings_menu->is_in_keybinds_menu)
	{
		render_hover_button_in_keybind_menu_part_one(cube);
		render_hover_button_in_keybind_menu_part_two(cube);
		render_hover_button_in_keybind_menu_part_three(cube);
		render_key_images(cube);
	}
}
