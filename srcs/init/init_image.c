/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:31:35 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/08 22:14:52 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_keys(void *mlx_ptr, t_menu *menu)
{
	const char	*key_paths[54] = {"images/A.png", "images/B.png", \
"images/C.png", "images/D.png", "images/E.png", "images/F.png", \
"images/G.png", "images/H.png", "images/I.png", "images/J.png", \
"images/K.png", "images/L.png", "images/M.png", "images/N.png", \
"images/O.png", "images/P.png", "images/Q.png", "images/R.png", \
"images/S.png", "images/T.png", "images/U.png", "images/V.png", \
"images/W.png", "images/X.png", "images/Y.png", "images/Z.png", \
"images/0.png", "images/1.png", "images/2.png", "images/3.png", \
"images/4.png", "images/5.png", "images/6.png", "images/7.png", \
"images/8.png", "images/9.png", "images/NUM0.png", "images/NUM1.png", \
"images/NUM2.png", "images/NUM3.png", "images/NUM4.png", \
"images/NUM5.png", "images/NUM6.png", "images/NUM7.png", \
"images/NUM8.png", "images/NUM9.png", "images/SHIFT.png", "images/CTRL.png"\
, "images/SPACE.png", "images/TAB.png", "images/NUMMULT.png", \
"images/NUMPLUS.png", "images/NUMMINUS.png", "images/NUMDIVIDE.png"};
	int			i;

	i = -1;
	while (++i < 54)
	{
		menu->keys[i].path = (char *)key_paths[i];
		menu->keys[i].img = mlx_png_file_to_image(mlx_ptr, \
menu->keys[i].path, NULL, NULL);
	}
}

void	init_menu_images(void *mlx_ptr, t_settings_menu_images \
	*image, const char *img_path)
{
	image->img = mlx_png_file_to_image(mlx_ptr, (char *)img_path, \
&image->width, &image->height);
	image->status = 0;
}

void	init_settings_menu_image(void *mlx_ptr, t_settings_menu_images \
	*image, const char *img_path, const char *img_hover_path)
{
	image->img = mlx_png_file_to_image(mlx_ptr, (char *)img_path, \
&image->width, &image->height);
	image->img_hover = mlx_png_file_to_image(\
mlx_ptr, (char *)img_hover_path, &image->width_hover, \
&image->height_hover);
	image->status = 0;
}

void	init_images(void *mlx_ptr, t_menu *menu)
{
	init_keys(mlx_ptr, menu);
	init_settings_menu_image(mlx_ptr, &menu->keybinds_button, \
"images/keybinds_button.png", "images/keybinds_button_hover.png");
	init_settings_menu_image(mlx_ptr, &menu->video_settings_button, \
"images/video_settings_button.png", "images/video_settings_button_hover.png");
	init_settings_menu_image(mlx_ptr, &menu->music_and_sounds_button, \
"images/music_and_sounds_button.png", \
"images/music_and_sounds_button_hover.png");
	init_settings_menu_image(mlx_ptr, &menu->keybinds_define_button, \
"images/keybinds_define_button.png", \
"images/keybinds_define_button_hover.png");
	init_settings_menu_image(mlx_ptr, &menu->exit_button, \
"images/exit_button.png", "images/exit_button_hover.png");
	init_settings_menu_image(mlx_ptr, &menu->play_button, \
"images/play_button.png", "images/play_button_hover.png");
	init_settings_menu_image(mlx_ptr, &menu->settings_button, \
"images/settings_button.png", "images/settings_button_hover.png");
	init_menu_images(mlx_ptr, &menu->video_settings_menu, \
"images/video_settings_menu.png");
	init_menu_images(mlx_ptr, &menu->keybinds_menu, \
"images/keybinds_menu.png");
	init_menu_images(mlx_ptr, &menu->music_and_sounds_menu, \
"images/music_and_sounds_menu.png");
	menu->background = mlx_png_file_to_image(mlx_ptr, \
"./images/background.png", NULL, NULL);
}
