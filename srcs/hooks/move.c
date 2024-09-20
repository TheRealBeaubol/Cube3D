/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:42:17 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/25 22:12:39 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_collisions(t_map *map, t_point pos)
{
	if (map->map[(int)pos.y][(int)pos.x] == '1')
		return (1);
	if (pos.x < 0 || pos.x >= map->width || pos.y < 0 || pos.y >= \
		map->height)
		return (1);
	return (0);
}

void	move_forward(t_cube *cube, double movespeed)
{
	t_point	new_pos;

	new_pos.x = cube->settings.pos.x + cube->settings.dir.x * movespeed;
	new_pos.y = cube->settings.pos.y + cube->settings.dir.y * movespeed;
	if (!check_collisions(&cube->map, (t_point) \
		{new_pos.x, cube->settings.pos.y}))
		cube->settings.pos.x = new_pos.x;
	if (!check_collisions(&cube->map, (t_point) \
		{cube->settings.pos.x, new_pos.y}))
		cube->settings.pos.y = new_pos.y;
}

void	move_backward(t_cube *cube, double movespeed)
{
	t_point	new_pos;

	new_pos.x = cube->settings.pos.x - cube->settings.dir.x * movespeed;
	new_pos.y = cube->settings.pos.y - cube->settings.dir.y * movespeed;
	if (!check_collisions(&cube->map, (t_point) \
		{new_pos.x, cube->settings.pos.y}))
		cube->settings.pos.x = new_pos.x;
	if (!check_collisions(&cube->map, (t_point) \
		{cube->settings.pos.x, new_pos.y}))
		cube->settings.pos.y = new_pos.y;
}

void	move_right(t_cube *cube, double movespeed)
{
	t_point	new_pos;

	new_pos.x = cube->settings.pos.x + cube->settings.plane.x * movespeed;
	new_pos.y = cube->settings.pos.y + cube->settings.plane.y * movespeed;
	if (!check_collisions(&cube->map, (t_point) \
		{new_pos.x, cube->settings.pos.y}))
		cube->settings.pos.x = new_pos.x;
	if (!check_collisions(&cube->map, (t_point) \
		{cube->settings.pos.x, new_pos.y}))
		cube->settings.pos.y = new_pos.y;
}

void	move_left(t_cube *cube, double movespeed)
{
	t_point	new_pos;

	new_pos.x = cube->settings.pos.x - cube->settings.plane.x * movespeed;
	new_pos.y = cube->settings.pos.y - cube->settings.plane.y * movespeed;
	if (!check_collisions(&cube->map, (t_point) \
		{new_pos.x, cube->settings.pos.y}))
		cube->settings.pos.x = new_pos.x;
	if (!check_collisions(&cube->map, (t_point) \
		{cube->settings.pos.x, new_pos.y}))
		cube->settings.pos.y = new_pos.y;
}
