/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:33:56 by mhervoch          #+#    #+#             */
/*   Updated: 2024/05/30 15:19:07 by mhervoch         ###   ########.fr       */
/*   Updated: 2024/05/28 17:23:28 by lboiteux         ###   ########.fr       */
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
	while (dx < cube->map_data->size_case)
	{
		dy = 0;
		while (dy < cube->map_data->size_case)
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
	while (x < cube->map_data->player_size)
	{
		j = (cube->player_settings->pos_x + x - WIDTH / 2 + 50 * 7 / 2) / 50;
		y = 0;
		while (y < cube->map_data->player_size)
		{
			i = (cube->player_settings->pos_y + y - (HEIGHT - cube->map_data->size_case * cube->map_data->size_y) / 2) / 50;
			j = (cube->player_settings->pos_x + x - (WIDTH - cube->map_data->size_case * cube->map_data->size_x) / 2) / 50;
			if (cube->map_data->map[i][j] == '1')
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
	dx = 1;
	dx = 0;
	while (dx < cube->map_data->player_size)
	{
		dy = 0;
		while (dy < cube->map_data->player_size)
		{
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, px + dx, py + dy, color);
			dy++;
		}
		dx++;
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

	y = HEIGHT / 2 - cube->map_data->size_y * cube->map_data->size_case / 2;
	i = 0;
	while (cube->map_data->map[i])
	{
		x = WIDTH / 2 - cube->map_data->size_x * cube->map_data->size_case / 2;
		j = 0;
		while (cube->map_data->map[i][j + 1])
		{

			print_pixel(cube, map[i][j], x, y);
			x += 50;
			j++;
		}
		y += 50;
		i++;
	}
	print_player(cube, 0xFFFF0000);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->img, 0, 0);
}
