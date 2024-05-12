/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:04:57 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/12 23:29:42 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	open_settings(t_cube *cube)
{
	mlx_clear_window(cube->mlx_ptr, cube->window_ptr);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->start_background, 0, 0);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_menu->keybinds_button, ((WIDTH - cube->menu->settings_menu->button_width) / 2) - cube->menu->settings_menu->button_width * 1.25, 70);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_menu->video_settings_button, (WIDTH - cube->menu->settings_menu->button_width) / 2, 70);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_menu->music_and_sounds_button, ((WIDTH - cube->menu->settings_menu->button_width) / 2) +  cube->menu->settings_menu->button_width * 1.25, 70);
}