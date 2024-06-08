/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:33:56 by mhervoch          #+#    #+#             */
/*   Updated: 2024/06/08 17:08:35 by lboiteux         ###   ########.fr       */
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
			i = (cube->player_settings->pos.y + y - (HEIGHT - cube->map->size_case * cube->map->height) / 2) / cube->map->size_case;
			j = (cube->player_settings->pos.x + x - (WIDTH - cube->map->size_case * cube->map->width) / 2) / cube->map->size_case;
			if (cube->map->map[i][j] == '1')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

#include <stdio.h>

t_point	get_hit_pos(t_cube *cube, t_ray *ray)
{
	t_point	hit_pos;
	int		x;
	int		y;

	hit_pos.x = ray->coor.x;
	hit_pos.y = ray->coor.y;
	x = (hit_pos.x - (WIDTH - cube->map->size_case * cube->map->width) / 2) / cube->map->size_case;
	y = (hit_pos.y - (HEIGHT - cube->map->size_case * cube->map->height) / 2) / cube->map->size_case;
	while (cube->map->map[y][x] != '1')
	{
		x = (hit_pos.x - (WIDTH - cube->map->size_case * cube->map->width) / 2) / cube->map->size_case;
		y = (hit_pos.y - (HEIGHT - cube->map->size_case * cube->map->height) / 2) / cube->map->size_case;
		if (cube->map->map[y][x] != '1')
		{
			hit_pos.x += ray->dir_x;
			hit_pos.y += ray->dir_y;
		}
	}
	return (hit_pos);
}

void	free_ray(t_ray **ray, int size)
{
	int	i;

	i = -1;
	(void) size;
	if (!ray)
		return ;
	while (ray[++i])
		free(ray[i]);
	free(ray);
}
#include <stdio.h>
t_ray	**init_ray(t_cube *cube)
{
	t_ray	**ray;
	int		i;
	
	free_ray(cube->player_settings->ray, WIDTH + 1);
	ray = ft_calloc(WIDTH + 1, sizeof(t_ray *));
	if (!ray)
		return (NULL);
	i = -1;
	while (++i < WIDTH)
	{
		ray[i] = ft_calloc(1, sizeof(t_ray));
		if (!ray[i])
			return (NULL);
	}
	i = -1;
	while (++i < WIDTH)
	{
		if (!i)
			ray[0]->angle = cube->player_settings->looking_angle;
		else if (i == WIDTH / 2)
			ray[i]->angle = cube->player_settings->looking_angle - 0.1;
		else if (i > WIDTH / 2)
			ray[i]->angle = ray[i - 1]->angle - 0.1;
		else
			ray[i]->angle = ray[i - 1]->angle + 0.1;
		if (ray[i]->angle > 2 * PI)
			ray[i]->angle -= 2 * PI;
		if (ray[i]->angle < 0)
			ray[i]->angle += 2 * PI;
		ray[i]->dir_x = cos(ray[i]->angle);
		ray[i]->dir_y = sin(ray[i]->angle);
		ray[i]->coor = cube->player_settings->pos;
		ray[i]->coor = get_hit_pos(cube, ray[i]);
		ray[i]->distance = sqrt(pow(cube->player_settings->pos.x - ray[i]->coor.x, 2) + pow(cube->player_settings->pos.y - ray[i]->coor.y, 2));
		printf("ray[%d]->distance : %f\n", i, ray[i]->distance);
	}
	return (ray);
}

void	plotray(t_cube *cube)
{
	int	i;

	i = -1;
	while (++i < cube->player_settings->fov)
		plotline(cube, cube->player_settings->ray[i]->coor, cube->player_settings->pos);
}

void	print_ray(t_cube *cube)
{
	cube->player_settings->ray = init_ray(cube);
	cube->player_settings->pos.x += cube->map->player_size / 2;
	cube->player_settings->pos.y += cube->map->player_size / 2;
	plotray(cube);
	cube->player_settings->pos.x -= cube->map->player_size / 2;
	cube->player_settings->pos.y -= cube->map->player_size / 2;
}

void	draw_wall(t_cube *cube)
{
	int	x;
	int	y;
	int	start;
	int	end;
	
	x = -1;
	while (++x < WIDTH)
	{
		ft_printf("x : %d\n", x);
		cube->player_settings->ray[x]->wall_height = (cube->map->size_case * 100) / cube->player_settings->ray[x]->distance;
		start = 100 / 2 - cube->player_settings->ray[x]->wall_height / 2;
		end = 100 / 2 + cube->player_settings->ray[x]->wall_height / 2;
		y = start - 1;
		while (++y < end)
		{
			// ft_printf("y : %d\n", y);
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, x, y, 0xFF00FF00);
			// ft_printf("y : %d\n", y);
		}
	}
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
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, px + dx, py + dy, color);
	}
	print_ray(cube);
	draw_wall(cube);
}

void	set_player(t_cube *cube, int x, int y)
{
	cube->player_settings->pos.x = x + 20;
	cube->player_settings->pos.y = y + 20;
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
	else if (pixel == 'N' && b)
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
