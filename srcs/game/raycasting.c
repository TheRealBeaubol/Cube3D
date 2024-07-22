/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:01:39 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/22 14:22:08 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_ray(t_player_settings *settings, t_ray *ray, int i)
{
	ray->camera_x = 2 * i / (float)WIDTH - 1;
	ray->ray_dir.x = settings->dir.x + settings->plane.x * ray->camera_x;
	ray->ray_dir.y = settings->dir.y + settings->plane.y * ray->camera_x;
	ray->pos = settings->pos;
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;
	ray->hit_wall = 0;
}

void	calculate_step_dir_and_init_sidedist(t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step_dir.x = -1;
		ray->side_dist.x = (ray->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_dir.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_dir.y = -1;
		ray->side_dist.y = (ray->pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_dir.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->delta_dist.y;
	}
}

void	draw_wall(int i, t_cube *cube, int start, int end)
{
	int	j;
	int	color;
	int	tex_y;

	j = start;
	cube->settings.ray[i]->tex_pos = (start - cube->settings.ray[i]->wall_offset - HEIGHT / 2 + \
cube->settings.ray[i]->wall_height / 2) * cube->settings.ray[i]->step;
	while (j < end)
	{
		tex_y = (int)cube->settings.ray[i]->tex_pos \
	& (cube->map.actual_texture.height - 1);
		cube->settings.ray[i]->tex_pos += cube->settings.ray[i]->step;
		color = cube->map.actual_texture.texture[tex_y * \
cube->map.actual_texture.width + cube->settings.ray[i]->tex_x];
		mlx_pixel_put(cube->mlx.ptr, cube->mlx.win, i, j, color);
		j++;
	}
}

void	texture_calculation(t_cube *cube, t_ray *ray)
{
	float	wall_x;

	if (ray->side == 0)
		wall_x = ray->pos.y + ray->lenght * ray->ray_dir.y;
	else
		wall_x = ray->pos.x + ray->lenght * ray->ray_dir.x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (float)cube->map.actual_texture.width);
	if ((ray->side == 0 && ray->ray_dir.x > 0) || \
	(ray->side == 1 && ray->ray_dir.y < 0))
		ray->tex_x = cube->map.actual_texture.width - ray->tex_x - 1;
	ray->step = 1.0 * cube->map.actual_texture.height / ray->wall_height;
}

int	*get_portal_texture(t_cube *cube, e_direction direction)
{
	int	**portal[4];
	static int	time = 0;
	static int	portal_index = 0;

	printf("Debug 1\n");
	portal[NORTH] = cube->map.no_portal;
	portal[SOUTH] = cube->map.so_portal;
	portal[EAST] = cube->map.ea_portal;
	portal[WEST] = cube->map.we_portal;
	if (time >= 50)
	{
		portal_index++;
		time = 0;
	}
	if (portal_index > 4)
		portal_index = 0;
	time++;
	printf("Debug 2\n");
	return(portal[direction][portal_index]);
}

void	do_rays(t_cube *cube, t_ray *ray, int i)
{
	int	start;
	int	end;

	init_ray(&cube->settings, ray, i);
	calculate_step_dir_and_init_sidedist(ray);
	perform_dda(ray, &cube->map, &cube->settings);
	if (ray->direction == NORTH)
		cube->map.actual_texture = cube->map.no_texture;
	else if (ray->direction == SOUTH)
		cube->map.actual_texture = cube->map.so_texture;
	else if (ray->direction == EAST)
		cube->map.actual_texture = cube->map.ea_texture;
	else if (ray->direction == WEST)
		cube->map.actual_texture = cube->map.we_texture;
	if (ray->hit_wall == 3 || ray->hit_wall == 2)
		cube->map.actual_texture.texture = get_portal_texture(cube, ray->direction);
    ray->wall_offset = (int)((-cube->settings.pitch) * HEIGHT);
	ray->wall_height = (int)(HEIGHT / ray->lenght);
	start = (int)((HEIGHT - (float)ray->wall_height) / 2 + \
ray->wall_offset);
	if (start < 0)
		start = 0;
	end = (int)((float)ray->wall_height / 2 + HEIGHT / 2 + \
ray->wall_offset);
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	texture_calculation(cube, ray);
	draw_wall(i, cube, start, end);
}
