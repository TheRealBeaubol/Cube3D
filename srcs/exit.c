/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:02:33 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/17 22:51:23 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	destroy_keys_images(t_cube *cube, t_keys_images *img)
{
	mlx_destroy_image(cube->mlx_ptr, img->key_a);
	mlx_destroy_image(cube->mlx_ptr, img->key_b);
	mlx_destroy_image(cube->mlx_ptr, img->key_c);
	mlx_destroy_image(cube->mlx_ptr, img->key_d);
	mlx_destroy_image(cube->mlx_ptr, img->key_e);
	mlx_destroy_image(cube->mlx_ptr, img->key_f);
	mlx_destroy_image(cube->mlx_ptr, img->key_g);
	mlx_destroy_image(cube->mlx_ptr, img->key_h);
	mlx_destroy_image(cube->mlx_ptr, img->key_i);
	mlx_destroy_image(cube->mlx_ptr, img->key_j);
	mlx_destroy_image(cube->mlx_ptr, img->key_k);
	mlx_destroy_image(cube->mlx_ptr, img->key_l);
	mlx_destroy_image(cube->mlx_ptr, img->key_m);
	mlx_destroy_image(cube->mlx_ptr, img->key_n);
	mlx_destroy_image(cube->mlx_ptr, img->key_o);
	mlx_destroy_image(cube->mlx_ptr, img->key_p);
	mlx_destroy_image(cube->mlx_ptr, img->key_q);
	mlx_destroy_image(cube->mlx_ptr, img->key_r);
	mlx_destroy_image(cube->mlx_ptr, img->key_s);
	mlx_destroy_image(cube->mlx_ptr, img->key_t);
	mlx_destroy_image(cube->mlx_ptr, img->key_u);
	mlx_destroy_image(cube->mlx_ptr, img->key_v);
	mlx_destroy_image(cube->mlx_ptr, img->key_w);
	mlx_destroy_image(cube->mlx_ptr, img->key_x);
	mlx_destroy_image(cube->mlx_ptr, img->key_y);
	mlx_destroy_image(cube->mlx_ptr, img->key_z);
	mlx_destroy_image(cube->mlx_ptr, img->key_0);
	mlx_destroy_image(cube->mlx_ptr, img->key_1);
	mlx_destroy_image(cube->mlx_ptr, img->key_2);
	mlx_destroy_image(cube->mlx_ptr, img->key_3);
	mlx_destroy_image(cube->mlx_ptr, img->key_4);
	mlx_destroy_image(cube->mlx_ptr, img->key_5);
	mlx_destroy_image(cube->mlx_ptr, img->key_6);
	mlx_destroy_image(cube->mlx_ptr, img->key_7);
	mlx_destroy_image(cube->mlx_ptr, img->key_8);
	mlx_destroy_image(cube->mlx_ptr, img->key_9);
	mlx_destroy_image(cube->mlx_ptr, img->key_space);
	mlx_destroy_image(cube->mlx_ptr, img->key_shift);
	mlx_destroy_image(cube->mlx_ptr, img->key_ctrl);
	mlx_destroy_image(cube->mlx_ptr, img->key_tab);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_0);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_1);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_2);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_3);	
	mlx_destroy_image(cube->mlx_ptr, img->key_num_4);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_5);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_6);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_7);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_8);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_9);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_mult);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_div);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_minus);
	mlx_destroy_image(cube->mlx_ptr, img->key_num_plus);
}

void	free_and_destroy(t_cube *cube)
{
	mlx_destroy_image(cube->mlx_ptr, cube->menu->play_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->exit_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->play_button_hover);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_button_hover);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->exit_button_hover);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->start_background);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->keybinds_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->keybinds_button_hover);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->video_settings_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->video_settings_button_hover);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->music_and_sounds_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->music_and_sounds_button_hover);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->keybinds_menu);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->video_settings_menu);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->music_and_sounds_menu);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->keybinds_define_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->keybinds_define_button_hover);
	destroy_keys_images(cube, cube->menu->settings_menu->keys_images);
	free(cube->menu->settings_menu->keys_images);
	free(cube->menu->settings_menu);
	mlx_destroy_image(cube->mlx_ptr, cube->img);
	mlx_destroy_window(cube->mlx_ptr, cube->window_ptr);
	mlx_destroy_display(cube->mlx_ptr);
	exit (0);
}

int	free_and_destroy_exit(int i, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (i == 0)
		free_and_destroy(cube);
	return (0);
}
