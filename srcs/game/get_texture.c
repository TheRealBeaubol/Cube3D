/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:06:14 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 19:09:00 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*get_portal_texture(t_cube *cube, t_direction direction)
{
	static int	time = 0;
	static int	portal_index = 0;

	if (time >= 500)
	{
		portal_index++;
		time = 0;
	}
	if (portal_index > 11)
		portal_index = 0;
	time++;
	return (cube->map.portal_texture[direction][portal_index]);
}

void	get_actual_texture(t_cube *cube, t_ray *ray)
{
	if (ray->hit_wall == 3)
	{
		cube->map.actual_texture.texture = \
get_portal_texture(cube, ray->direction);
		cube->map.actual_texture.width = cube->map.no_texture.width;
		cube->map.actual_texture.height = cube->map.no_texture.height;
	}
	else if (ray->direction == NORTH)
		cube->map.actual_texture = cube->map.no_texture;
	else if (ray->direction == SOUTH)
		cube->map.actual_texture = cube->map.so_texture;
	else if (ray->direction == EAST)
		cube->map.actual_texture = cube->map.ea_texture;
	else if (ray->direction == WEST)
		cube->map.actual_texture = cube->map.we_texture;
}
