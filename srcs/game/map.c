/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:03:10 by lboiteux          #+#    #+#             */
/*   Updated: 2024/10/23 02:26:02 by lboiteux         ###   ########.fr       */
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

void	print_map_pixel(int i, int j, t_cube *cube, t_int_point point)
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

void	draw_map(t_cube *cube)
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
			print_map_pixel(i, j, cube, point);
			point.x += 30;
			j += 1.0;
		}
		point.y += 30;
		i += 1.0;
	}
}

void	print_square(t_cube *cube, t_int_point point, int color)
{
	int	dx;
	int	dy;

	dx = 0;
	while (dx < cube->map.tile_size)
	{
		dy = 0;
		while (dy < cube->map.tile_size)
		{
			if (point.x + dx >= 0 && point.y + dy >= 0 && point.x + dx < \
WIDTH && point.y + dy < HEIGHT)
				mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, point.x + dx + \
cube->map.map_padding.x, point.y + dy + cube->map.map_padding.y, color);
			dy++;
		}
		dx++;
	}
}

void	draw_player(t_cube *cube)
{
	t_int_point	point;
	t_int_point	dpoint;
	int			goofy_patch;

	goofy_patch = 0;
	if (cube->map.tile_size < 50)
		goofy_patch = 1;
	point.y = -1;
	while (++point.y < cube->mlx.player.height)
	{
		point.x = -1;
		while (++point.x < cube->mlx.player.width)
		{
			dpoint.x = (cube->settings.pos.x) * cube->map.tile_size - 20 + \
point.x;
			dpoint.y = (cube->settings.pos.y - goofy_patch) * \
cube->map.tile_size - 20 + point.y;
			if (cube->mlx.player.texture[(int)(point.y * \
cube->mlx.player.height + point.x)] != 0)
				mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, dpoint.x + \
cube->map.map_padding.x, dpoint.y + cube->map.map_padding.y, \
cube->mlx.player.texture[(int)(point.y * cube->mlx.player.height + point.x)]);
		}
	}
}

void	draw_full_map(t_cube *cube)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < cube->map.height - 1)
	{
		j = -1;
		while (++j < cube->map.width)
		{
			if (cube->map.map[i][j] == '1')
				color = 0xFFF6D902;
			else if (cube->map.map[i][j] == '0')
				color = 0xFFFDF19A;
			else if (cube->map.map[i][j] == 'D')
				color = 0xFF00FF00;
			else
				color = 0xFFA1FF14;
			print_square(cube, (t_int_point){j * \
cube->map.tile_size, i * cube->map.tile_size}, color);
		}
	}
	draw_player(cube);
}
