/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_portal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:14:11 by mhervoch          #+#    #+#             */
/*   Updated: 2024/07/03 19:01:13 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	count_portal(t_cube *cube)
{
	int	i;
	int	j;
	
	j = -1;
	while (cube->map.map[++j])
	{
		i = -1;
		while (cube->map.map[j][++i])
		{
			if (cube->map.map[j][i] == 'P' || cube->map.map[j][i] == 'V' || cube->map.map[j][i] == 'M')
				cube->map.cpt_portal++;
		}
	}
	return (cube->map.cpt_portal);
}

void	set_type(t_cube *cube, int i, int j, t_portal *portal)
{
	if (cube->map.map[j][i] == 'P')
		portal->type = 0;
	if (cube->map.map[j][i] == 'V')
		portal->type = 1;
	if (cube->map.map[j][i] == 'M')
		portal->type = 2;
}

t_point	search_uni(t_cube *cube)
{
	t_point	out;
	int		i;
	int		j;

	j = -1;
	while (cube->map.map[++j])
	{
		i = -1;
		while (cube->map.map[j][++i])
		{
			if (cube->map.map[j][i] == 'O')
			{
				out.x = i;
				out.y = j;
			}
		}
	}
	return (out);
}

t_point	search_double(t_cube *cube, int ind)
{
	t_point	out;
	int		i;
	int		j;

	j = -1;
	while (cube->map.map[++j])
	{
		i = -1;
		while (cube->map.map[j][++i])
		{
			if (cube->map.map[j][i] == 'M' && i != cube->map.portal[ind]->pos.x && j != cube->map.portal[ind]->pos.y)
			{
				out.x = i;
				out.y = j;
			}
		}
	}
	return (out);
}

void	search_exit(t_cube *cube, int i, int j, int ind)
{
	if (cube->map.map[j][i] == 'M')
		cube->map.portal[ind]->out = search_double(cube, ind);
	if (cube->map.map[j][i] == 'V')
		cube->map.portal[ind]->out = search_uni(cube);
}

void	init_portal(t_cube *cube)
{
	int	i;
	int	j;
	int	ind;

	ind = 0;
	cube->map.cpt_portal = 0;
	count_portal(cube);
	cube->map.portal = calloc(cube->map.cpt_portal + 1, sizeof(t_portal *));
	i = -1;
	while (++i < cube->map.cpt_portal)
		cube->map.portal[i] = ft_calloc(1, sizeof(t_portal));
	j = -1;
	while (cube->map.map[++j])
	{
		i = -1;
		while (cube->map.map[j][++i])
		{
			if (cube->map.map[j][i] == 'P' || cube->map.map[j][i] == 'M' || cube->map.map[j][i] == 'V')
			{
				cube->map.portal[ind]->pos.x = i;
				cube->map.portal[ind]->pos.y = j;
				set_type(cube, i, j, cube->map.portal[ind]);
				if (cube->map.map[j][i] != 'P')
					search_exit(cube, i, j, ind);
				else
				{
					cube->map.portal[ind]->out.x = 0;
					cube->map.portal[ind]->out.y = 0;
				}
				ind++;
			}
		}
	}
}