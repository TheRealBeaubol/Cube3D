/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:00:32 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/31 17:43:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_width(char **map)
{
	int	width;
	int	i;

	i = 0;
	width = ft_strlen(map[i]);
	while (map[++i])
	{
		if ((int)ft_strlen(map[i]) > width)
			width = ft_strlen(map[i]);
	}
	return (width);
}

int	get_height(char *file)
{
	char	*str;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	i = 0;
	str = get_next_line(fd, 0);
	while (str)
	{
		free(str);
		str = get_next_line(fd, 0);
		i++;
	}
	close(fd);
	return (i);
}

t_map	*init_map(char	*map_name)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	map->map = parsing(map, map_name);
	if (!map->map)
	{
		free(map);
		return (NULL);
	}
	map->width = get_width(map->map);
	map->size_case = 20;
	map->player_size = 4;
	return (map);
}
