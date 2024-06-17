/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:11:15 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/17 17:03:57 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"
#include <stdio.h>
void	init_ray(t_player_settings *player_settings, t_ray *ray, int i)
{
	ray->camera_x = 2 * i / (float)WIDTH - 1;
	ray->ray_dir_x = player_settings->dir_x + player_settings->plane.x * ray->camera_x;
	ray->ray_dir_y = player_settings->dir_y + player_settings->plane.y * ray->camera_x;
	// printf("ray_dir_x = %f\n", player_settings->dir_x);
	// printf("ray_dir_y = %f\n", player_settings->dir_y);
	// printf("plane.x = %f\n", player_settings->plane.x);
	// printf("plane.y = %f\n", player_settings->plane.y);
	// printf("camera_x = %f\n", ray->camera_x);
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->map_x = (int)player_settings->pos.x;
	ray->map_y = (int)player_settings->pos.y;
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
		if (map->map[ray->map_y][ray->map_x] == 'P' && (fabs(ray->map_x - player_settings->pos.x) > 2 || fabs(ray->map_y - player_settings->pos.y) > 2))
			ray->hit_wall = 2;
	}
	if (ray->side == 0)
		ray->lenght = (ray->map_x - player_settings->pos.x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->lenght = (ray->map_y - player_settings->pos.y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	// printf("ray->map_x = %d\n", ray->map_x);
	// printf("ray->map_y = %d\n", ray->map_y);
	// printf("ray->pos.x = %f\n", player_settings->pos.x);
	// printf("ray->pos.y = %f\n", player_settings->pos.y);
	// printf("ray->dir.x = %f\n", ray->ray_dir_x);
	// printf("ray->dir.y = %f\n", ray->ray_dir_y);
	// printf("ray->step_x = %d\n", ray->step_x);
	// printf("ray->step_y = %d\n", ray->step_y);
	// printf("ray->perp_wall_dist = %f\n", ray->lenght);
}

#include <stdio.h>
void	draw_wall(int i, t_cube *cube, t_ray *ray, int start, int end)
{
	int	j;
	int	color;
	int	tex_y;

	j = start;
	while (j < end)
	{
		tex_y = (int)ray->tex_pos & (cube->map->texture_height - 1);
		// printf("tex_pos = %f\n", ray->tex_pos);
		// printf("cube->map->texture = %d\n", cube->map->texture_height - 1);
		ray->tex_pos += ray->step;
		color = cube->map->actual_texture[tex_y * cube->map->texture_width + ray->tex_x];
		mlx_set_image_pixel(cube->mlx_ptr, cube->img, i, j, color);
		j++;
	}
}

void	texture_calculation(t_cube *cube, t_ray *ray, int start)
{
	int	wall_x;

	if (ray->side == 0)
		wall_x = \
cube->player_settings->pos.y + ray->lenght * ray->ray_dir_y;
	else
		wall_x = \
cube->player_settings->pos.x + ray->lenght * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (float)cube->map->texture_width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
		ray->tex_x = cube->map->texture_width - ray->tex_x - 1;
	ray->step = 1.0 * cube->map->texture_height / ray->wall_height;
	ray->tex_pos = (start - HEIGHT / 2 + ray->wall_height / 2) * ray->step;
}

void	do_rays(t_cube *cube, t_ray *ray, int i)
{
	int	start;
	int	end;

	init_ray(cube->player_settings, ray, i);
	calculate_step_and_init_sidedist(ray, cube->player_settings);
	perform_dda(ray, cube->map, cube->player_settings);
	if (ray->direction == NORTH)
	{
		cube->map->actual_texture = cube->map->north_texture;
		cube->map->texture_height = cube->map->no_texture.height;
		cube->map->texture_width = cube->map->no_texture.width;
	}
	if (ray->direction == SOUTH)
	{
		cube->map->actual_texture = cube->map->south_texture;
		cube->map->texture_height = cube->map->so_texture.height;
		cube->map->texture_width = cube->map->so_texture.width;
	}
	if (ray->direction == EAST)
	{
		cube->map->actual_texture = cube->map->east_texture;
		cube->map->texture_height = cube->map->ea_texture.height;
		cube->map->texture_width = cube->map->ea_texture.width;
	}
	if (ray->direction == WEST)
	{
		cube->map->actual_texture = cube->map->west_texture;
		cube->map->texture_height = cube->map->we_texture.height;
		cube->map->texture_width = cube->map->we_texture.width;
	}
	// printf("texture_height = %d\n", cube->map->texture_height);
	// printf("texture_width = %d\n", cube->map->texture_width);
	ray->wall_height = (int)(HEIGHT / ray->lenght);
	start = -ray->wall_height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = ray->wall_height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	texture_calculation(cube, ray, start);
	if (ray->direction == NORTH)
		printf("%d\n", end);
	draw_wall(i, cube, ray, start, end);
}
