/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:57:12 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/14 21:21:35 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_mouse_in_settings_menu(t_cube *cube, int x, int y)
{
	cube->menu->settings_menu->keybinds_button_status = (\
x > 300 && x < 620 && y > 75 && y < 190);
	cube->menu->settings_menu->video_settings_button_status = (\
x > 800 && x < 1120 && y > 75 && y < 190);
	cube->menu->settings_menu->music_and_sounds_button_status = (\
x > 1300 && x < 1620 && y > 75 && y < 190);
}

void	handle_mouse_in_keybinds_menu(t_cube *cube, int x, int y)
{
	if (x > 671 && x < 719 && y > 392 && y < 440)
		cube->menu->settings_menu->keybinds_define_button_status = 1;
	else if (x > 671 && x < 719 && y > 461 && y < 509)
		cube->menu->settings_menu->keybinds_define_button_status = 2;
	else if (x > 671 && x < 719 && y > 530 && y < 578)
		cube->menu->settings_menu->keybinds_define_button_status = 3;
	else if (x > 671 && x < 719 && y > 599 && y < 647)
		cube->menu->settings_menu->keybinds_define_button_status = 4;
	else if (x > 671 && x < 719 && y > 668 && y < 716)
		cube->menu->settings_menu->keybinds_define_button_status = 5;
	else if (x > 1037 && x < 1188 && y > 395 && y < 440)
		cube->menu->settings_menu->keybinds_define_button_status = 6;
	else if (x > 1037 && x < 1188 && y > 464 && y < 509)
		cube->menu->settings_menu->keybinds_define_button_status = 7;
	else if (x > 1037 && x < 1188 && y > 533 && y < 578)
		cube->menu->settings_menu->keybinds_define_button_status = 8;
	else if (x > 1037 && x < 1188 && y > 602 && y < 647)
		cube->menu->settings_menu->keybinds_define_button_status = 9;
	else if (x > 1037 && x < 1188 && y > 671 && y < 716)
		cube->menu->settings_menu->keybinds_define_button_status = 10;
	else
		cube->menu->settings_menu->keybinds_define_button_status = 0;
	if (cube->menu->settings_menu->keybinds_define_button_status)
		cube->menu->settings_menu->keybind_menu_indice = \
cube->menu->settings_menu->keybinds_define_button_status;
}

void	handle_mouse_in_start_menu(t_cube *cube, int x, int y)
{
	cube->menu->play_button_status = (x > 780 && x < 1135 && \
y > 280 && y < 400);
	cube->menu->settings_button_status = (x > 780 && x < 1135 && \
y > 480 && y < 600);
	cube->menu->exit_button_status = (x > 780 && x < 1135 && \
y > 680 && y < 800);
}

void	handle_mouse_in_game(t_cube *cube, int x, int y)
{
	static int		x_old = 0;

		mlx_mouse_hide();
	if (!x_old)
		x_old = x;
	else if (x == 0)
	{
		mlx_mouse_move(cube->mlx_ptr, cube->window_ptr, WIDTH / 2, HEIGHT / 2);
		x_old = 0;
	}
	else if (x == WIDTH - 1)
	{
		mlx_mouse_move(cube->mlx_ptr, cube->window_ptr, WIDTH / 2, HEIGHT / 2);
		x_old = WIDTH - 1;
	}
	else if (x_old > x)
	{
		double old_dir_x = cube->player_settings->dir_x;
		cube->player_settings->dir_x = cube->player_settings->dir_x * cos(-0.1) - cube->player_settings->dir_y * sin(-0.1);
		cube->player_settings->dir_y = old_dir_x * sin(-0.1) + cube->player_settings->dir_y * cos(-0.1);
		double old_plane_x = cube->player_settings->plane.x;
		cube->player_settings->plane.x = cube->player_settings->plane.x * cos(-0.1) - cube->player_settings->plane.y * sin(-0.1);
		cube->player_settings->plane.y = old_plane_x * sin(-0.1) + cube->player_settings->plane.y * cos(-0.1);
		x_old = x;
	}
	else if (x_old < x)
	{
		double old_dir_x = cube->player_settings->dir_x;
		cube->player_settings->dir_x = cube->player_settings->dir_x * cos(0.1) - cube->player_settings->dir_y * sin(0.1);
		cube->player_settings->dir_y = old_dir_x * sin(0.1) + cube->player_settings->dir_y * cos(0.1);
		double old_plane_x = cube->player_settings->plane.x;
		cube->player_settings->plane.x = cube->player_settings->plane.x * cos(0.1) - cube->player_settings->plane.y * sin(0.1);
		cube->player_settings->plane.y = old_plane_x * sin(0.1) + cube->player_settings->plane.y * cos(0.1);
		x_old = x;
	}
	(void)y;
	mlx_clear_window(cube->mlx_ptr, cube->window_ptr);
	render_cube(cube);
}

#include <stdio.h>
void	fps_counter(void)
{
	static clock_t	last_time = 0;
	static clock_t	last_avg_time = 0;
	static int		frame_count = 0;
	static float	fps_sum = 0.0;
	clock_t			current_time;
	float			fps;
	float			avg_fps;

	current_time = clock();
	fps = CLOCKS_PER_SEC / (float)(current_time - last_time);
	last_time = current_time;
	fps_sum += fps;
	frame_count++;
	if ((current_time - last_avg_time) >= CLOCKS_PER_SEC * 10)
	{
		avg_fps = fps_sum / frame_count;
		printf("\033[1;31mAverage FPS (10s): %.2f\033[0m\n", avg_fps);
		fps_sum = 0.0;
		frame_count = 0;
		last_avg_time = current_time;
	}
	printf("FPS: %.2f\n", fps);
}

int	mouse_move(void *cube_void)
{
	t_cube	*cube;
	int		x;
	int		y;

	cube = (t_cube *)cube_void;
	mlx_mouse_get_pos(cube->mlx_ptr, &x, &y);
	if (cube->menu->is_in_menu)
		handle_mouse_in_start_menu(cube, x, y);
	if (cube->menu->settings_menu->is_in_settings_menu)
		handle_mouse_in_settings_menu(cube, x, y);
	if (cube->menu->settings_menu->is_in_keybinds_menu)
		handle_mouse_in_keybinds_menu(cube, x, y);
	if (cube->is_in_game)
		handle_mouse_in_game(cube, x, y);
	render_hover_button(cube);
	fps_counter();
	return (0);
}
