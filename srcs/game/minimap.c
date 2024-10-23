/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:03:10 by lboiteux          #+#    #+#             */
/*   Updated: 2024/10/23 17:23:13 by lboiteux         ###   ########.fr       */
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
	while (dx < 30)
	{
		dy = 0;
		while (dy < 30)
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

void	print_minimap_pixel(int i, int j, t_cube *cube, t_int_point point)
{
	if (i < 0 || j < 0 || i >= cube->map.height - 1 || j >= cube->map.width)
		print_global_pixel(cube, point, 0xFFC1FF44);
	else if (cube->map.map[(int)i][(int)j] == '1')
		print_global_pixel(cube, point, 0xFFF6D902);
	else if (cube->map.map[(int)i][(int)j] == '0')
		print_global_pixel(cube, point, 0xFFFDF19A);
	else if (cube->map.map[(int)i][(int)j] == 'D')
		print_global_pixel(cube, point, 0xFF00FF00);
	else
		print_global_pixel(cube, point, 0xFFC1FF44);
}

void	draw_minimap(t_cube *cube)
{
	float		i;
	float		j;
	t_int_point	point;
	t_point		offset;

	offset.x = cube->settings.pos.x - floor((double)cube->settings.pos.x);
	offset.y = cube->settings.pos.y - floor((double)cube->settings.pos.y);
	point.y = (-30 * offset.y) - 10;
	i = floor((double)cube->settings.pos.y) - 5;
	while (i <= cube->map.height)
	{
		point.x = (WIDTH - 250) + (-30 * offset.x);
		j = floor((double)cube->settings.pos.x) - 4;
		while (j <= cube->map.width)
		{
			print_minimap_pixel(i, j, cube, point);
			point.x += 30;
			j += 1.0;
		}
		point.y += 30;
		i += 1.0;
	}
}
