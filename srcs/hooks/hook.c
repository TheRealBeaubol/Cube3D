/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:44:49 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/25 01:13:07 by lboiteux         ###   ########.fr       */
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

void	edit_player_settings(t_cube *cube, int key)
{
	if (cube->menu.keybind_menu_indice == 1)
		cube->settings.move_forward = key;
	if (cube->menu.keybind_menu_indice == 2)
		cube->settings.move_backward = key;
	if (cube->menu.keybind_menu_indice == 3)
		cube->settings.move_left = key;
	if (cube->menu.keybind_menu_indice == 4)
		cube->settings.move_right = key;
}

void	handle_settings_hook(t_cube *cube, int key)
{
	if ((key >= 4 && key <= 39) || key == 43 || key == \
44 || (key >= 84 && key <= 87) || (key >= 89 && key <= 98) || \
key == 224 || key == 225)
	{
		edit_player_settings(cube, key);
		open_settings(cube);
		cube->menu.keybind_menu_indice = 0;
	}
	cube->menu.waiting_for_key = 0;
}

void	handle_game_hook(t_cube *cube, int key)
{
	if (key == cube->settings.move_forward || \
key == cube->settings.move_backward || key == cube->settings.move_left || \
key == cube->settings.move_right || key == \
SDL_SCANCODE_LEFT || key == SDL_SCANCODE_RIGHT)
		cube->settings.key_tab[key] = 1;
}

int	key_press(int key, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (cube->is_in_game)
		handle_game_hook(cube, key);
	if (cube->menu.waiting_for_key)
		handle_settings_hook(cube, key);
	if (key == SDL_SCANCODE_ESCAPE)
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

int	mouse_release(int key, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	(void)cube;
	(void)key;
	(void)cube_void;
	return (0);
}

int	is_hover(int x1, int x2, int y1, int y2, t_int_point mouse)
{
	return (mouse.x > x1 && mouse.x < x2 && mouse.y > y1 && mouse.y < y2);
}

void	handle_mouse_in_settings(t_cube *cube, t_int_point pos)
{
	cube->menu.keybinds_button.status = is_hover(300, 620, 75, 190, pos);
	cube->menu.video_settings_button.status = is_hover(800, 1120, 75, 190, pos);
	cube->menu.music_and_sounds_button.status = is_hover(1300, 1620, 75, 190, pos);
}

void handle_mouse_in_menu(t_cube *cube, t_int_point pos)
{
	cube->menu.play_button.status = is_hover(780, 1135, 280, 400, pos);
	cube->menu.settings_button.status = is_hover(780, 1135, 480, 600, pos);
	cube->menu.exit_button.status = is_hover(780, 1135, 680, 800, pos);
}

void	handle_mouse_in_keybinds(t_cube *cube, t_int_point pos)
{
	const t_int_point	keybinds_pos[20] = {{671, 392}, {719, 440}, {\
671, 461}, {719, 509}, {671, 530}, {719, 578}, {671, 599}, {719, 647}, {\
671, 668}, {719, 716}, {1037, 392}, {1188, 440}, {1037, 461}, {1188, 509}, {\
1037, 530}, {1188, 578}, {1037, 599}, {1188, 647}, {1037, 668}, {1188, 716}};
	int					i;

	i = 0;
	while (i < 20)
	{
		if (is_hover(keybinds_pos[i].x, keybinds_pos[i + 1].x, \
keybinds_pos[i].y, keybinds_pos[i + 1].y, pos))
		{
			cube->menu.keybinds_define_button.status = i / 2 + 1;
			break ;
		}
		else
			cube->menu.keybinds_define_button.status = 0;
		i += 2;
	}
	if (cube->menu.keybinds_define_button.status)
		cube->menu.keybind_menu_indice = \
cube->menu.keybinds_define_button.status;
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
	// printf("FPS: %.2f\n", fps);
}

void	render_hover(void *mlx_ptr, void *win_ptr, t_settings_menu_images img, t_int_point pos)
{
	if (img.status)
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_hover, pos.x, pos.y);
	else
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, pos.x, pos.y);
}

