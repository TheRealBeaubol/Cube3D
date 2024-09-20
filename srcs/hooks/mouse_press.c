/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 04:52:12 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 20:03:18 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	open_settings(t_cube *cube)
{
	mlx_clear_window(cube->mlx.ptr, cube->mlx.win);
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, \
cube->menu.background, 0, 0);
	cube->menu.keybinds_menu.status = 1;
	cube->menu.keybind_menu_indice = 0;
	cube->menu.waiting_for_key = 0;
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, \
cube->menu.keybinds_menu.img, (WIDTH - \
cube->menu.keybinds_menu.width) / 2, (HEIGHT - \
cube->menu.keybinds_menu.height) / 2);
	put_keys_images(cube, cube->mlx.ptr, cube->mlx.win);
}

void	handle_mouse_press_in_menu(t_cube *cube, int key)
{
	if ((cube->menu.play_button.status || cube->menu.settings_button.status || \
cube->menu.exit_button.status) && key)
	{
		if (system("paplay ./sounds/click.ogg &"))
			printf("Error playing sound\n");
	}
	if (cube->menu.play_button.status && key)
	{
		cube->is_in_menu = 0;
		cube->is_in_game = 1;
		render_cube(cube);
	}
	if (cube->menu.settings_button.status && key)
	{
		cube->is_in_menu = 0;
		cube->is_in_settings = 1;
		open_settings(cube);
	}
	if (cube->menu.exit_button.status && key)
		free_destroy_and_exit(cube);
}

void	handle_mouse_press_in_settings(t_cube *cube, int key)
{
	if (cube->menu.keybinds_define_button.status && key)
	{
		if (system("paplay ./sounds/click.ogg &"))
			printf("Error playing sound\n");
		cube->menu.waiting_for_key = 1;
	}
}

int	mouse_press(int key, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (cube->is_in_menu)
		handle_mouse_press_in_menu(cube, key);
	if (cube->is_in_settings)
		handle_mouse_press_in_settings(cube, key);
	return (0);
}
