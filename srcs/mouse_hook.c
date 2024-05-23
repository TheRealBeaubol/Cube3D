/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:57:12 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/23 15:38:41 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_hover_button(t_cube *cube)
{
	void	*keys_image;

	if (cube->menu->is_in_menu)
	{
		if (cube->menu->play_button_status)
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->play_button_hover, (WIDTH - cube->menu->button_width) / 2, \
	((HEIGHT - cube->menu->button_height) / 2) - 200);
		else
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->play_button, (WIDTH - cube->menu->button_width) / 2, \
	((HEIGHT - cube->menu->button_height) / 2) - 200);
		if (cube->menu->settings_button_status)
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_button_hover, (WIDTH - cube->menu->button_width) / 2, \
	((HEIGHT - cube->menu->button_height) / 2));
		else
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_button, (WIDTH - cube->menu->button_width) / 2, \
	((HEIGHT - cube->menu->button_height) / 2));
		if (cube->menu->exit_button_status)
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->exit_button_hover, (WIDTH - cube->menu->button_width) / 2, \
	((HEIGHT - cube->menu->button_height) / 2) + 200);
		else
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->exit_button, (WIDTH - cube->menu->button_width) / 2, \
	((HEIGHT - cube->menu->button_height) / 2) + 200);
	}
	if (cube->menu->settings_menu->is_in_settings_menu)
	{
		if (cube->menu->settings_menu->keybinds_button_status)
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_button_hover, ((WIDTH - \
cube->menu->settings_menu->button_width) / 2) - \
cube->menu->settings_menu->button_width * 1.25, 70);
		else
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->keybinds_button, ((WIDTH - \
cube->menu->settings_menu->button_width) / 2) - \
cube->menu->settings_menu->button_width * 1.25, 70);
		if (cube->menu->settings_menu->video_settings_button_status)
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->video_settings_button_hover, (WIDTH - \
cube->menu->settings_menu->button_width) / 2, 70);
		else
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->video_settings_button, (WIDTH - \
cube->menu->settings_menu->button_width) / 2, 70);
		if (cube->menu->settings_menu->music_and_sounds_button_status)
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->music_and_sounds_button_hover, ((WIDTH - \
cube->menu->settings_menu->button_width) / 2) + \
cube->menu->settings_menu->button_width * 1.25, 70);
		else
			mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_menu->music_and_sounds_button, ((WIDTH - \
cube->menu->settings_menu->button_width) / 2) + \
cube->menu->settings_menu->button_width * 1.25, 70);
	}
	if (cube->menu->settings_menu->is_in_keybinds_menu)
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
}

void	handle_mouse_in_start_menu(t_cube *cube, int x, int y)
{
	if (cube->menu->is_in_menu)
	{
		cube->menu->play_button_status = (x > 780 && x < 1135 && \
y > 280 && y < 400);
		cube->menu->settings_button_status = (x > 780 && x < 1135 && \
y > 480 && y < 600);
		cube->menu->exit_button_status = (x > 780 && x < 1135 && \
y > 680 && y < 800);
	}
	if (cube->menu->settings_menu->is_in_settings_menu)
	{
		cube->menu->settings_menu->keybinds_button_status = (\
x > 300 && x < 620 && y > 75 && y < 190);
		cube->menu->settings_menu->video_settings_button_status = (\
x > 800 && x < 1120 && y > 75 && y < 190);
		cube->menu->settings_menu->music_and_sounds_button_status = (\
x > 1300 && x < 1620 && y > 75 && y < 190);
	}
	if (cube->menu->settings_menu->is_in_keybinds_menu)
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
	render_hover_button(cube);
}

int	mouse_release(int keycode, void *cube_void)
{
	(void)cube_void;
	(void)keycode;
	return (0);
}

int	mouse_press(int key, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (cube->menu->is_in_menu)
	{
		if (cube->menu->play_button_status && key)
		{
			cube->menu->is_in_menu = 0;
			cube->is_in_game = 1;
			mlx_clear_window(cube->mlx_ptr, cube->window_ptr);
			print_map(parsing(cube->map), cube);
		}
		if (cube->menu->settings_button_status && key)
		{
			cube->menu->is_in_menu = 0;
			cube->menu->settings_menu->is_in_settings_menu = 1;
			open_settings(cube);
		}
		if (cube->menu->exit_button_status && key)
			free_and_destroy(cube);
	}
	if (cube->menu->settings_menu->is_in_settings_menu)
	{
		if (cube->menu->settings_menu->keybinds_button_status && key)
			open_keybinds_menu(cube);
		if (cube->menu->settings_menu->video_settings_button_status && key)
			open_video_settings_menu(cube);
		if (cube->menu->settings_menu->music_and_sounds_button_status && key)
			open_music_and_sounds_menu(cube);
		if (cube->menu->settings_menu->keybinds_define_button_status && key)
			cube->menu->settings_menu->waiting_for_key = 1;
	}
	return (0);
}

