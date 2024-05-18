/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 01:48:36 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/18 02:08:21 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_numpad_keys(t_cube *cube, t_keys_images *img)
{
	img->key_num_0 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUM0.png", NULL, NULL);
	img->key_num_1 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUM1.png", NULL, NULL);
	img->key_num_2 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUM2.png", NULL, NULL);
	img->key_num_3 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUM3.png", NULL, NULL);
	img->key_num_4 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUM4.png", NULL, NULL);
	img->key_num_5 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUM5.png", NULL, NULL);
	img->key_num_6 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUM6.png", NULL, NULL);
	img->key_num_7 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUM7.png", NULL, NULL);
	img->key_num_8 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUM8.png", NULL, NULL);
	img->key_num_9 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUM9.png", NULL, NULL);
	img->key_num_div = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUMDIVIDE.png", NULL, NULL);
	img->key_num_mult = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUMMULT.png", NULL, NULL);
}

void	init_alnum_keys_end(t_cube *cube, t_keys_images *img)
{
	img->key_y = \
mlx_png_file_to_image(cube->mlx_ptr, "images/Y.png", NULL, NULL);
	img->key_z = \
mlx_png_file_to_image(cube->mlx_ptr, "images/Z.png", NULL, NULL);
	img->key_0 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/0.png", NULL, NULL);
	img->key_1 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/1.png", NULL, NULL);
	img->key_2 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/2.png", NULL, NULL);
	img->key_3 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/3.png", NULL, NULL);
	img->key_4 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/4.png", NULL, NULL);
	img->key_5 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/5.png", NULL, NULL);
	img->key_6 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/6.png", NULL, NULL);
	img->key_7 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/7.png", NULL, NULL);
	img->key_8 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/8.png", NULL, NULL);
	img->key_9 = \
mlx_png_file_to_image(cube->mlx_ptr, "images/9.png", NULL, NULL);
}

void	init_alnum_keys_next(t_cube *cube, t_keys_images *img)
{
	img->key_m = \
mlx_png_file_to_image(cube->mlx_ptr, "images/M.png", NULL, NULL);
	img->key_n = \
mlx_png_file_to_image(cube->mlx_ptr, "images/N.png", NULL, NULL);
	img->key_o = \
mlx_png_file_to_image(cube->mlx_ptr, "images/O.png", NULL, NULL);
	img->key_p = \
mlx_png_file_to_image(cube->mlx_ptr, "images/P.png", NULL, NULL);
	img->key_q = \
mlx_png_file_to_image(cube->mlx_ptr, "images/Q.png", NULL, NULL);
	img->key_r = \
mlx_png_file_to_image(cube->mlx_ptr, "images/R.png", NULL, NULL);
	img->key_s = \
mlx_png_file_to_image(cube->mlx_ptr, "images/S.png", NULL, NULL);
	img->key_t = \
mlx_png_file_to_image(cube->mlx_ptr, "images/T.png", NULL, NULL);
	img->key_u = \
mlx_png_file_to_image(cube->mlx_ptr, "images/U.png", NULL, NULL);
	img->key_v = \
mlx_png_file_to_image(cube->mlx_ptr, "images/V.png", NULL, NULL);
	img->key_w = \
mlx_png_file_to_image(cube->mlx_ptr, "images/W.png", NULL, NULL);
	img->key_x = \
mlx_png_file_to_image(cube->mlx_ptr, "images/X.png", NULL, NULL);
	init_alnum_keys_end(cube, img);
}

void	init_alnum_keys_start(t_cube *cube, t_keys_images *img)
{
	img->key_a = \
mlx_png_file_to_image(cube->mlx_ptr, "images/A.png", NULL, NULL);
	img->key_b = \
mlx_png_file_to_image(cube->mlx_ptr, "images/B.png", NULL, NULL);
	img->key_c = \
mlx_png_file_to_image(cube->mlx_ptr, "images/C.png", NULL, NULL);
	img->key_d = \
mlx_png_file_to_image(cube->mlx_ptr, "images/D.png", NULL, NULL);
	img->key_e = \
mlx_png_file_to_image(cube->mlx_ptr, "images/E.png", NULL, NULL);
	img->key_f = \
mlx_png_file_to_image(cube->mlx_ptr, "images/F.png", NULL, NULL);
	img->key_g = \
mlx_png_file_to_image(cube->mlx_ptr, "images/G.png", NULL, NULL);
	img->key_h = \
mlx_png_file_to_image(cube->mlx_ptr, "images/H.png", NULL, NULL);
	img->key_i = \
mlx_png_file_to_image(cube->mlx_ptr, "images/I.png", NULL, NULL);
	img->key_j = \
mlx_png_file_to_image(cube->mlx_ptr, "images/J.png", NULL, NULL);
	img->key_k = \
mlx_png_file_to_image(cube->mlx_ptr, "images/K.png", NULL, NULL);
	img->key_l = \
mlx_png_file_to_image(cube->mlx_ptr, "images/L.png", NULL, NULL);
	init_alnum_keys_next(cube, img);
}

t_keys_images	*init_keys_images(t_cube *cube)
{
	t_keys_images	*img;

	img = ft_calloc(1, sizeof(t_keys_images));
	init_alnum_keys_start(cube, img);
	init_numpad_keys(cube, img);
	img->key_num_minus = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUMMINUS.png", NULL, NULL);
	img->key_num_plus = \
mlx_png_file_to_image(cube->mlx_ptr, "images/NUMPLUS.png", NULL, NULL);
	img->key_space = \
mlx_png_file_to_image(cube->mlx_ptr, "images/SPACE.png", NULL, NULL);
	img->key_shift = \
mlx_png_file_to_image(cube->mlx_ptr, "images/SHIFT.png", NULL, NULL);
	img->key_ctrl = \
mlx_png_file_to_image(cube->mlx_ptr, "images/CTRL.png", NULL, NULL);
	img->key_tab = \
mlx_png_file_to_image(cube->mlx_ptr, "images/TAB.png", NULL, NULL);
	return (img);
}
