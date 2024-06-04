/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:11:15 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/04 11:59:40 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_wall(t_cube *cube, int n)
{
	int	i;
	int	j;

	i = (cube->player_settings->ray[n]->y / cube->map->size_case);
	j = (cube->player_settings->ray[n]->x / cube->map->size_case);
	ft_printf("i = %d\n", i);
	ft_printf("j = %d\n", j);
	ft_printf("cube->player_settings->ray[n]->y = %d\n", cube->player_settings->ray[n]->y);
	ft_printf("cube->player_settings->ray[n]->x = %d\n", cube->player_settings->ray[n]->x);
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
	return (NULL);
}

void	check_ray_north(t_cube *cube, int i)
{
	int	ox;
	int	oy;

	cube->player_settings->ray[i]->y = cube->player_settings->pos_y + cube->map->size_case;
	cube->player_settings->ray[i]->x = (cube->player_settings->pos_y - cube->player_settings->ray[i]->y) / -tan(cube->player_settings->looking_angle) + cube->player_settings->pos_x;
	ft_printf("cube->player_settings->ray[i]->y = %d\n", cube->player_settings->ray[i]->y);
	ft_printf("cube->player_settings->ray[i]->x = %d\n", cube->player_settings->ray[i]->x);
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
		while(++j < end)
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, i, j, 0xFFCACAFF);
	}
}

void	find_player(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->map->map[++i])
	{
		j = -1;
		while (cube->map->map[i][++j])
		{
			if (cube->map->map[i][j] == 'N' || cube->map->map[i][j] == 'S' || cube->map->map[i][j] == 'W' || cube->map->map[i][j] == 'E')
			{
				cube->player_settings->pos_x = j * cube->map->size_case + cube->map->size_case / 2;
				cube->player_settings->pos_y = i * cube->map->size_case + cube->map->size_case / 2;
				if (cube->map->map[i][j] == 'N')
					cube->player_settings->looking_angle = 90;
				else if (cube->map->map[i][j] == 'S')
					cube->player_settings->looking_angle = 180;
				else if (cube->map->map[i][j] == 'W')
					cube->player_settings->looking_angle = 270;
				else if (cube->map->map[i][j] == 'E')
					cube->player_settings->looking_angle = 0;
			}
		}
	}
}

void	search_looking(t_cube *cube)
{
	int	i;

	i = -1;
	find_player(cube);
	cube->player_settings->ray = feed_ray_tab(cube->player_settings);
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
