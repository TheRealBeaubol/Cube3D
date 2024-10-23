/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:22:51 by lboiteux          #+#    #+#             */
/*   Updated: 2024/10/23 17:23:21 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
