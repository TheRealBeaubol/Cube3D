/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:02:00 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/31 15:00:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_settings_file(t_cube *cube)
{
	int	fd;

	(void)cube;
	fd = open("/tmp/settings.txt", O_RDWR, 0644);
	if (fd == -1)
		fd = open("/tmp/settings.txt", O_CREAT | O_RDWR, 0644);
	ft_putstr_fd("[KEYBINDS] :\n\n[VIDEO SETTINGS] \
:\n\n[MUSIC AND SOUNDS] :\n", fd);
	close(fd);
}

t_player_settings	*init_player_settings(void)
{
	t_player_settings	*settings;

	settings = ft_calloc(1, sizeof(t_player_settings));
	settings->move_forward = KEY_W;
	settings->move_backward = KEY_S;
	settings->move_left = KEY_A;
	settings->move_right = KEY_D;
	settings->dir_x = 0;
	settings->dir_y = 0;
	return (settings);
}

/*
 Set the default settings here. Do a fonction to edit the settings with only
 a putstr and a string like up there, just put int value. When reading the
 settings.txt file check if the int value is coherent. If not because 
 someone edited the file -> set error message and redefine the settings.txt file.
*/

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
	cube->map = init_map(cube->map_name);
	cube->is_in_game = 0;
	cube->player_settings = init_player_settings();
	init_settings_file(cube);
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
