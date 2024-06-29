/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:39:27 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/29 12:45:33 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_map_content(char c)
{
	return (c == '0' || c == '1' || c == '?' || c == 'P');
}

static void	check_wall(char **map, int i, int j)
{
	if (i && i < ft_tablen(map) - 1 && j && j < (int)ft_strlen(map[i]) - 1)
	{
		if (is_map_content(map[i - 1][j]) && is_map_content(map[i + 1][j]) && \
			is_map_content(map[i][j - 1]) && is_map_content(map[i][j + 1]))
			map[i][j] = '?';
	}
}

static int	remove_change(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '?')
				map[i][j] = '0';
			else if (map[i][j] == '0')
				return (0);
		}
	}
	return (1);
}

int	check_closed_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
				check_wall(map, i, j);
		}
	}
	if (!remove_change(map))
	{
		ft_printf("Errorcaca\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
