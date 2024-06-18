/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:23:25 by mhervoch          #+#    #+#             */
/*   Updated: 2024/06/18 17:25:22 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

t_point	get_portal_pos(t_cube *cube)
{
	t_point	pos;
	int		i;
	int		j;

	j = -1;
	pos.x = 0;
	pos.y = 0;
	while(++j < cube->map->height)
	{
		i = -1;
		while(++i < cube->map->width)
		{
			if (cube->map->map[j][i] == 'P')
			{
				pos.x = i;
				pos.y = j;
				return (pos);
			}
		}
	}
	return (pos);
}

int	check_portal(t_point point, t_cube *cube)
{
	if (cube->player_settings->pos.x  < point.x + 1 && cube->player_settings->pos.x  > point.x && cube->player_settings->pos.y  < point.y + 1 && cube->player_settings->pos.y  > point.y)
		return (1);
	return (0);
}

void	check_and_do_portal(t_cube *cube)
{
	t_point	pos_portal;
	
	pos_portal = get_portal_pos(cube);
	printf("player.x: %f | portal.x: %f\nplayer.y: %f | portal.y: %f\n", cube->player_settings->pos.x, pos_portal.x, cube->player_settings->pos.y, pos_portal.y);
	if (check_portal(pos_portal, cube))
	{
		cube->map_name = "map_test.cub";
		init(cube, 1);
	}
}
