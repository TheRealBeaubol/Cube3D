/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:57:12 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/12 23:42:04 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_hover_button(t_cube *cube)
{
	if (cube->menu->is_in_menu)
	{
		if (cube->menu->play_button_status)
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->play_button_hover, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) - 200);
		else
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->play_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) - 200);
		if (cube->menu->settings_button_status)
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_button_hover, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2));
		else
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2));
		if (cube->menu->exit_button_status)
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->exit_button_hover, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) + 200);
		else
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->exit_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) + 200);
	}
	if (cube->menu->settings_menu->is_in_settings_menu)
	{
		if (cube->menu->settings_menu->keybinds_button_status)
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_menu->keybinds_button_hover, ((WIDTH - cube->menu->settings_menu->button_width) / 2) - cube->menu->settings_menu->button_width * 1.25, 70);
		else
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_menu->keybinds_button, ((WIDTH - cube->menu->settings_menu->button_width) / 2) - cube->menu->settings_menu->button_width * 1.25, 70);
		if (cube->menu->settings_menu->video_settings_button_status)
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_menu->video_settings_button_hover, (WIDTH - cube->menu->settings_menu->button_width) / 2, 70);
		else
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_menu->video_settings_button, (WIDTH - cube->menu->settings_menu->button_width) / 2, 70);
		if (cube->menu->settings_menu->music_and_sounds_button_status)
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_menu->music_and_sounds_button_hover, ((WIDTH - cube->menu->settings_menu->button_width) / 2) +  cube->menu->settings_menu->button_width * 1.25, 70);
		else
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_menu->music_and_sounds_button, ((WIDTH - cube->menu->settings_menu->button_width) / 2) +  cube->menu->settings_menu->button_width * 1.25, 70);
	}
}

void	handle_mouse_in_start_menu(t_cube *cube, int x, int y)
{
	if (cube->menu->is_in_menu)
	{
		if (x > 780 && x < 1135 && y > 280 && y < 400)
			cube->menu->play_button_status = 1;
		else
			cube->menu->play_button_status = 0;
		if (x > 780 && x < 1135 && y > 480 && y < 600)
			cube->menu->settings_button_status = 1;
		else
			cube->menu->settings_button_status = 0;
		if (x > 780 && x < 1135 && y > 680 && y < 800)
			cube->menu->exit_button_status = 1;
		else
			cube->menu->exit_button_status = 0;
		render_hover_button(cube);
	}
	if (cube->menu->settings_menu->is_in_settings_menu)
	{
		if (x > 300 && x < 620 && y > 75 && y < 190)
			cube->menu->settings_menu->keybinds_button_status = 1;
		else
			cube->menu->settings_menu->keybinds_button_status = 0;
		if (x > 800 && x < 1120 && y > 75 && y < 190)
			cube->menu->settings_menu->video_settings_button_status = 1;
		else
			cube->menu->settings_menu->video_settings_button_status = 0;
		if (x > 1300 && x < 1620 && y > 75 && y < 190)
			cube->menu->settings_menu->music_and_sounds_button_status = 1;
		else
			cube->menu->settings_menu->music_and_sounds_button_status = 0;
		render_hover_button(cube);
	}
}

int	mouse_release(int keycode, void *cube_void)
{
	(void)cube_void;
	(void)keycode;
	return (0);
}

int	mouse_press(int keycode, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (cube->menu->is_in_menu)
	{
		if (cube->menu->play_button_status && keycode)
		{
			cube->menu->is_in_menu = 0;
			mlx_clear_window(cube->mlx_ptr, cube->window_ptr);
		}
		if (cube->menu->settings_button_status && keycode)
		{
			cube->menu->is_in_menu = 0;
			cube->menu->settings_menu->is_in_settings_menu = 1;
			open_settings(cube);
		}
		if (cube->menu->exit_button_status && keycode)
			free_and_destroy(cube);
	}
	if (cube->menu->settings_menu->is_in_settings_menu)
	{
		if (cube->menu->settings_menu->keybinds_button_status && keycode)
			ft_printf("keybinds\n");
		if (cube->menu->settings_menu->video_settings_button_status && keycode)
			ft_printf("video settings\n");
		if (cube->menu->settings_menu->music_and_sounds_button_status && keycode)
			ft_printf("music and sounds\n");
	}
	return (0);

}

int	mouse_move(void *cube_void)
{
	t_cube	*cube;
	int		x;
	int		y;

	cube = (t_cube *)cube_void;
	mlx_mouse_get_pos(cube->mlx_ptr, &x, &y);
	handle_mouse_in_start_menu(cube, x, y);
	return (0);
}
