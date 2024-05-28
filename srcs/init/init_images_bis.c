/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:00:13 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/18 02:02:11 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_settings_menu_button(t_cube *cube, t_settings_menu *settings_menu)
{
	settings_menu->keybinds_button = mlx_png_file_to_image(cube->mlx_ptr, \
"images/keybinds_button.png", &(settings_menu->button_width), \
&(settings_menu->button_height));
	settings_menu->keybinds_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/keybinds_button_hover.png", NULL, NULL);
	settings_menu->video_settings_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/video_settings_button.png", NULL, NULL);
	settings_menu->video_settings_button_hover = mlx_png_file_to_image(\
cube->mlx_ptr, "images/video_settings_button_hover.png", NULL, NULL);
	settings_menu->music_and_sounds_button = mlx_png_file_to_image(\
cube->mlx_ptr, "images/music_and_sounds_button.png", NULL, NULL);
	settings_menu->music_and_sounds_button_hover = mlx_png_file_to_image(\
cube->mlx_ptr, "images/music_and_sounds_button_hover.png", NULL, NULL);
	settings_menu->keybinds_define_button = mlx_png_file_to_image(\
cube->mlx_ptr, "images/keybinds_define_button.png", NULL, NULL);
	settings_menu->keybinds_define_button_hover = mlx_png_file_to_image(\
cube->mlx_ptr, "images/keybinds_define_button_hover.png", NULL, NULL);
}

// settings_menu->back_button = mlx_png_file_to_image(cube->mlx_ptr, 
// 	"images/back_button.png", NULL, NULL);
// settings_menu->back_button_hover = mlx_png_file_to_image(cube->mlx_ptr, 
// 	"images/back_button_hover.png", NULL, NULL);

t_settings_menu	*init_settings_menu(t_cube *cube)
{
	t_settings_menu	*settings_menu;

	settings_menu = ft_calloc(1, sizeof(t_settings_menu));
	settings_menu->waiting_for_key = 0;
	init_settings_menu_button(cube, settings_menu);
	settings_menu->keybinds_menu = mlx_png_file_to_image(cube->mlx_ptr, \
"images/keybinds_menu.png", &(settings_menu->settings_menu_width), \
&(settings_menu->settings_menu_height));
	settings_menu->video_settings_menu = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/video_settings_menu.png", NULL, NULL);
	settings_menu->music_and_sounds_menu = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/music_and_sounds_menu.png", NULL, NULL);
	return (settings_menu);
}

t_menu	*init_menu(t_cube *cube)
{
	t_menu	*menu;

	menu = ft_calloc(1, sizeof(t_menu));
	menu->start_background = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/start_background.png", NULL, NULL);
	menu->play_button = mlx_png_file_to_image(cube->mlx_ptr, \
"images/play_button.png", &(menu->button_width), &(menu->button_height));
	menu->settings_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/settings_button.png", NULL, NULL);
	menu->exit_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/exit_button.png", NULL, NULL);
	menu->play_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/play_button_hover.png", NULL, NULL);
	menu->settings_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/settings_button_hover.png", NULL, NULL);
	menu->exit_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/exit_button_hover.png", NULL, NULL);
	menu->settings_menu = init_settings_menu(cube);
	menu->settings_menu->keys_images = init_keys_images(cube);
	return (menu);
}
