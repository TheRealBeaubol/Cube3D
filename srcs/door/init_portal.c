/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_portal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:14:11 by mhervoch          #+#    #+#             */
/*   Updated: 2024/09/20 17:58:16 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
			if (cube->map.map[j][i] == 'M' && (portal->pos.x != i || \
portal->pos.y != j))
				find_out_pos(cube, i, j, portal);
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
				cube->map.portal[ind]->pos = (t_point){i, j};
				search_exit(cube, i, j, &cube->map.portal[ind++]);
			}
		}
	}
}