void	*get_key_images(t_cube *cube, int key)
{
	if (key == KEY_A)
		return (cube->menu->settings_menu->keys_images->key_a);
	if (key == KEY_B)
		return (cube->menu->settings_menu->keys_images->key_b);
	if (key == KEY_C)
		return (cube->menu->settings_menu->keys_images->key_c);
	if (key == KEY_D)
		return (cube->menu->settings_menu->keys_images->key_d);
	if (key == KEY_E)
		return (cube->menu->settings_menu->keys_images->key_e);
	if (key == KEY_F)
		return (cube->menu->settings_menu->keys_images->key_f);
	if (key == KEY_G)
		return (cube->menu->settings_menu->keys_images->key_g);
	if (key == KEY_H)
		return (cube->menu->settings_menu->keys_images->key_h);
	if (key == KEY_I)
		return (cube->menu->settings_menu->keys_images->key_i);
	if (key == KEY_J)
		return (cube->menu->settings_menu->keys_images->key_j);
	if (key == KEY_K)
		return (cube->menu->settings_menu->keys_images->key_k);
	if (key == KEY_L)
		return (cube->menu->settings_menu->keys_images->key_l);
	if (key == KEY_M)
		return (cube->menu->settings_menu->keys_images->key_m);
	if (key == KEY_N)
		return (cube->menu->settings_menu->keys_images->key_n);
	if (key == KEY_O)
		return (cube->menu->settings_menu->keys_images->key_o);
	if (key == KEY_P)
		return (cube->menu->settings_menu->keys_images->key_p);
	if (key == KEY_Q)
		return (cube->menu->settings_menu->keys_images->key_q);
	if (key == KEY_R)
		return (cube->menu->settings_menu->keys_images->key_r);
	if (key == KEY_S)
		return (cube->menu->settings_menu->keys_images->key_s);
	if (key == KEY_T)
		return (cube->menu->settings_menu->keys_images->key_t);
	if (key == KEY_U)
		return (cube->menu->settings_menu->keys_images->key_u);
	if (key == KEY_V)
		return (cube->menu->settings_menu->keys_images->key_v);
	if (key == KEY_W)
		return (cube->menu->settings_menu->keys_images->key_w);
	if (key == KEY_X)
		return (cube->menu->settings_menu->keys_images->key_x);
	if (key == KEY_Y)
		return (cube->menu->settings_menu->keys_images->key_y);
	if (key == KEY_Z)
		return (cube->menu->settings_menu->keys_images->key_z);
	if (key == KEY_0)
		return (cube->menu->settings_menu->keys_images->key_0);
	if (key == KEY_1)
		return (cube->menu->settings_menu->keys_images->key_1);
	if (key == KEY_2)
		return (cube->menu->settings_menu->keys_images->key_2);
	if (key == KEY_3)
		return (cube->menu->settings_menu->keys_images->key_3);
	if (key == KEY_4)
		return (cube->menu->settings_menu->keys_images->key_4);
	if (key == KEY_5)
		return (cube->menu->settings_menu->keys_images->key_5);
	if (key == KEY_6)
		return (cube->menu->settings_menu->keys_images->key_6);
	if (key == KEY_7)
		return (cube->menu->settings_menu->keys_images->key_7);
	if (key == KEY_8)
		return (cube->menu->settings_menu->keys_images->key_8);
	if (key == KEY_9)
		return (cube->menu->settings_menu->keys_images->key_9);
	if (key == SPACE)
		return (cube->menu->settings_menu->keys_images->key_space);
	if (key == SHIFT)
		return (cube->menu->settings_menu->keys_images->key_shift);
	if (key == KEYPAD_0)
		return (cube->menu->settings_menu->keys_images->key_num_0);
	if (key == KEYPAD_1)
		return (cube->menu->settings_menu->keys_images->key_num_1);
	if (key == KEYPAD_2)
		return (cube->menu->settings_menu->keys_images->key_num_2);
	if (key == KEYPAD_3)
		return (cube->menu->settings_menu->keys_images->key_num_3);
	if (key == KEYPAD_4)
		return (cube->menu->settings_menu->keys_images->key_num_4);
	if (key == KEYPAD_5)
		return (cube->menu->settings_menu->keys_images->key_num_5);
	if (key == KEYPAD_6)
		return (cube->menu->settings_menu->keys_images->key_num_6);
	if (key == KEYPAD_7)
		return (cube->menu->settings_menu->keys_images->key_num_7);
	if (key == KEYPAD_8)
		return (cube->menu->settings_menu->keys_images->key_num_8);
	if (key == KEYPAD_9)
		return (cube->menu->settings_menu->keys_images->key_num_9);
	if (key == KEYPAD_DIV)
		return (cube->menu->settings_menu->keys_images->key_num_div);
	if (key == KEYPAD_MULT)
		return (cube->menu->settings_menu->keys_images->key_num_mult);
	if (key == KEYPAD_MINUS)
		return (cube->menu->settings_menu->keys_images->key_num_minus);
	if (key == KEYPAD_PLUS)
		return (cube->menu->settings_menu->keys_images->key_num_plus);
	if (key == CTRL)
		return (cube->menu->settings_menu->keys_images->key_ctrl);
	if (key == TAB)
		return (cube->menu->settings_menu->keys_images->key_tab);
	return (NULL);
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
