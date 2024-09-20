/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:21:32 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 19:53:12 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_hover(void *mlx_ptr, void *win_ptr, t_settings_menu_images \
	img, t_int_point pos)
{
	if (img.status)
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_hover, pos.x, pos.y);
	else
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, pos.x, pos.y);
}

void	render_button_in_menu(t_cube *cube)
{
	render_hover(cube->mlx.ptr, cube->mlx.win, cube->menu.play_button, \
		(t_int_point){(WIDTH - cube->menu.play_button.width) / 2, ((HEIGHT - \
		cube->menu.play_button.height) / 2) - 200});
	render_hover(cube->mlx.ptr, cube->mlx.win, cube->menu.settings_button, \
		(t_int_point){(WIDTH - cube->menu.settings_button.width) / \
		2, ((HEIGHT - cube->menu.settings_button.height) / 2)});
	render_hover(cube->mlx.ptr, cube->mlx.win, cube->menu.exit_button, \
		(t_int_point){(WIDTH - cube->menu.exit_button.width) / 2, ((HEIGHT - \
		cube->menu.exit_button.height) / 2) + 200});
}

void	render_button_in_keybinds(t_cube *cube)
{
	const t_int_point	pos[7] = {{671, 461}, {671, 530}, \
	{671, 599}, {1037, 464}, {1037, 533}, \
	{1037, 602}, {844, 671}};

	if (cube->menu.keybind_menu_indice)
		render_hover(cube->mlx.ptr, cube->mlx.win, \
	cube->menu.keybinds_define_button, pos[cube->menu.keybind_menu_indice - 1]);
}

void	render_buttons(t_cube *cube)
{
	if (cube->is_in_menu)
		render_button_in_menu(cube);
	if (cube->is_in_settings)
	{
		render_button_in_keybinds(cube);
		put_keys_images(cube, cube->mlx.ptr, cube->mlx.win);
	}
}
