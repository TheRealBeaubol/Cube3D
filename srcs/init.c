/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:02:00 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/18 00:20:39 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_settings_menu	*init_settings_menu(t_cube *cube)
{
	t_settings_menu	*settings_menu;

	settings_menu = ft_calloc(1, sizeof(t_settings_menu));
	settings_menu->waiting_for_key = 0;
	settings_menu->waiting_for_print = 0;
	settings_menu->keybinds_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/keybinds_button.png", &(settings_menu->button_width), &(settings_menu->button_height));
	settings_menu->keybinds_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/keybinds_button_hover.png", NULL, NULL);
	settings_menu->video_settings_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/video_settings_button.png", NULL, NULL);
	settings_menu->video_settings_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/video_settings_button_hover.png", NULL, NULL);
	settings_menu->music_and_sounds_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/music_and_sounds_button.png", NULL, NULL);
	settings_menu->music_and_sounds_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/music_and_sounds_button_hover.png", NULL, NULL);
	settings_menu->keybinds_menu = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/keybinds_menu.png", &(settings_menu->settings_menu_width), &(settings_menu->settings_menu_height));
	settings_menu->video_settings_menu = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/video_settings_menu.png", NULL, NULL);
	settings_menu->music_and_sounds_menu = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/music_and_sounds_menu.png", NULL, NULL);
	settings_menu->keybinds_define_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/keybinds_define_button.png", NULL, NULL);
	settings_menu->keybinds_define_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/keybinds_define_button_hover.png", NULL, NULL);
	return (settings_menu);
}
// settings_menu->back_button = mlx_png_file_to_image(cube->mlx_ptr, 
// 	"images/back_button.png", NULL, NULL);
// settings_menu->back_button_hover = mlx_png_file_to_image(cube->mlx_ptr, 
// 	"images/back_button_hover.png", NULL, NULL);

t_keys_images	*init_keys_images(t_cube *cube)
{
	t_keys_images	*img;

	img = ft_calloc(1, sizeof(t_keys_images));
	img->key_a = mlx_png_file_to_image(cube->mlx_ptr, "images/A.png", NULL, NULL);
	img->key_b = mlx_png_file_to_image(cube->mlx_ptr, "images/B.png", NULL, NULL);
	img->key_c = mlx_png_file_to_image(cube->mlx_ptr, "images/C.png", NULL, NULL);
	img->key_d = mlx_png_file_to_image(cube->mlx_ptr, "images/D.png", NULL, NULL);
	img->key_e = mlx_png_file_to_image(cube->mlx_ptr, "images/E.png", NULL, NULL);
	img->key_f = mlx_png_file_to_image(cube->mlx_ptr, "images/F.png", NULL, NULL);
	img->key_g = mlx_png_file_to_image(cube->mlx_ptr, "images/G.png", NULL, NULL);
	img->key_h = mlx_png_file_to_image(cube->mlx_ptr, "images/H.png", NULL, NULL);
	img->key_i = mlx_png_file_to_image(cube->mlx_ptr, "images/I.png", NULL, NULL);
	img->key_j = mlx_png_file_to_image(cube->mlx_ptr, "images/J.png", NULL, NULL);
	img->key_k = mlx_png_file_to_image(cube->mlx_ptr, "images/K.png", NULL, NULL);
	img->key_l = mlx_png_file_to_image(cube->mlx_ptr, "images/L.png", NULL, NULL);
	img->key_m = mlx_png_file_to_image(cube->mlx_ptr, "images/M.png", NULL, NULL);
	img->key_n = mlx_png_file_to_image(cube->mlx_ptr, "images/N.png", NULL, NULL);
	img->key_o = mlx_png_file_to_image(cube->mlx_ptr, "images/O.png", NULL, NULL);
	img->key_p = mlx_png_file_to_image(cube->mlx_ptr, "images/P.png", NULL, NULL);
	img->key_q = mlx_png_file_to_image(cube->mlx_ptr, "images/Q.png", NULL, NULL);
	img->key_r = mlx_png_file_to_image(cube->mlx_ptr, "images/R.png", NULL, NULL);
	img->key_s = mlx_png_file_to_image(cube->mlx_ptr, "images/S.png", NULL, NULL);
	img->key_t = mlx_png_file_to_image(cube->mlx_ptr, "images/T.png", NULL, NULL);
	img->key_u = mlx_png_file_to_image(cube->mlx_ptr, "images/U.png", NULL, NULL);
	img->key_v = mlx_png_file_to_image(cube->mlx_ptr, "images/V.png", NULL, NULL);
	img->key_w = mlx_png_file_to_image(cube->mlx_ptr, "images/W.png", NULL, NULL);
	img->key_x = mlx_png_file_to_image(cube->mlx_ptr, "images/X.png", NULL, NULL);
	img->key_y = mlx_png_file_to_image(cube->mlx_ptr, "images/Y.png", NULL, NULL);
	img->key_z = mlx_png_file_to_image(cube->mlx_ptr, "images/Z.png", NULL, NULL);
	img->key_0 = mlx_png_file_to_image(cube->mlx_ptr, "images/0.png", NULL, NULL);
	img->key_1 = mlx_png_file_to_image(cube->mlx_ptr, "images/1.png", NULL, NULL);
	img->key_2 = mlx_png_file_to_image(cube->mlx_ptr, "images/2.png", NULL, NULL);
	img->key_3 = mlx_png_file_to_image(cube->mlx_ptr, "images/3.png", NULL, NULL);
	img->key_4 = mlx_png_file_to_image(cube->mlx_ptr, "images/4.png", NULL, NULL);
	img->key_5 = mlx_png_file_to_image(cube->mlx_ptr, "images/5.png", NULL, NULL);
	img->key_6 = mlx_png_file_to_image(cube->mlx_ptr, "images/6.png", NULL, NULL);
	img->key_7 = mlx_png_file_to_image(cube->mlx_ptr, "images/7.png", NULL, NULL);
	img->key_8 = mlx_png_file_to_image(cube->mlx_ptr, "images/8.png", NULL, NULL);
	img->key_9 = mlx_png_file_to_image(cube->mlx_ptr, "images/9.png", NULL, NULL);
	img->key_num_0 = mlx_png_file_to_image(cube->mlx_ptr, "images/NUM0.png", NULL, NULL);
	img->key_num_1 = mlx_png_file_to_image(cube->mlx_ptr, "images/NUM1.png", NULL, NULL);
	img->key_num_2 = mlx_png_file_to_image(cube->mlx_ptr, "images/NUM2.png", NULL, NULL);
	img->key_num_3 = mlx_png_file_to_image(cube->mlx_ptr, "images/NUM3.png", NULL, NULL);
	img->key_num_4 = mlx_png_file_to_image(cube->mlx_ptr, "images/NUM4.png", NULL, NULL);
	img->key_num_5 = mlx_png_file_to_image(cube->mlx_ptr, "images/NUM5.png", NULL, NULL);
	img->key_num_6 = mlx_png_file_to_image(cube->mlx_ptr, "images/NUM6.png", NULL, NULL);
	img->key_num_7 = mlx_png_file_to_image(cube->mlx_ptr, "images/NUM7.png", NULL, NULL);
	img->key_num_8 = mlx_png_file_to_image(cube->mlx_ptr, "images/NUM8.png", NULL, NULL);
	img->key_num_9 = mlx_png_file_to_image(cube->mlx_ptr, "images/NUM9.png", NULL, NULL);
	img->key_num_div = mlx_png_file_to_image(cube->mlx_ptr, "images/NUMDIVIDE.png", NULL, NULL);
	img->key_num_mult = mlx_png_file_to_image(cube->mlx_ptr, "images/NUMMULT.png", NULL, NULL);
	img->key_num_minus = mlx_png_file_to_image(cube->mlx_ptr, "images/NUMMINUS.png", NULL, NULL);
	img->key_num_plus = mlx_png_file_to_image(cube->mlx_ptr, "images/NUMPLUS.png", NULL, NULL);
	img->key_space = mlx_png_file_to_image(cube->mlx_ptr, "images/SPACE.png", NULL, NULL);
	img->key_shift = mlx_png_file_to_image(cube->mlx_ptr, "images/SHIFT.png", NULL, NULL);
	img->key_ctrl = mlx_png_file_to_image(cube->mlx_ptr, "images/CTRL.png", NULL, NULL);
	img->key_tab = mlx_png_file_to_image(cube->mlx_ptr, "images/TAB.png", NULL, NULL);
	return (img);
}

