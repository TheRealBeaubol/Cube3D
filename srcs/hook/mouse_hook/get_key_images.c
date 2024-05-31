/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:37:51 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/30 14:43:54 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*get_key_images_part_one(t_cube *cube, int key)
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
	return (NULL);
}

void	*get_key_images_part_two(t_cube *cube, int key)
{
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
	return (NULL);
}

void	*get_key_images_part_three(t_cube *cube, int key)
{
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
	return (NULL);
}

void	*get_key_images_part_four(t_cube *cube, int key)
{
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
	return (NULL);
}

void	*get_key_images(t_cube *cube, int key)
{
	if (get_key_images_part_one(cube, key))
		return (get_key_images_part_one(cube, key));
	if (get_key_images_part_two(cube, key))
		return (get_key_images_part_two(cube, key));
	if (get_key_images_part_three(cube, key))
		return (get_key_images_part_three(cube, key));
	if (get_key_images_part_four(cube, key))
		return (get_key_images_part_four(cube, key));
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
