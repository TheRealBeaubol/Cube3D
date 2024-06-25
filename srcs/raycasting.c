/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:11:15 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/25 15:56:59 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	#include <stdio.h>
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
		//printf("map x: %d\n", ray->map_x);
		//printf("map y: %d\n", ray->map_y);

		/*if (map->map[ray->map_y][ray->map_x] == 'P')
		{
			printf("map_case: %c\n", map->map[ray->map_y][ray->map_x]);
			printf("diff x: %f\n", fabs(ray->map_x - player_settings->pos.x));
			printf("diff y: %f\n", fabs(ray->map_y - player_settings->pos.y));
		}*/
		if (map->map[ray->map_y][ray->map_x] == 'D' && (fabs(ray->map_x - player_settings->pos.x) > 2 || fabs(ray->map_y - player_settings->pos.y) > 2))
			ray->hit_wall = 2;
		if (map->map[ray->map_y][ray->map_x] == 'P' || map->map[ray->map_y][ray->map_x] == 'S' || map->map[ray->map_y][ray->map_x] == 'W')
			ray->hit_wall = 3;
	}
	if (ray->side == 0)
		ray->lenght = (ray->map_x - player_settings->pos.x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->lenght = (ray->map_y - player_settings->pos.y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
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
	while (++start < end)
	{
		if (ray->hit_wall == 3)
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, i, start, 0xFF000000);
		else if (ray->hit_wall == 2)
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, i, start, 0xFFFFFFFF);
		else
		{
			if (ray->direction == NORTH)
				mlx_set_image_pixel(cube->mlx_ptr, cube->img, i, start, 0xFF00FF00);
			else if (ray->direction == SOUTH)
				mlx_set_image_pixel(cube->mlx_ptr, cube->img, i, start, 0xFFFF0000);
			else if (ray->direction == WEST)
				mlx_set_image_pixel(cube->mlx_ptr, cube->img, i, start, 0xFF0000FF);
			else if (ray->direction == EAST)
				mlx_set_image_pixel(cube->mlx_ptr, cube->img, i, start, 0xFFFFFF00);
		}
	}
}

void	texture_calculation(t_cube *cube, t_ray *ray)
{
//	int	tex_num;
	int	tex_x;

	// mlx_get_image_pixel(cube->mlx_ptr, cube->map->north_texture, cube->texture[x][y], x, y, &ray->color);
	//tex_num = cube->map->map[ray->map_y][ray->map_x] - 1;
	if (ray->side == 0)
		ray->wall_x = \
cube->player_settings->pos.y + ray->lenght * ray->ray_dir_y;
	else
		ray->wall_x = \
cube->player_settings->pos.x + ray->lenght * ray->ray_dir_x;
	if (ray->wall_x < 0)
		ray->wall_x += 1;
	if (ray->wall_x >= 1)
		ray->wall_x -= 1;
	tex_x = (int)(ray->wall_x * (double)64);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = 64 - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = 64 - tex_x - 1;
}
