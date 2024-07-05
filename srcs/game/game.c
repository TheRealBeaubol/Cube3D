/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:41:38 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/05 19:57:59 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_in_circle(int x, int y, int r)
{
	if ((x - r) * (x - r) + (y - r) * (y - r) <= r * r)
		return (1);
	return (0);
}

void	print_global_pixel(t_cube *cube, int x, int y, int color)
{
	int	dx;
	int	dy;

	dx = 0;
	while (dx < 50)
	{
		dy = 0;
		while (dy < 50)
		{
			if (is_in_circle(x + dx - (WIDTH - 5 * 50) , y + dy, 125))
				mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, x + dx, y + dy, color);
			dy++;
		}
		dx++;
	}
}

void	print_player(t_cube *cube, int color)
{
	int	dx;
	int	dy;
	int	px;
	int	py;

	px = WIDTH - (2 * 50);
	py = (2 * 50);
	dx = 13;
	while (++dx < 37)
	{
		dy = 13;
		while (++dy < 37)
			mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, px + \
dx, py + dy, color);
	}
}

void	print_map(t_cube *cube)
{
	int			i;
	int			j;
	int			save_i;
	int			save_j;
	t_int_point	point;

	i = (int)cube->settings.pos.y - 3;
	j = (int)cube->settings.pos.x - 3;
	save_i = i + 5;
	save_j = j + 5;
	point.y = 0;
	while (++i < save_i)
	{
		point.x = WIDTH - (5 * 50);
		j = save_j - 6;
		while (++j < save_j)
		{
			if (i < 0 || j < 0 || i >= cube->map.height || j >= cube->map.width)
				print_global_pixel(cube, point.x, point.y, 0x00000000);
			else if (cube->map.map[i][j] == '1')
				print_global_pixel(cube, point.x, point.y, 0xFF0000FF);
			else if (cube->map.map[i][j] == '0')
				print_global_pixel(cube, point.x, point.y, 0xFFFFFFFF);
			else if (cube->map.map[i][j] == 'P')
				print_global_pixel(cube, point.x, point.y, 0xFF00FF00);
			else
				print_global_pixel(cube, point.x, point.y, 0x00000000);
			point.x += 50;
		}
		point.y += 50;
	}
}

void	render_cube(t_cube *cube)
{
	int	i;

	mlx_clear_window(cube->mlx.ptr, cube->mlx.win);
	cube->settings.ray = ft_calloc(WIDTH + 1, sizeof(t_ray *));
	i = -1;
	while (++i < WIDTH)
		cube->settings.ray[i] = ft_calloc(1, sizeof(t_ray));
	i = -1;
	while (++i < WIDTH)
		do_rays(cube, cube->settings.ray[i], i);
	print_map(cube);
	print_player(cube, 0xFF00FF00);
	draw_background(cube);
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, \
cube->mlx.background_img, 0, 0);
}