t_menu	*init_menu(t_cube *cube)
{
	t_menu	*menu;

	menu = ft_calloc(1, sizeof(t_menu));
	menu->start_background = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/start_background.png", NULL, NULL);
	menu->play_button = mlx_png_file_to_image(cube->mlx_ptr, \
"images/play_button.png", &(menu->button_width), &(menu->button_height));
	menu->settings_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/settings_button.png", NULL, NULL);
	menu->exit_button = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/exit_button.png", NULL, NULL);
	menu->play_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/play_button_hover.png", NULL, NULL);
	menu->settings_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/settings_button_hover.png", NULL, NULL);
	menu->exit_button_hover = mlx_png_file_to_image(cube->mlx_ptr, \
		"images/exit_button_hover.png", NULL, NULL);
	menu->settings_menu = init_settings_menu(cube);
	menu->settings_menu->keys_images = init_keys_images(cube);
	return (menu);
}

void	clear_window(t_cube *cube)
{
	int	x;
	int	y;

	y = -1;
	while (++y != HEIGHT)
	{
		x = -1;
		while (++x != WIDTH)
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, x, y, 0xffe19239);
	}
}

void	init_settings_file(t_cube *cube)
{
	int	fd;

	(void)cube;
	fd = open("/tmp/settings.txt", O_RDWR, 0644);
	if (fd == -1)
		fd = open("/tmp/settings.txt", O_CREAT | O_RDWR, 0644);
	ft_putstr_fd("[KEYBINDS] :\n\n[VIDEO SETTINGS] :\n\n[MUSIC AND SOUNDS] :\n", fd);
	close(fd);
}

t_player_settings	*init_player_settings(void)
{
	t_player_settings	*settings;

	settings = ft_calloc(1, sizeof(t_player_settings));
	settings->move_forward = KEY_W;
	settings->move_backward = KEY_S;
	settings->move_left = KEY_A;
	settings->move_right = KEY_D;
}

// Set the default settings here, 
// Do a fonction to edit the settings with only a putstr and a string like up there, just put int value. 
// When reading the settings.txt file check if the int value is coherent.
// If not because someone edited the file -> set error message and redefine the settings.txt file.
void	init(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	if (cube->mlx_ptr == NULL)
		exit (1);
	cube->img = mlx_new_image(cube->mlx_ptr, WIDTH, HEIGHT);
	cube->window_ptr = mlx_new_window(cube->mlx_ptr, WIDTH, HEIGHT, "Cube3D");
	if (cube->window_ptr == NULL)
		free_and_destroy(cube);
	cube->menu = init_menu(cube);
	cube->player_settings = init_player_settings();
	cube->menu->is_in_menu = 1;
	cube->menu->play_button_status = 0;
	cube->menu->settings_button_status = 0;
	cube->menu->exit_button_status = 0;
	init_settings_file(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->start_background, 0, 0);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->play_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) - 200);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->settings_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2));
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->exit_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) + 200);
}
