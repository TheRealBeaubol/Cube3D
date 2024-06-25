/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:28:35 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/25 12:37:08 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_hover(t_int_point point_1, t_int_point point_2, t_int_point mouse)
{
	return (mouse.x > point_1.x && mouse.x < point_2.x && mouse.y > \
		point_1.y && mouse.y < point_2.y);
}

void	handle_mouse_in_settings(t_cube *cube, t_int_point pos)
{
	cube->menu.keybinds_button.status = \
	is_hover((t_int_point){300, 75}, (t_int_point){620, 190}, pos);
	cube->menu.video_settings_button.status = \
	is_hover((t_int_point){800, 75}, (t_int_point){1120, 190}, pos);
	cube->menu.music_and_sounds_button.status = \
		is_hover((t_int_point){1300, 75}, (t_int_point){1620, 190}, pos);
}

void	handle_mouse_in_menu(t_cube *cube, t_int_point pos)
{
	cube->menu.play_button.status = is_hover((t_int_point){780, 280}, \
		(t_int_point){1135, 400}, pos);
	cube->menu.settings_button.status = is_hover((t_int_point){780, 480}, \
		(t_int_point){1135, 600}, pos);
	cube->menu.exit_button.status = is_hover((t_int_point){780, 680}, \
		(t_int_point){1135, 800}, pos);
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
		if (is_hover(keybinds_pos[i], keybinds_pos[i + 1], pos))
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
