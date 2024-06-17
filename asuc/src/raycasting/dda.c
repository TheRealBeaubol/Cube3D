/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:58:08 by asuc              #+#    #+#             */
/*   Updated: 2024/06/17 15:54:49 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_raycasting.h"

static inline int	is_within_map_bounds(t_ray *ray, t_map *map)
{
	return (ray->map_x >= 0 && ray->map_x < map->cols && ray->map_y >= 0
		&& ray->map_y < map->rows);
}

static inline int	has_reached_max_distance(t_ray *ray, int max_distance)
{
	return (fabs(ray->pos.x - ray->map_x) > max_distance || fabs(ray->pos.y
			- ray->map_y) > max_distance);
}

static inline void	update_ray_position(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

static inline void	calculate_perpendicular_distance(t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map_x - ray->pos.x + (1 - ray->step_x) / 2)
			/ ray->dir.x;
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y - ray->pos.y + (1 - ray->step_y) / 2)
			/ ray->dir.y;
	}
	// printf("ray->map_x = %d\n", ray->map_x);
	// printf("ray->map_y = %d\n", ray->map_y);
	// printf("ray->pos.x = %f\n", ray->pos.x);
	// printf("ray->pos.y = %f\n", ray->pos.y);
	// printf("ray->dir.x = %f\n", ray->dir.x);
	// printf("ray->dir.y = %f\n", ray->dir.y);
	// printf("ray->step_x = %d\n", ray->step_x);
	// printf("ray->step_y = %d\n", ray->step_y);
	// printf("ray->perp_wall_dist = %f\n", ray->perp_wall_dist);
}

inline void	perform_dda(t_ray *ray, t_map *map)
{
	int	max_distance;

	max_distance = sqrt(WIN_WIDTH * WIN_WIDTH + WIN_HEIGHT * WIN_HEIGHT) + 1;
	while (ray->hit == 0)
	{
		update_ray_position(ray);
		if (is_within_map_bounds(ray, map)
			&& map->map[ray->map_y][ray->map_x] == '1')
		{
			ray->hit = 1;
		}
		else if (has_reached_max_distance(ray, max_distance))
		{
			ray->hit = 2;
			break ;
		}
	}
	if (ray->hit == 1)
	{
		calculate_perpendicular_distance(ray);
	}
	else if (ray->hit == 2)
	{
		ray->perp_wall_dist = max_distance;
	}
}
