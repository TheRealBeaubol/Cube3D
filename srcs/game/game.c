/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:41:38 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/09 01:19:33 by lboiteux         ###   ########.fr       */
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
			if (is_in_circle(point.x + dx - (WIDTH - 5 * 50), point.y + dy, 125))
				mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, point.x + dx, point.y + dy, color);
			dy++;
		}
		dx++;
	}
}

void	print_map(t_cube *cube)
{
	float		i;
	float		j;
	t_int_point	point;
	t_point		offset;

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
			if (i < 0 || j < 0 || i >= cube->map.height - 1 || j >= cube->map.width)
				print_global_pixel(cube, point, 0xFF111111);
			else if (cube->map.map[(int)i][(int)j] == '1')
				print_global_pixel(cube, point, 0xFF0000FF);
			else if (cube->map.map[(int)i][(int)j] == '0')
				print_global_pixel(cube, point, 0xFFFFFFFF);
			else if (cube->map.map[(int)i][(int)j] == 'P')
				print_global_pixel(cube, point, 0xFF00FF00);
			else
				print_global_pixel(cube, point, 0xFF111111);
			point.x += 40;
			j += 1.0;
		}
		point.y += 40;
		i += 1.0;
	}
}

static void	draw_circle(int radius, t_int_point center, t_cube *cube, unsigned int color)
{
	t_int_point	p;
	t_int_point	d;

	d.y = -radius;
	while (d.y <= radius)
	{
		d.x = -radius;
		while (d.x <= radius)
		{
			if (d.x * d.x + d.y * d.y <= radius * radius)
			{
				p.x = center.x + d.x;
				p.y = center.y + d.y;
				mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, p.x, p.y, color);
			}
			d.x++;
		}
		d.y++;
	}
}

void	render_cube(t_cube *cube)
{
	int	i;

	mlx_clear_window(cube->mlx.ptr, cube->mlx.win);
	draw_background(cube);
	cube->settings.ray = ft_calloc(WIDTH + 1, sizeof(t_ray *));
	i = -1;
	while (++i < WIDTH)
		cube->settings.ray[i] = ft_calloc(1, sizeof(t_ray));
	i = -1;
	while (++i < WIDTH)
		do_rays(cube, cube->settings.ray[i], i);
	if (cube->settings.show_map)
	{
		draw_circle(130, (t_int_point){WIDTH - 3 * 50 + 25, 2.5 * 50}, cube, 0xFF000000);
		draw_circle(125, (t_int_point){WIDTH - 3 * 50 + 25, 2.5 * 50}, cube, 0xFF111111);
		print_map(cube);
		draw_circle(7, (t_int_point){WIDTH - 3 * 50 + 25, 2.5 * 50}, cube, 0xFF00FF00);
	}
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, \
cube->mlx.background_img, 0, 0);
}
