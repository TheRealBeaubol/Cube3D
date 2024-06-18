/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:34:29 by asuc              #+#    #+#             */
/*   Updated: 2024/06/18 13:38:08 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_raycasting.h"

inline void	init_ray(t_ray *ray, t_player *player, float camera_x)
{
	ray->pos = player->pos;
	ray->dir.x = player->dir.x + player->plane.x * camera_x;
	ray->dir.y = player->dir.y + player->plane.y * camera_x;
	// if (x % 10 == 0)
	// {
	// 	printf("[%d] ", x);
	// 	printf("ray->dir.x = %f	|	", ray->dir.x);
	// 	printf("ray->dir.y = %f\n", ray->dir.y);
	// }
	// printf("player->dir.x = %f\n", player->dir.x);
	// printf("player->dir.y = %f\n", player->dir.y);
	// printf("player->plane.x = %f\n", player->plane.x);
	// printf("player->plane.y = %f\n", player->plane.y);
	// printf("camera_x = %f\n", camera_x);
	ray->map_x = (int)ray->pos.x;
	ray->map_y = (int)ray->pos.y;
	ray->delta_dist_x = fabs(1 / ray->dir.x);
	ray->delta_dist_y = fabs(1 / ray->dir.y);
	ray->hit = 0;
}

inline void	calculate_step_and_side_dist(t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos.x) * ray->delta_dist_x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos.y) * ray->delta_dist_y;
	}
}

inline int	*select_texture(t_ray_params *params, t_sprite *sprite)
{
	if (params->ray.side == 0)
	{
		if (params->ray.dir.x > 0)
		{
			params->texture_height = sprite->wall_e.height;
			params->texture_width = sprite->wall_e.width;
			return (sprite->east_texture);
		}
		params->texture_height = sprite->wall_w.height;
		params->texture_width = sprite->wall_w.width;
		return (sprite->west_texture);
	}
	else
	{
		if (params->ray.dir.y > 0)
		{
			params->texture_height = sprite->wall_s.height;
			params->texture_width = sprite->wall_s.width;
			return (sprite->south_texture);
		}
		params->texture_height = sprite->wall_n.height;
		params->texture_width = sprite->wall_n.width;
		return (sprite->north_texture);
	}
}

inline void	calculate_wall_x_and_tex_x(t_ray *ray, t_ray_params *params)
{
	if (ray->side == 0)
		params->wall_x = ray->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		params->wall_x = ray->pos.x + ray->perp_wall_dist * ray->dir.x;
	params->wall_x -= floor(params->wall_x);
	printf("params->tex_x = %d\n", params->tex_x);
	params->tex_x = (int)(params->wall_x * (float)params->texture_width);
	printf("params->tex_x = %d\n", params->tex_x);
	if ((ray->side == 0 && ray->dir.x > 0) || (ray->side == 1
			&& ray->dir.y < 0))
		params->tex_x = params->texture_width - params->tex_x - 1;
}
