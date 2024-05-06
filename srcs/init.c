/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:02:00 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/06 21:23:54 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_menu	*init_menu(t_cube *cube)
{
	t_menu	*menu;

	menu = ft_calloc(1, sizeof(t_menu));
	menu->start_background = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/start_background.png", NULL, NULL);
	menu->play_button = mlx_png_file_to_image(cube->mlx_ptr, \
"images/play_button.png", &(menu->button_width), &(menu->button_height));
	menu->options_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/options_button.png", NULL, NULL);
	menu->exit_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/exit_button.png", NULL, NULL);
	menu->play_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/play_button_hover.png", NULL, NULL);
	menu->options_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/options_button_hover.png", NULL, NULL);
	menu->exit_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/exit_button_hover.png", NULL, NULL);
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
	cube->menu->is_in_menu = 0;
	cube->menu->play_button_status = 0;
	cube->menu->options_button_status = 0;
	cube->menu->exit_button_status = 0;
	// clear_window(cube);
	// mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->img, 0, 0);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->start_background, 0, 0);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->play_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) - 200);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->options_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2));
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->exit_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) + 200);
}
