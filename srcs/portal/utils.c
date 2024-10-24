/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:57:41 by lboiteux          #+#    #+#             */
/*   Updated: 2024/10/24 21:34:58 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	if (j && j < cube->map.height - 2 && i && i < cube->map.width - 1)
	{
		if (cube->map.map[j][i + 1] == '0')
		{
			init_spawn(&portal->dir, &portal->plane, 'E');
			portal->out = (t_point){i + 1.5, j + 0.5};
		}
		else if (cube->map.map[j][i - 1] == '0')
		{
			init_spawn(&portal->dir, &portal->plane, 'W');
			portal->out = (t_point){i - 0.5, j + 0.5};
		}
		else if (cube->map.map[j + 1][i] == '0')
		{
			init_spawn(&portal->dir, &portal->plane, 'S');
			portal->out = (t_point){i + 0.5, j + 1.5};
		}
		else if (cube->map.map[j - 1][i] == '0')
		{
			init_spawn(&portal->dir, &portal->plane, 'N');
			portal->out = (t_point){i + 0.5, j - 0.5};
		}
	}
	else
		free_init_and_exit(cube, ERROR_PORTAL_ACCESS, 0);
}
