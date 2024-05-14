/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:02:00 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/14 16:07:29 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_settings_menu	*init_settings_menu(t_cube *cube)
{
	t_settings_menu	*settings_menu;

	settings_menu = ft_calloc(1, sizeof(t_settings_menu));
	settings_menu->keybinds_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/keybinds_button.png", &(settings_menu->button_width), &(settings_menu->button_height));
	settings_menu->keybinds_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/keybinds_button_hover.png", NULL, NULL);
	settings_menu->video_settings_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/video_settings_button.png", NULL, NULL);
	settings_menu->video_settings_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/video_settings_button_hover.png", NULL, NULL);
	settings_menu->music_and_sounds_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/music_and_sounds_button.png", NULL, NULL);
	settings_menu->music_and_sounds_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/music_and_sounds_button_hover.png", NULL, NULL);
	settings_menu->keybinds_menu = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/keybinds_menu.png", &(settings_menu->settings_menu_width), &(settings_menu->settings_menu_height));
	settings_menu->video_settings_menu = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/video_settings_menu.png", NULL, NULL);
	settings_menu->music_and_sounds_menu = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/music_and_sounds_menu.png", NULL, NULL);
	return (settings_menu);
}
// settings_menu->back_button = mlx_png_file_to_image(cube->mlx_ptr, 
// 	"images/back_button.png", NULL, NULL);
// settings_menu->back_button_hover = mlx_png_file_to_image(cube->mlx_ptr, 
// 	"images/back_button_hover.png", NULL, NULL);

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
	return (menu);
}

void	clear_window(t_cube *cube)
{
	int	x;
	int	y;

	y = -1;
	while (++y != HEIGHT)
	{
		x = -1;
		while (++x != WIDTH)
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, x, y, 0xffe19239);
	}
}

void	init_settings_file(t_cube *cube)
{
	int	fd;

	(void)cube;
	fd = open("/tmp/settings.txt", O_RDWR, 0644);
	if (fd == -1)
		fd = open("/tmp/settings.txt", O_CREAT | O_RDWR, 0644);
	ft_putstr_fd("[KEYBINDS] :\n\n[VIDEO SETTINGS] :\n\n[MUSIC AND SOUNDS] :\n", fd);
	close(fd);
}

// Set the default settings here, 
// Do a fonction to edit the settings with only a putstr and a string like up there, just put int value. 
// When reading the settings.txt file check if the int value is coherent.
// If not because someone edited the file -> set error message and redefine the settings.txt file.
void	init(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	if (cube->mlx_ptr == NULL)
		exit (1);
	cube->img = mlx_new_image(cube->mlx_ptr, WIDTH, HEIGHT);
	cube->window_ptr = mlx_new_window(cube->mlx_ptr, WIDTH, HEIGHT, "Cube3D");
	if (cube->window_ptr == NULL)
		free_and_destroy(cube);
	cube->menu = init_menu(cube);
	cube->menu->is_in_menu = 1;
	cube->menu->play_button_status = 0;
	cube->menu->settings_button_status = 0;
	cube->menu->exit_button_status = 0;
	init_settings_file(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->start_background, 0, 0);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->play_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) - 200);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2));
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->exit_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) + 200);
}
