/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:44:49 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/25 12:47:49 by lboiteux         ###   ########.fr       */
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

void	move(t_cube *cube)
{
	double	old_dir_x;
	double	old_plane_x;
	double	movespeed;
	float	rotspeed;

	movespeed = 0.05;
	rotspeed = 0.1;
	if (cube->settings.key_tab[cube->settings.move_forward])
	{
		if (cube->map.map[(int)cube->settings.pos.y] \
	[(int)(cube->settings.pos.x + cube->settings.dir.x * movespeed)] != '1')
			cube->settings.pos.x += cube->settings.dir.x * movespeed;
		if (cube->map.map[(int)(cube->settings.pos.y + \
	cube->settings.dir.y * movespeed)][(int)cube->settings.pos.x] != '1')
			cube->settings.pos.y += cube->settings.dir.y * movespeed;
	}
	if (cube->settings.key_tab[cube->settings.move_backward])
	{
		if (cube->map.map[(int)cube->settings.pos.y] \
	[(int)(cube->settings.pos.x - cube->settings.dir.x * movespeed)] != '1')
			cube->settings.pos.x -= cube->settings.dir.x * movespeed;
		if (cube->map.map[(int)(cube->settings.pos.y - \
	cube->settings.dir.y * movespeed)][(int)cube->settings.pos.x] != '1')
			cube->settings.pos.y -= cube->settings.dir.y * movespeed;
	}
	if (cube->settings.key_tab[cube->settings.move_left])
	{
		if (cube->map.map[(int)(cube->settings.pos.y + \
	cube->settings.dir.x * movespeed)][(int)cube->settings.pos.x] != '1')
			cube->settings.pos.y -= cube->settings.dir.x * movespeed;
		if (cube->map.map[(int)cube->settings.pos.y] \
	[(int)(cube->settings.pos.x - cube->settings.dir.y * movespeed)] != '1')
			cube->settings.pos.x += cube->settings.dir.y * movespeed;
	}
	if (cube->settings.key_tab[cube->settings.move_right])
	{
		if (cube->map.map[(int)(cube->settings.pos.y - \
	cube->settings.dir.x * movespeed)][(int)cube->settings.pos.x] != '1')
			cube->settings.pos.y += cube->settings.dir.x * movespeed;
		if (cube->map.map[(int)cube->settings.pos.y] \
	[(int)(cube->settings.pos.x + cube->settings.dir.y * movespeed)] != '1')
			cube->settings.pos.x -= cube->settings.dir.y * movespeed;
	}
	if (cube->settings.key_tab[SDL_SCANCODE_LEFT])
	{
		old_dir_x = cube->settings.dir.x;
		cube->settings.dir.x = cube->settings.dir.x * cos(-rotspeed) - \
	cube->settings.dir.y * sin(-rotspeed);
		cube->settings.dir.y = old_dir_x * sin(-rotspeed) + \
	cube->settings.dir.y * cos(-rotspeed);
		old_plane_x = cube->settings.plane.x;
		cube->settings.plane.x = cube->settings.plane.x * \
	cos(-rotspeed) - cube->settings.plane.y * sin(-rotspeed);
		cube->settings.plane.y = old_plane_x * sin(-rotspeed) + \
	cube->settings.plane.y * cos(-rotspeed);
	}
	if (cube->settings.key_tab[SDL_SCANCODE_RIGHT])
	{
		old_dir_x = cube->settings.dir.x;
		cube->settings.dir.x = cube->settings.dir.x * cos(rotspeed) - \
	cube->settings.dir.y * sin(rotspeed);
		cube->settings.dir.y = old_dir_x * sin(rotspeed) + \
	cube->settings.dir.y * cos(rotspeed);
		old_plane_x = cube->settings.plane.x;
		cube->settings.plane.x = cube->settings.plane.x * \
	cos(rotspeed) - cube->settings.plane.y * sin(rotspeed);
		cube->settings.plane.y = old_plane_x * sin(rotspeed) + \
	cube->settings.plane.y * cos(rotspeed);
	}
}

void	handle_mouse_in_game(t_cube *cube, t_int_point pos)
{
	static int		x_old = 0;
	float			old_dir_x;
	float			old_plane_x;
	float			rotate_speed;

	rotate_speed = 0.1;
	mlx_mouse_hide();
	if (!x_old)
		x_old = pos.x;
	else if (pos.x == 0)
	{
		mlx_mouse_move(cube->mlx.ptr, cube->mlx.win, WIDTH / 2, HEIGHT / 2);
		x_old = 0;
	}
	else if (pos.x == WIDTH - 1)
	{
		mlx_mouse_move(cube->mlx.ptr, cube->mlx.win, WIDTH / 2, HEIGHT / 2);
		x_old = WIDTH - 1;
	}
	else if (x_old > pos.x)
	{
		old_dir_x = cube->settings.dir.x;
		cube->settings.dir.x = cube->settings.dir.x * \
	cos(-rotate_speed) - cube->settings.dir.y * sin(-rotate_speed);
		cube->settings.dir.y = old_dir_x * sin(-rotate_speed) + \
	cube->settings.dir.y * cos(-rotate_speed);
		old_plane_x = cube->settings.plane.x;
		cube->settings.plane.x = cube->settings.plane.x * \
	cos(-rotate_speed) - cube->settings.plane.y * sin(-rotate_speed);
		cube->settings.plane.y = old_plane_x * sin(-rotate_speed) + \
	cube->settings.plane.y * cos(-rotate_speed);
		x_old = pos.x;
	}
	else if (x_old < pos.x)
	{
		old_dir_x = cube->settings.dir.x;
		cube->settings.dir.x = cube->settings.dir.x * \
	cos(rotate_speed) - cube->settings.dir.y * sin(rotate_speed);
		cube->settings.dir.y = old_dir_x * sin(rotate_speed) + \
	cube->settings.dir.y * cos(rotate_speed);
		old_plane_x = cube->settings.plane.x;
		cube->settings.plane.x = cube->settings.plane.x * \
	cos(rotate_speed) - cube->settings.plane.y * sin(rotate_speed);
		cube->settings.plane.y = old_plane_x * sin(rotate_speed) + \
	cube->settings.plane.y * cos(rotate_speed);
		x_old = pos.x;
	}
	mlx_clear_window(cube->mlx.ptr, cube->mlx.win);
	render_cube(cube);
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
		move(cube);
		handle_mouse_in_game(cube, pos);
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
