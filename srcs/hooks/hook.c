/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:44:49 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 18:07:19 by lboiteux         ###   ########.fr       */
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

void	handle_key_in_game(t_cube *cube)
{
	if (cube->settings.key_tab[cube->settings.keybinds[2]] == 1)
		cube->settings.move_speed = 0.115;
	else if (cube->settings.key_tab[cube->settings.keybinds[6]] == 1)
		cube->settings.move_speed = 0.035;
	else
		cube->settings.move_speed = 0.065;
	if (cube->settings.key_tab[cube->settings.keybinds[0]])
		move_forward(cube, cube->settings.move_speed);
	if (cube->settings.key_tab[cube->settings.keybinds[1]])
		move_backward(cube, cube->settings.move_speed);
	if (cube->settings.key_tab[cube->settings.keybinds[3]])
		move_left(cube, cube->settings.move_speed);
	if (cube->settings.key_tab[cube->settings.keybinds[4]])
		move_right(cube, cube->settings.move_speed);
	if (cube->settings.key_tab[SDL_SCANCODE_LEFT] == 1)
		rotate(cube, -cube->settings.sensibility);
	if (cube->settings.key_tab[SDL_SCANCODE_RIGHT] == 1)
		rotate(cube, cube->settings.sensibility);
}

void	handle_mouse_in_game(t_cube *cube, t_int_point pos)
{
	t_point			point;

	mlx_mouse_hide();
	point.x = (pos.x - WIDTH / 2) * cube->settings.sensibility;
	rotate(cube, point.x);
	cube->settings.pitch += (pos.y - HEIGHT / 2) * cube->settings.sensibility;
	if (cube->settings.pitch > 1.0)
		cube->settings.pitch = 1.0;
	if (cube->settings.pitch < -1.0)
		cube->settings.pitch = -1.0;
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
		check_and_do_portal(cube);
		mlx_clear_window(cube->mlx.ptr, cube->mlx.win);
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
