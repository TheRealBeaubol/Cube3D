/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:11:15 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/04 10:36:05 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	is_wall(t_cube *cube, int i)
{
	int	i;
	int	j;

	i = (cube->player_settings->ray[i]->y - (HEIGHT - cube->map->size_case * cube->map->height) / 2) / cube->map->size_case;
	j = (cube->player_settings->pos_x - (WIDTH - cube->map->size_case * cube->map->width) / 2) / cube->map->size_case;
	if (cube->map->map[i][j] == '1')
		return (1);
	return (0);
}

char	*get_direction(t_cube *cube)
{
	int	dirx;
	int	diry;

	dirx = cube->player_settings->ray[0]->x - cube->player_settings->pos_x;
	diry = cube->player_settings->ray[0]->y - cube->player_settings->pos_y;
	if (abs(dirx > abs(diry)))
	{
		if (dirx > 0)
			return ("WEST");
		else
			return ("EAST");
	}
	else if (abs(dirx <= abs(diry)))
	{
		if (diry > 0)
			return ("NORTH");
		else
			return ("SOUTH");
	}
}

void	check_ray_north(t_cube *cube, int i)
{
	int	ox;
	int	oy;

	cube->player_settings->ray[i]->y = cube->player_settings->pos_y + cube->map->size_case;
	cube->player_settings->ray[i]->x = (cube->player_settings->pos_y - cube->player_settings->ray[i]->y) / -tan(cube->player_settings->looking_angle) + cube->player_settings->pos_x;
	oy = 50;
	ox = oy * tan(cube->player_settings->looking_angle);
	while (!is_wall(cube, i))
	{
		cube->player_settings->ray[i]->y += oy;
		cube->player_settings->ray[i]->x += ox;
	}
}

void	check_ray_south(t_cube *cube, int i)
{
	int	ox;
	int	oy;

	cube->player_settings->ray[i]->y = cube->player_settings->pos_y - cube->map->size_case;
	cube->player_settings->ray[i]->x = (cube->player_settings->pos_y - cube->player_settings->ray[i]->y) / -tan(cube->player_settings->looking_angle) + cube->player_settings->pos_x;
	oy = 50;
	ox = oy * tan(cube->player_settings->looking_angle);
	while (!is_wall(cube, i))
	{
		cube->player_settings->ray[i]->y += oy;
		cube->player_settings->ray[i]->x += ox;
	}
}

void	check_ray_west(t_cube *cube, int i)
{
	int	ox;
	int	oy;

	cube->player_settings->ray[i]->x = cube->player_settings->pos_x + cube->map->size_case;
	cube->player_settings->ray[i]->y = (cube->player_settings->pos_x - cube->player_settings->ray[i]->x) / -tan(cube->player_settings->looking_angle) + cube->player_settings->pos_y;
	oy = 50;
	ox = oy * tan(cube->player_settings->looking_angle);
	while (!is_wall(cube, i))
	{
		cube->player_settings->ray[i]->y += oy;
		cube->player_settings->ray[i]->x += ox;
	}
}

void	check_ray_east(t_cube *cube, int i)
{
	int	ox;
	int	oy;

	cube->player_settings->ray[i]->x = cube->player_settings->pos_x - cube->map->size_case;
	cube->player_settings->ray[i]->y = (cube->player_settings->pos_x - cube->player_settings->ray[i]->x) / -tan(cube->player_settings->looking_angle) + cube->player_settings->pos_y;
	oy = 50;
	ox = oy * tan(cube->player_settings->looking_angle);
	while (!is_wall(cube, i))
	{
		cube->player_settings->ray[i]->y += oy;
		cube->player_settings->ray[i]->x += ox;
	}
}

void	drawing_wall(t_cube *cube)
{
	int	i;
	int	j;
	int	begin;
	int	end;

	i = -1;
	while (cube->player_settings->ray[++i])
	{
		cube->player_settings->ray[i]->len = sqrt(powf(cube->player_settings->ray[i]->x - cube->player_settings->pos_x, 2) + powf(cube->player_settings->ray[i]->y - cube->player_settings->pos_y, 2));
		
		cube->player_settings->ray[i]->wall_height = (cube->map->size_case * HEIGHT) / cube->player_settings->ray[i]->len;
		begin = (HEIGHT / 2) - cube->player_settings->ray[i]->wall_height;
		end = (HEIGHT / 2) + cube->player_settings->ray[i]->wall_height;
		j = begin - 1;
		while(++j < end);
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, i, j, 0xFFCACAFF);
	}
}

void	search_looking(t_cube *cube)
{
	int	i;

	i = -1;
	init_ray(cube);
	while (cube->player_settings->ray[++i])
	{
		if (ft_strncmp(get_direction(cube), "NORTH", 5))
			check_ray_north(cube, i);
		if (ft_strncmp(get_direction(cube), "SOUTH", 5))
			check_ray_south(cube, i);
		if (ft_strncmp(get_direction(cube), "WEST", 4))
			check_ray_west(cube, i);
		if (ft_strncmp(get_direction(cube), "EAST", 4))
			check_ray_east(cube, i);
	}
	drawing_wall(cube);
}
