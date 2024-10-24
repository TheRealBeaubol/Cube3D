/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:03:10 by lboiteux          #+#    #+#             */
/*   Updated: 2024/10/24 22:16:35 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_in_circle(int x, int y, int r)
{
	if ((x - r) * (x - r) + (y - r) * (y - r) <= r * r)
		return (1);
	return (0);
}

void	print_global_pixel(t_cube *cube, t_int_point point, int color)
{
	int	dx;
	int	dy;

	dx = 0;
	while (dx < 40)
	{
		dy = 0;
		while (dy < 40)
		{
			if (is_in_circle(point.x + dx - (\
WIDTH - 5 * 50), point.y + dy, 125))
				mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, \
point.x + dx, point.y + dy, color);
			dy++;
		}
		dx++;
	}
}

float	print_map_pixel(int i, int j, t_cube *cube, t_int_point point)
{
	int	line_width;

	if (i < 0 || j < 0)
	{
		print_global_pixel(cube, point, 0xFFC1FF44);
		return (1.0);
	}
	line_width = 0;
	while (cube->map.map[i][line_width])
		line_width++;
	if (j >= line_width)
		print_global_pixel(cube, point, 0xFFC1FF44);
	else if (cube->map.map[i][j] == '1')
		print_global_pixel(cube, point, 0xFFF6D902);
	else if (cube->map.map[i][j] == '0')
		print_global_pixel(cube, point, 0xFFFDF19A);
	else if (cube->map.map[i][j] == 'D')
		print_global_pixel(cube, point, 0xFF00FF00);
	else
		print_global_pixel(cube, point, 0xFFC1FF44);
	return (1.0);
}

void	draw_map(t_cube *cube)
{
	float		i;
	float		j;
	t_int_point	point;
	t_point		offset;

	draw_circle(130, (t_int_point){WIDTH - 3 * 50 + \
25, 2.5 * 50}, cube, 0xFFF69D02);
	draw_circle(125, (t_int_point){WIDTH - 3 * 50 + \
25, 2.5 * 50}, cube, 0xFFC1FF44);
	offset.x = cube->settings.pos.x - floor((double)cube->settings.pos.x);
	offset.y = cube->settings.pos.y - floor((double)cube->settings.pos.y);
	point.y = (0 - 40 * offset.y - 35);
	i = floor((double)cube->settings.pos.y) - 4;
	while (i <= cube->settings.pos.y + 4)
	{
		point.x = (WIDTH - (5 * 50) - 40 * offset.x - 35);
		j = floor((double)cube->settings.pos.x) - 4;
		while (j <= cube->settings.pos.x + 4)
		{
			j += print_map_pixel(i, j, cube, point);
			point.x += 40;
		}
		point.y += 40;
		i += 1.0;
	}
}
