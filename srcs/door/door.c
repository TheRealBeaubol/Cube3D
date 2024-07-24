/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:23:25 by mhervoch          #+#    #+#             */
/*   Updated: 2024/07/24 19:18:56 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_point	get_portal_pos(t_cube *cube)
{
	t_point	pos;
	int		i;
	int		j;

	j = -1;
	pos.x = 0;
	pos.y = 0;
	while (++j < cube->map.height)
	{
		i = -1;
		while (++i < cube->map.width)
		{
			if (cube->map.map[j][i] == 'P')
			{
				pos.x = i;
				pos.y = j;
				return (pos);
			}
		}
	}
	return (pos);
}

int	check_portal(t_cube *cube)
{
	int	i;

	i = -1;
	while (++i < cube->map.cpt_portal)
	{
		if (cube->settings.pos.x < cube->map.portal[i]->pos.x + 1 && cube->settings.pos.x > cube->map.portal[i]->pos.x && cube->settings.pos.y < cube->map.portal[i]->pos.y + 1 && cube->settings.pos.y > cube->map.portal[i]->pos.y)
			return (i);
	}
	return (-1);
}

void	set_new_player_pos(t_cube *cube)
{
	while (cube->map.map[(int)(cube->settings.pos.y)][(int)cube->settings.pos.x] == 'W' || cube->map.map[(int)(cube->settings.pos.y)][(int)cube->settings.pos.x] == 'E')
	{
		if (cube->map.map[(int)(cube->settings.pos.y + 0.5)][(int)cube->settings.pos.x] != '1')
			cube->settings.pos.y += 0.5;
		else if (cube->map.map[(int)(cube->settings.pos.y - 0.5)][(int)cube->settings.pos.x] != '1')
			cube->settings.pos.y -= 0.5;
		if (cube->map.map[(int)cube->settings.pos.y][(int)(cube->settings.pos.x + 0.5)] != '1')
			cube->settings.pos.x += 0.5;
		else if (cube->map.map[(int)cube->settings.pos.y][(int)(cube->settings.pos.x - 0.5)] != '1')
			cube->settings.pos.x -= 0.5;
	}
}

void	check_and_do_portal(t_cube *cube)
{
	int	type;

	type = check_portal(cube);
	if (type < 0)
		return ;
	if (cube->map.portal[type]->type == 0)
		cube->map_name = "map_test.cub";
	else if (cube->map.portal[type]->type == 1 || cube->map.portal[type]->type == 2)
	{
		cube->settings.pos.x = cube->map.portal[type]->out.x;
		cube->settings.pos.y = cube->map.portal[type]->out.y;
		set_new_player_pos(cube);
	}
}
