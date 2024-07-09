/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:20:58 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/10 00:21:06 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_first_background(t_cube *cube)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				mlx_set_image_pixel(cube->mlx.ptr, cube->mlx.background_img, x, y, cube->map.ceiling_color);
			else
				mlx_set_image_pixel(cube->mlx.ptr, cube->mlx.background_img, x, y, cube->map.floor_color);
		}
	}
}

void	draw_on_image(t_cube *cube, unsigned long color, float pos_y, int start_y)
{
	int		pos_x;

	while (++pos_y <= start_y)
	{
		pos_x = -1;
		while (++pos_x < WIDTH)
		{
			if (pos_y < HEIGHT && pos_y >= 0 && pos_x < WIDTH && pos_x >= 0)
				mlx_set_image_pixel(cube->mlx.ptr, cube->mlx.background_img, pos_x, pos_y, color);
		}
	}
}

void	draw_background(t_cube *cube)
{
	int			pitch_shift;
	int			start_y;
	float		pos_y;
	static int	prev_pitch_shift = 0;

	pitch_shift = (int)((cube->settings.pitch) * HEIGHT);
	if (pitch_shift > prev_pitch_shift)
	{
		start_y = HEIGHT / 2 - prev_pitch_shift;
		pos_y  = HEIGHT / 2 - pitch_shift;
	}
	else
	{
		start_y = HEIGHT / 2 - pitch_shift;
		pos_y = HEIGHT / 2 - prev_pitch_shift;
	}
	if (pitch_shift > prev_pitch_shift)
		draw_on_image(cube, cube->map.floor_color, pos_y - 1, start_y);
	else
		draw_on_image(cube, cube->map.ceiling_color, pos_y - 1, start_y);
	prev_pitch_shift = pitch_shift;
}

int	is_player(char c)
{
	return (c != 'N' && c != 'S' && c != 'E' && c != 'W');
}
