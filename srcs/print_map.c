/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:33:56 by mhervoch          #+#    #+#             */
/*   Updated: 2024/06/04 11:47:13 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*void	print_wall(t_cube *cube, char pixel, int x, int y)
{	
}*/

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
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, x + dx, y + dy, color);
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
			i = (cube->player_settings->pos_y + y - (HEIGHT - cube->map->size_case * cube->map->height) / 2) / cube->map->size_case;
			j = (cube->player_settings->pos_x + x - (WIDTH - cube->map->size_case * cube->map->width) / 2) / cube->map->size_case;
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

	cube->player_settings->pos_x += cube->player_settings->dir_x;
	cube->player_settings->pos_y += cube->player_settings->dir_y;
	px = cube->player_settings->pos_x;
	py = cube->player_settings->pos_y;
	if (is_in_wall(cube))
	{
		cube->player_settings->pos_x -= cube->player_settings->dir_x;
		cube->player_settings->pos_y -= cube->player_settings->dir_y;
		px -= cube->player_settings->dir_x;
		py -= cube->player_settings->dir_y;
	}
	dx = -1;
	while (++dx < cube->map->player_size)
	{
		dy = -1;
		while (++dy < cube->map->player_size)
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, px + dx, py + dy, color);
	}
	cube->player_settings->dir_x = 0;
	cube->player_settings->dir_y = 0;
}

void	set_player(t_cube *cube, int x, int y)
{
	cube->player_settings->pos_x = x + 20;
	cube->player_settings->pos_y = y + 20;
}

/*void	print_ray(t_cube *cube, int x, int y)
{
	
}

void	print_view(t_cube *cube, int x, int y)
{
	int	i;
	
	plane = 0;
	cube->player_settings->ray->dirX = 200;
	cube->player_settings->ray->dirY = 200;
	i = -1;
	while (++i < cube->player_settings->ray_nb)
	{
		print_ray(cube, x, y);
		cube->player_settings->ray->planeX += 10;
		cube->player_settings->ray->planeY += 10;
	}
}*/

void	print_pixel(t_cube *cube, char pixel, int x, int y)
{
	static int	b = 1;

	if (pixel == '1')
		print_global_pixel(cube, x, y, 0xFF0000FF);
	else if (pixel == '0')
		print_global_pixel(cube, x, y, 0xFFFFFFFF);
	else if (pixel == 'P' && b)
	{
		b = 0;
		print_global_pixel(cube, x, y, 0xFFFFFFFF);
		set_player(cube, x, y);
	}
	else
		print_global_pixel(cube, x, y, 0xFFFFFFFF);
}

void	print_map(char **map, t_cube *cube)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = HEIGHT / 2 - cube->map->height * cube->map->size_case / 2;
	i = 0;
	while (cube->map->map[i])
	{
		x = WIDTH / 2 - cube->map->width * cube->map->size_case / 2;
		j = 0;
		while (cube->map->map[i][j])
		{
			print_pixel(cube, map[i][j], x, y);
			x += cube->map->size_case;
			j++;
		}
		y += cube->map->size_case;
		i++;
	}
	print_player(cube, 0xFFFF0000);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->img, 0, 0);
}
