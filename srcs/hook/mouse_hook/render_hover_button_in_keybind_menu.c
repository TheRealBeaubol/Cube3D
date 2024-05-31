/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hover_button_in_settings_menu.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:18:17 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/30 15:19:43 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_hover_button_in_keybind_menu_part_three(t_cube *cube)
{
	if (cube->menu->settings_menu->keybinds_define_button_status == 9)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button_hover, 1037, 602);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button, 1037, 602);
	if (cube->menu->settings_menu->keybinds_define_button_status == 10)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button_hover, 1037, 671);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button, 1037, 671);
}

void	render_hover_button_in_keybind_menu_part_two(t_cube *cube)
{
	if (cube->menu->settings_menu->keybinds_define_button_status == 5)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button_hover, 671, 668);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button, 671, 668);
	if (cube->menu->settings_menu->keybinds_define_button_status == 6)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button_hover, 1037, 395);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button, 1037, 395);
	if (cube->menu->settings_menu->keybinds_define_button_status == 7)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button_hover, 1037, 464);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button, 1037, 464);
	if (cube->menu->settings_menu->keybinds_define_button_status == 8)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button_hover, 1037, 533);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button, 1037, 533);
}

void	render_hover_button_in_keybind_menu_part_one(t_cube *cube)
{
	if (cube->menu->settings_menu->keybinds_define_button_status == 1)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button_hover, 671, 392);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button, 671, 392);
	if (cube->menu->settings_menu->keybinds_define_button_status == 2)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button_hover, 671, 461);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button, 671, 461);
	if (cube->menu->settings_menu->keybinds_define_button_status == 3)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button_hover, 671, 530);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button, 671, 530);
	if (cube->menu->settings_menu->keybinds_define_button_status == 4)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button_hover, 671, 599);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_define_button, 671, 599);
}

void	render_key_images(t_cube *cube)
{
	void	*keys_image;

	keys_image = get_key_images(cube, cube->player_settings->move_forward);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
keys_image, 671, 392);
	keys_image = get_key_images(cube, cube->player_settings->move_backward);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
keys_image, 671, 461);
	keys_image = get_key_images(cube, cube->player_settings->move_left);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
keys_image, 671, 530);
	keys_image = get_key_images(cube, cube->player_settings->move_right);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
keys_image, 671, 599);
}