void	render_button_in_menu(t_cube *cube)
{
	render_hover(cube->mlx.ptr, cube->mlx.win, cube->menu.play_button, \
(t_int_point){(WIDTH - cube->menu.play_button.width) / 2, ((HEIGHT - cube->menu.play_button.height) / 2) - 200});
	render_hover(cube->mlx.ptr, cube->mlx.win, cube->menu.settings_button, \
(t_int_point){(WIDTH - cube->menu.settings_button.width) / 2, ((HEIGHT - cube->menu.settings_button.height) / 2)});
	render_hover(cube->mlx.ptr, cube->mlx.win, cube->menu.exit_button, \
(t_int_point){(WIDTH - cube->menu.exit_button.width) / 2, ((HEIGHT - cube->menu.exit_button.height) / 2) + 200});
}

void	render_button_in_settings(t_cube *cube)
{
	render_hover(cube->mlx.ptr, cube->mlx.win, cube->menu.keybinds_button, \
(t_int_point){(WIDTH - cube->menu.keybinds_button.width) / 2 - cube->menu.keybinds_button.width * 1.25, 70});
	render_hover(cube->mlx.ptr, cube->mlx.win, cube->menu.video_settings_button, \
(t_int_point){(WIDTH - cube->menu.video_settings_button.width) / 2, 70});
	render_hover(cube->mlx.ptr, cube->mlx.win, cube->menu.music_and_sounds_button, \
(t_int_point){(WIDTH - cube->menu.music_and_sounds_button.width) / 2 + cube->menu.music_and_sounds_button.width * 1.25, 70});
}

void	render_button_in_keybinds(t_cube *cube)
{
	const t_int_point	pos[10] = {{671, 392}, {671, 461}, {671, 530}, {671, 599},\
{671, 668}, {1037, 395}, {1037, 464}, {1037, 533}, {1037, 602}, {1037, 671}};

	if (cube->menu.keybind_menu_indice)
		render_hover(cube->mlx.ptr, cube->mlx.win, cube->menu.keybinds_define_button, \
	pos[cube->menu.keybind_menu_indice - 1]);
}

