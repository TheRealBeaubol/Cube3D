/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:05:36 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/24 22:45:36 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_player_settings(t_cube *cube)
{
	init_player_binds(&cube->settings);
	cube->settings.dir.x = 0;
	cube->settings.dir.y = -1;
	cube->settings.plane.x = 0.66;
	cube->settings.plane.y = 0;
	ft_bzero(cube->settings.key_tab, 256);
}

void	init_player(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map.map[i])
	{
		j = 0;
		while (cube->map.map[i][j])
		{
			if (!is_player(cube->map.map[i][j]))
			{
				cube->settings.pos.x = i + 0.5;
				cube->settings.pos.y = j + 0.5;
				cube->map.map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_mlx(t_cube *cube)
{
	cube->mlx.ptr = mlx_init();
	if (cube->mlx.ptr == NULL)
		free_init_and_exit (cube, "Error\n", 0);
	cube->mlx.win = mlx_new_window(cube->mlx.ptr, WIDTH, HEIGHT, "Cube3D");
	if (cube->mlx.win == NULL)
		free_init_and_exit (cube, "Error\n", 1);
	cube->mlx.background_img = mlx_new_image(cube->mlx.ptr, WIDTH, HEIGHT);
	draw_background(cube->mlx.ptr, cube->mlx.background_img, \
cube->map.ceiling_color, cube->map.floor_color);
}

void	start_game(t_cube *cube, void *mlx_ptr, void *win_ptr)
{
	cube->is_in_menu = 1;
	cube->is_in_game = 0;
	cube->is_in_settings = 0;
	cube->menu.waiting_for_key = 0;
	cube->menu.background = mlx_png_file_to_image(cube->mlx.ptr, \
"./images/background.png", NULL, NULL);
	mlx_put_image_to_window(mlx_ptr, win_ptr, cube->menu.background, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, \
cube->menu.play_button.img, (WIDTH - cube->menu.play_button.width) / \
2, ((HEIGHT - cube->menu.play_button.height) / 2) - 200);
	mlx_put_image_to_window(mlx_ptr, win_ptr, \
cube->menu.settings_button.img, (WIDTH - cube->menu.settings_button.width) / \
2, ((HEIGHT - cube->menu.settings_button.height) / 2));
	mlx_put_image_to_window(mlx_ptr, win_ptr, \
cube->menu.exit_button.img, (WIDTH - cube->menu.exit_button.width) / \
2, ((HEIGHT - cube->menu.exit_button.height) / 2) + 200);
}

void	init(t_cube *cube)
{
	init_settings_file();
	init_key_map(cube);
	init_player_settings(cube);
	init_player(cube);
	init_mlx(cube);
	preload_textures(cube);
	init_images(cube->mlx.ptr, &cube->menu);
	start_game(cube, cube->mlx.ptr, cube->mlx.win);
}