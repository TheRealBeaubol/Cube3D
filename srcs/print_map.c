/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:33:56 by mhervoch          #+#    #+#             */
/*   Updated: 2024/06/10 18:51:06 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_global_pixel(t_cube *cube, int x, int y, int color)
{
	int	dx;
	int	dy;

	dx = 0;
	while (dx < cube->map->size_case)
	{
		dy = 0;
		while (dy < cube->map->size_case)
		{
			mlx_set_image_pixel(cube->mlx_ptr, cube->minimap_img, x + dx, y + dy, color);
			dy++;
		}
		dx++;
	}
}

int	is_in_wall(t_cube *cube)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	while (x < cube->map->player_size)
	{
		y = 0;
		while (y < cube->map->player_size)
		{
			i = (cube->player_settings->pos.y + y) / cube->map->size_case;
			j = (cube->player_settings->pos.x + x - (WIDTH - cube->map->size_case * cube->map->width)) / cube->map->size_case;
			if (cube->map->map[i][j] == '1')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void	print_player(t_cube *cube, int color)
{
	int	dx;
	int	dy;
	int	px;
	int	py;

	px = cube->player_settings->pos.x;
	py = cube->player_settings->pos.y;
	if (is_in_wall(cube))
	{
		if (cube->player_settings->move == 1)
		{
			cube->player_settings->pos.x += cube->player_settings->dir_x;
			cube->player_settings->pos.y += cube->player_settings->dir_y;
			px += cube->player_settings->dir_x;
			py += cube->player_settings->dir_y;
		}
		else if (cube->player_settings->move == 0)
		{
			cube->player_settings->pos.x -= cube->player_settings->dir_x;
			cube->player_settings->pos.y -= cube->player_settings->dir_y;
			px -= cube->player_settings->dir_x;
			py -= cube->player_settings->dir_y;
		}
		else if (cube->player_settings->move == 2)
		{
			cube->player_settings->pos.x -= cube->player_settings->dir_y;
			cube->player_settings->pos.y += cube->player_settings->dir_x;
			px -= cube->player_settings->dir_y;
			py += cube->player_settings->dir_x;
		}
		else if (cube->player_settings->move == 3)
		{
			cube->player_settings->pos.x += cube->player_settings->dir_y;
			cube->player_settings->pos.y -= cube->player_settings->dir_x;
			px += cube->player_settings->dir_y;
			py -= cube->player_settings->dir_x;
		}
	}
	dx = -1;
	while (++dx < cube->map->player_size)
	{
		dy = -1;
		while (++dy < cube->map->player_size)
			mlx_set_image_pixel(cube->mlx_ptr, cube->minimap_img, px + dx, py + dy, color);
	}
}

void	draw_background(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, x, y, 0xFF33EBFF);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, x, y, 0xFF7D9E7C);
			x++;
		}
		y++;
	}
}

void	print_map(t_cube *cube)
{
	int			i;
	int			j;
	int			x;
	int			y;
	static int	b = 1;

	y = 0;
	i = 0;
	while (cube->map->map[i])
	{
		x = WIDTH - cube->map->width * cube->map->size_case;
		j = 0;
		while (cube->map->map[i][j])
		{
			if (cube->map->map[i][j] == 'N' && b == 1)
			{
				cube->player_settings->pos.x = i;
				cube->player_settings->pos.y = j;
				b = 0;
			}
			else if (cube->map->map[i][j] == '1')
				print_global_pixel(cube, x, y, 0xFF0000FF);
			else if (cube->map->map[i][j] == '0')
				print_global_pixel(cube, x, y, 0xFFFFFFFF);
			else
				print_global_pixel(cube, x, y, 0xFFFFFFFF);
			x += cube->map->size_case;
			j++;
		}
		y += cube->map->size_case;
		i++;
	}
}

void	render_cube(t_cube *cube)
{
	int	i;

	i = -1;
	draw_background(cube);
	print_map(cube);
	print_player(cube, 0xFFFF0000);
	cube->player_settings->ray = ft_calloc(WIDTH + 1, sizeof(t_ray *));
	while (++i < WIDTH)
		cube->player_settings->ray[i] = ft_calloc(1, sizeof(t_ray));
	i = -1;
	while (++i < WIDTH)
		do_rays(cube, cube->player_settings->ray[i], i);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->img, 0, 0);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->minimap_img, 0, 0);
}