void	render_buttons(t_cube *cube)
{
	if (cube->is_in_menu)
		render_button_in_menu(cube);
	if (cube->is_in_settings)
		render_button_in_settings(cube);
	if (cube->menu.keybinds_menu.status)
	{
		render_button_in_keybinds(cube);
		put_keys_images(cube, cube->mlx.ptr, cube->mlx.win);
	}
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
		if (cube->map.map[(int)cube->settings.pos.y][(int)(cube->settings.pos.x + cube->settings.dir.x * movespeed)] != '1')
			cube->settings.pos.x += cube->settings.dir.x * movespeed;
		if (cube->map.map[(int)(cube->settings.pos.y + cube->settings.dir.y * movespeed)][(int)cube->settings.pos.x] != '1')
			cube->settings.pos.y += cube->settings.dir.y * movespeed;
	}
	if (cube->settings.key_tab[cube->settings.move_backward])
	{
		if (cube->map.map[(int)cube->settings.pos.y][(int)(cube->settings.pos.x - cube->settings.dir.x * movespeed)] != '1')
			cube->settings.pos.x -= cube->settings.dir.x * movespeed;
		if (cube->map.map[(int)(cube->settings.pos.y - cube->settings.dir.y * movespeed)][(int)cube->settings.pos.x] != '1')
			cube->settings.pos.y -= cube->settings.dir.y * movespeed;
	}
	if (cube->settings.key_tab[cube->settings.move_left])
	{
		if (cube->map.map[(int)(cube->settings.pos.y + cube->settings.dir.x * movespeed)][(int)cube->settings.pos.x] != '1')
			cube->settings.pos.y -= cube->settings.dir.x * movespeed;
		if (cube->map.map[(int)cube->settings.pos.y][(int)(cube->settings.pos.x - cube->settings.dir.y * movespeed)] != '1')
			cube->settings.pos.x += cube->settings.dir.y * movespeed;
	}
	if (cube->settings.key_tab[cube->settings.move_right])
	{
		if (cube->map.map[(int)(cube->settings.pos.y - cube->settings.dir.x * movespeed)][(int)cube->settings.pos.x] != '1')
			cube->settings.pos.y += cube->settings.dir.x * movespeed;
		if (cube->map.map[(int)cube->settings.pos.y][(int)(cube->settings.pos.x + cube->settings.dir.y * movespeed)] != '1')
			cube->settings.pos.x -= cube->settings.dir.y * movespeed;
	}
	if (cube->settings.key_tab[SDL_SCANCODE_LEFT])
	{
		old_dir_x = cube->settings.dir.x;
		cube->settings.dir.x = cube->settings.dir.x * cos(-rotspeed) - cube->settings.dir.y * sin(-rotspeed);
		cube->settings.dir.y = old_dir_x * sin(-rotspeed) + cube->settings.dir.y * cos(-rotspeed);
		old_plane_x = cube->settings.plane.x;
		cube->settings.plane.x = cube->settings.plane.x * cos(-rotspeed) - cube->settings.plane.y * sin(-rotspeed);
		cube->settings.plane.y = old_plane_x * sin(-rotspeed) + cube->settings.plane.y * cos(-rotspeed);
	}
	if (cube->settings.key_tab[SDL_SCANCODE_RIGHT])
	{
		old_dir_x = cube->settings.dir.x;
		cube->settings.dir.x = cube->settings.dir.x * cos(rotspeed) - cube->settings.dir.y * sin(rotspeed);
		cube->settings.dir.y = old_dir_x * sin(rotspeed) + cube->settings.dir.y * cos(rotspeed);
		old_plane_x = cube->settings.plane.x;
		cube->settings.plane.x = cube->settings.plane.x * cos(rotspeed) - cube->settings.plane.y * sin(rotspeed);
		cube->settings.plane.y = old_plane_x * sin(rotspeed) + cube->settings.plane.y * cos(rotspeed);
	}
}
void	handle_mouse_in_game(t_cube *cube, t_int_point pos)
{
	static int		x_old = 0;

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
		float old_dir_x = cube->settings.dir.x;
		cube->settings.dir.x = cube->settings.dir.x * cos(-0.1) - cube->settings.dir.y * sin(-0.1);
		cube->settings.dir.y = old_dir_x * sin(-0.1) + cube->settings.dir.y * cos(-0.1);
		float old_plane_x = cube->settings.plane.x;
		cube->settings.plane.x = cube->settings.plane.x * cos(-0.1) - cube->settings.plane.y * sin(-0.1);
		cube->settings.plane.y = old_plane_x * sin(-0.1) + cube->settings.plane.y * cos(-0.1);
		x_old = pos.x;
	}
	else if (x_old < pos.x)
	{
		float old_dir_x = cube->settings.dir.x;
		cube->settings.dir.x = cube->settings.dir.x * cos(0.1) - cube->settings.dir.y * sin(0.1);
		cube->settings.dir.y = old_dir_x * sin(0.1) + cube->settings.dir.y * cos(0.1);
		float old_plane_x = cube->settings.plane.x;
		cube->settings.plane.x = cube->settings.plane.x * cos(0.1) - cube->settings.plane.y * sin(0.1);
		cube->settings.plane.y = old_plane_x * sin(0.1) + cube->settings.plane.y * cos(0.1);
		x_old = pos.x;
	}
	mlx_clear_window(cube->mlx.ptr, cube->mlx.win);
	render_cube(cube);
}

int	loop_hook(void *cube_void)
{
	t_cube *cube;
	t_int_point pos;

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
	mlx_on_event(cube->mlx.ptr, cube->mlx.win, MLX_MOUSEUP, &mouse_release, cube);
	mlx_loop_hook(cube->mlx.ptr, &loop_hook, cube);
	mlx_loop(cube->mlx.ptr);
}
