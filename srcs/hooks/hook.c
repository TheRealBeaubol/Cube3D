/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:44:49 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/03 18:35:22 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	exit_hook(int key, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (key == 0)
		free_destroy_and_exit(cube);
	return (0);
}

int	key_release(int key, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (key <= 256)
		cube->settings.key_tab[key] = 0;
	return (0);
}

void	fps_counter(void)
{
	static t_fps_counter	fps_counter = {0, 0, 0, 0};
	clock_t					current_time;
	float					fps;
	float					avg_fps;

	current_time = clock();
	fps = CLOCKS_PER_SEC / (float)(current_time - fps_counter.last_time);
	fps_counter.last_time = current_time;
	fps_counter.fps_sum += fps;
	fps_counter.frame_count++;
	if ((current_time - fps_counter.last_avg_time) >= CLOCKS_PER_SEC * 10)
	{
		avg_fps = fps_counter.fps_sum / fps_counter.frame_count;
		printf("\033[1;31mAverage FPS (10s): %.2f\033[0m\n", avg_fps);
		fps_counter.fps_sum = 0.0;
		fps_counter.frame_count = 0;
		fps_counter.last_avg_time = current_time;
	}
	// printf("\033[1;32mFPS: %.2f\033[0m\n", fps);
}

void	rotate(t_cube *cube, float angle)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = cube->settings.dir.x;
	cube->settings.dir.x = cube->settings.dir.x * cos(angle) - \
		cube->settings.dir.y * sin(angle);
	cube->settings.dir.y = old_dir_x * sin(angle) + \
		cube->settings.dir.y * cos(angle);
	old_plane_x = cube->settings.plane.x;
	cube->settings.plane.x = cube->settings.plane.x * cos(angle) - \
		cube->settings.plane.y * sin(angle);
	cube->settings.plane.y = old_plane_x * sin(angle) + \
		cube->settings.plane.y * cos(angle);
}

void	handle_key_in_game(t_cube *cube)
{
	double	movespeed;
	float	rotspeed;

	movespeed = 0.1;
	rotspeed = 0.05;
	if (cube->settings.key_tab[cube->settings.move_forward])
		move_forward(cube, movespeed);
	if (cube->settings.key_tab[cube->settings.move_backward])
		move_backward(cube, movespeed);
	if (cube->settings.key_tab[cube->settings.move_left])
		move_left(cube, movespeed);
	if (cube->settings.key_tab[cube->settings.move_right])
		move_right(cube, movespeed);
	if (cube->settings.key_tab[SDL_SCANCODE_LEFT] == 1)
		rotate(cube, -rotspeed);
	if (cube->settings.key_tab[SDL_SCANCODE_RIGHT] == 1)
		rotate(cube, rotspeed);
}

void	handle_mouse_in_game(t_cube *cube, t_int_point pos)
{
	float			rotate_speed;
	t_point			point;

	rotate_speed = 0.005;
	mlx_mouse_hide();
	point.x = (pos.x - WIDTH / 2) * rotate_speed;
	rotate(cube, point.x);
	mlx_mouse_move(cube->mlx.ptr, cube->mlx.win, WIDTH / 2, HEIGHT / 2);
}

int	loop_hook(void *cube_void)
{
	t_cube		*cube;
	t_int_point	pos;

	cube = (t_cube *)cube_void;
	mlx_mouse_get_pos(cube->mlx.ptr, &pos.x, &pos.y);
	if (cube->is_in_menu)
		handle_mouse_in_menu(cube, pos);
	if (cube->is_in_settings)
		handle_mouse_in_settings(cube, pos);
	if (cube->menu.keybinds_menu.status)
		handle_mouse_in_keybinds(cube, pos);
	if (!cube->is_in_game)
		render_buttons(cube);
	if (cube->is_in_game)
	{
		handle_key_in_game(cube);
		handle_mouse_in_game(cube, pos);
		mlx_clear_window(cube->mlx.ptr, cube->mlx.win);
		check_and_do_portal(cube);
		render_cube(cube);
	}
	fps_counter();
	return (0);
}

void	hook(t_cube *cube)
{
	mlx_on_event(cube->mlx.ptr, cube->mlx.win, MLX_WINDOW_EVENT, \
&exit_hook, cube);
	mlx_on_event(cube->mlx.ptr, cube->mlx.win, MLX_KEYDOWN, &key_press, cube);
	mlx_on_event(cube->mlx.ptr, cube->mlx.win, MLX_KEYUP, &key_release, cube);
	mlx_on_event(cube->mlx.ptr, cube->mlx.win, MLX_MOUSEDOWN, \
&mouse_press, cube);
	mlx_loop_hook(cube->mlx.ptr, &loop_hook, cube);
	mlx_loop(cube->mlx.ptr);
}
