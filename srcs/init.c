/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:02:00 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/05 22:44:35 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_menu(t_cube *cube)
{
	t_menu	menu;
	int		button_height;
	int		button_width;

	cube->menu = &menu;
	button_height = 50;
	button_width = 200;
	menu.play_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/top_button.png", &button_height, &button_width);
}

void	clear_window(t_cube *cube)
{
	int	x;
	int	y;

	y = -1;
	while (++y != HEIGHT / 2)
	{
		x = -1;
		while (++x != WIDTH)
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, x, y, 0xffffffff);
	}
	y -= 1;
	while (++y != HEIGHT)
	{
		x = -1;
		while (++x != WIDTH)
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, x, y, 0xff666666);
	}
}

void	init(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	if (cube->mlx_ptr == NULL)
		exit (1);
	cube->img = mlx_new_image(cube->mlx_ptr, WIDTH, HEIGHT);
	cube->window_ptr = mlx_new_window(cube->mlx_ptr, WIDTH, HEIGHT, "Cube3D");
	if (cube->window_ptr == NULL)
		free_and_destroy(cube);
	init_menu(cube);
	clear_window(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
		cube->menu->play_button, 100, 100);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->img, 0, 0);
}
