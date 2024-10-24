/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:41:38 by lboiteux          #+#    #+#             */
/*   Updated: 2024/10/24 21:48:37 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_circle(int radius, t_int_point center, \
	t_cube *cube, unsigned int color)
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

void	print_player(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (y < cube->mlx.player.width)
	{
		x = 0;
		while (x < cube->mlx.player.height)
		{
			if (cube->mlx.player.texture[(int)(y * \
cube->mlx.player.width + x)] != 0)
				mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, WIDTH - \
3 * 50 + x, 2.5 * 50 + y - 25, cube->mlx.player.texture[(int)(y * \
cube->mlx.player.width + x)]);
			x++;
		}
		y++;
	}
}

void	draw_crosshair(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, WIDTH / \
2 + i, HEIGHT / 2, 0xFF000000);
		mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, WIDTH / \
2 - i, HEIGHT / 2, 0xFF000000);
		mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, WIDTH / \
2, HEIGHT / 2 + i, 0xFF000000);
		mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, WIDTH / \
2, HEIGHT / 2 - i, 0xFF000000);
		i++;
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
		draw_map(cube);
		print_player(cube);
	}
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, \
cube->mlx.background_img, 0, 0);
	draw_crosshair(cube);
	i = -1;
	while (++i < WIDTH)
		free(cube->settings.ray[i]);
	free(cube->settings.ray);
}
