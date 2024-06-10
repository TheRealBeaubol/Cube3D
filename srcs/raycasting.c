/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:11:15 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/10 19:02:53 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
void	init_ray(t_player_settings *player_settings, t_ray *ray, int i)
{
	ray->camera_x = 2 * i / (float)WIDTH - 1;
	ray->ray_dir_x = player_settings->dir_x + player_settings->plane.x * ray->camera_x;
	ray->ray_dir_y = player_settings->dir_y + player_settings->plane.y * ray->camera_x;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->map_x = player_settings->pos.x;
	ray->map_y = player_settings->pos.y;
	ray->hit_wall = 0;
}

void	calculate_step_and_init_sidedist(t_ray *ray, t_player_settings *player_settings)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player_settings->pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player_settings->pos.x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player_settings->pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player_settings->pos.y) * ray->delta_dist_y;
	}
}

void	perform_dda(t_ray *ray, t_map *map, t_player_settings *player_settings)
{
	while (ray->hit_wall == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			if (ray->ray_dir_x < 0)
				ray->direction = WEST;
			else
				ray->direction = EAST;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			if (ray->ray_dir_y < 0)
				ray->direction = NORTH;
			else
				ray->direction = SOUTH;
			ray->side = 1;
		}
		if (map->map[ray->map_y][ray->map_x] == '1')
			ray->hit_wall = 1;
	}
	printf("map_x = %d, map_y = %d\n", ray->map_x, ray->map_y);
	printf("pos_x = %f, pos_y = %f\n", player_settings->pos.x, player_settings->pos.y);
	printf("ray_dir_x = %f, ray_dir_y = %f\n", ray->ray_dir_x, ray->ray_dir_y);
	printf("step_x = %d, step_y = %d\n", ray->step_x, ray->step_y);
	if (ray->side == 0)
		ray->lenght = (ray->map_x - player_settings->pos.x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->lenght = (ray->map_y - player_settings->pos.y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	printf("lenght = %f\n", ray->lenght);
}

void	do_rays(t_cube *cube, t_ray *ray, int i)
{
	int	start;
	int	end;

	init_ray(cube->player_settings, ray, i);
	calculate_step_and_init_sidedist(ray, cube->player_settings);
	perform_dda(ray, cube->map, cube->player_settings);
	ray->wall_height = (int)(HEIGHT / ray->lenght);
	start = -ray->wall_height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = ray->wall_height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	start -= 1;
	ft_printf("start = %d, end = %d\n", start, end);
	while (++start < end)
		mlx_pixel_put(cube->mlx_ptr, cube->window_ptr, i, start, 0xFFFF0000);
}

