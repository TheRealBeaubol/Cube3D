/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:07:10 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/25 12:13:20 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	calculate_ray_lenght(t_ray *ray)
{
	if (ray->side == 0)
		ray->lenght = (ray->map.x - ray->pos.x + (1 - \
ray->step_dir.x) / 2) / ray->ray_dir.x;
	else
		ray->lenght = (ray->map.y - ray->pos.y + (1 - \
ray->step_dir.y) / 2) / ray->ray_dir.y;
}

void	update_side_distance(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map.x += ray->step_dir.x;
		if (ray->ray_dir.x < 0)
			ray->direction = EAST;
		else
			ray->direction = WEST;
		ray->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map.y += ray->step_dir.y;
		if (ray->ray_dir.y < 0)
			ray->direction = NORTH;
		else
			ray->direction = SOUTH;
		ray->side = 1;
	}
}

void	perform_dda(t_ray *ray, t_map *map)
{
	while (ray->hit_wall == 0)
	{
		update_side_distance(ray);
		if (map->map[ray->map.y][ray->map.x] == '1')
			ray->hit_wall = 1;
		if (map->map[ray->map.y][ray->map.x] == 'P' && (fabs(ray->map.x - \
ray->pos.x) > 2 || fabs(ray->map.y - ray->pos.y) > 2))
			ray->hit_wall = 2;
	}
	calculate_ray_lenght(ray);
}
