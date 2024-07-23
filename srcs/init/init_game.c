/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:05:36 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/23 15:23:04 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_mlx(t_cube *cube)
{
	cube->mlx.ptr = mlx_init();
	if (cube->mlx.ptr == NULL)
		free_init_and_exit (cube, "Error\n", 0);
	cube->mlx.win = mlx_new_window(cube->mlx.ptr, WIDTH, HEIGHT, "Cube3D");
	if (cube->mlx.win == NULL)
		free_init_and_exit (cube, "Error\n", 1);
	cube->mlx.background_img = mlx_new_image(cube->mlx.ptr, WIDTH, HEIGHT);
	draw_first_background(cube);
}

void	start_game(t_cube *cube, void *mlx_ptr, void *win_ptr)
{
	cube->is_in_menu = 1;
	cube->is_in_game = 0;
	cube->is_in_settings = 0;
	cube->menu.waiting_for_key = 0;
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

void	print_key_tab(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		printf("cube->settings.key_tab[%d] = %d\n", i, cube->settings.key_tab[i]);
		i++;
	}
}

void	init(t_cube *cube)
{
	int	i;

	init_settings_file();
	init_key_map(cube);
	init_player_binds(&cube->settings);
	init_portal(cube);
	i = -1;
	while (++i < 256)
		cube->settings.key_tab[i] = 0;
	init_mlx(cube);
	printf("\033[1;32mPreloading textures...\033[0m\n");
	preload_textures(cube);
	init_images(cube->mlx.ptr, &cube->menu);
	printf("\033[1;32mStarting game...\033[0m\n");
	start_game(cube, cube->mlx.ptr, cube->mlx.win);
}
