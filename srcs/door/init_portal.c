/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_portal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:14:11 by mhervoch          #+#    #+#             */
/*   Updated: 2024/09/10 17:56:15 by lboiteux         ###   ########.fr       */
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
			if (cube->map.map[j][i] == 'V' || cube->map.map[j][i] == 'M')
				cube->map.cpt_portal++;
		}
	}
	return (cube->map.cpt_portal);
}

void	set_type(t_cube *cube, int i, int j, t_portal *portal)
{
	if (cube->map.map[j][i] == 'V')
		portal->type = 1;
	if (cube->map.map[j][i] == 'M')
		portal->type = 2;
}

void	find_out_pos(t_cube *cube, int i, int j, t_portal *portal)
{
	if (cube->map.map[j][i + 1] == '0')
	{
		init_spawn(&portal->dir, &portal->plane, 'E');
		portal->out.x = i + 1.5;
		portal->out.y = j + 0.5;
	}
	else if (cube->map.map[j][i - 1] == '0')
	{
		init_spawn(&portal->dir, &portal->plane, 'W');
		portal->out.x = i - 0.5;
		portal->out.y = j + 0.5;
	}
	else if (cube->map.map[j + 1][i] == '0')
	{
		init_spawn(&portal->dir, &portal->plane, 'S');
		portal->out.x = i + 0.5;
		portal->out.y = j + 1.5;
	}
	else if (cube->map.map[j - 1][i] == '0')
	{
		init_spawn(&portal->dir, &portal->plane, 'N');
		portal->out.x = i + 0.5;
		portal->out.y = j - 0.5;
	}
}

void	search_uni(t_cube *cube, t_portal *portal)
{
	int		i;
	int		j;

	j = -1;
	while (cube->map.map[++j])
	{
		i = -1;
		while (cube->map.map[j][++i])
		{
			if (cube->map.map[j][i] == 'O')
				find_out_pos(cube, i, j, portal);
		}
	}
}

void	search_double(t_cube *cube, t_portal *portal)
{
	int		i;
	int		j;

	j = -1;
	while (cube->map.map[++j])
	{
		i = -1;
		while (cube->map.map[j][++i])
		{
			// printf("i = %d, j = %d\n", i, j);
			if (cube->map.map[j][i] == 'M')
				printf("M : ix = %f, jy = %f\n%d %d\n", portal->pos.x, portal->pos.y, i, j);
			if (cube->map.map[j][i] == 'M' && (portal->pos.x != i || portal->pos.y != j))
			{
				printf("Start : ix = %f, jy = %f\n", portal->out.x, portal->out.y);
				find_out_pos(cube, i, j, portal);
				printf("End : ix = %f, jy = %f\n", portal->out.x, portal->out.y);
			}
		}
	}
}

void	search_exit(t_cube *cube, int i, int j, t_portal **portal)
{
	if (cube->map.map[j][i] == 'M')
		search_double(cube, *portal);
	if (cube->map.map[j][i] == 'V')
		search_uni(cube, *portal);
}

void	init_portal(t_cube *cube)
{
	int	i;
	int	j;
	int	ind;

	ind = 0;
	cube->map.cpt_portal = 0;
	count_portal(cube);
	cube->map.portal = ft_calloc(cube->map.cpt_portal + 1, sizeof(t_portal *));
	i = -1;
	while (++i < cube->map.cpt_portal)
		cube->map.portal[i] = ft_calloc(1, sizeof(t_portal));
	j = -1;
	while (cube->map.map[++j])
	{
		i = -1;
		while (cube->map.map[j][++i])
		{
			if (cube->map.map[j][i] == 'M' || cube->map.map[j][i] == 'V')
			{
				set_type(cube, i, j, cube->map.portal[ind]);
				cube->map.portal[ind]->pos.x = i;
				cube->map.portal[ind]->pos.y = j;
				search_exit(cube, i, j, &cube->map.portal[ind]);
				printf("Portal %d : x = %f, y = %f\n", ind, cube->map.portal[ind]->pos.x, cube->map.portal[ind]->pos.y);
				printf("Portal %d : out x = %f, out y = %f\n", ind, cube->map.portal[ind]->out.x, cube->map.portal[ind]->out.y);
				ind++;
			}
		}
	}
}
