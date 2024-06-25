/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:50:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/25 01:00:22 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_wall_texture(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 2] != 'g' || str[len - 3] != 'n' || \
str[len - 4] != 'p' || str[len - 5] != '.')
		return (-1);
	if (str[0] == 'W' && str[1] == 'E')
		return (1);
	if (str[0] == 'N' && str[1] == 'O')
		return (2);
	if (str[0] == 'S' && str[1] == 'O')
		return (3);
	if (str[0] == 'E' && str[1] == 'A')
		return (4);
	return (-1);
}

void	get_wall_texture_path(char *str, t_map *map)
{
	char	*texture_path;

	texture_path = ft_strdup(str + 3);
	texture_path[ft_strlen(texture_path) - 1] = '\0';
	if (is_wall_texture(str) == 1)
		map->texture_paths[0] = ft_strdup(texture_path);
	if (is_wall_texture(str) == 2)
		map->texture_paths[1] = ft_strdup(texture_path);
	if (is_wall_texture(str) == 3)
		map->texture_paths[2] = ft_strdup(texture_path);
	if (is_wall_texture(str) == 4)
		map->texture_paths[3] = ft_strdup(texture_path);
}

void	get_wall_texture(t_map *map, int fd)
{
	char	*str;
	int		i;

	i = -1;
	map->texture_paths = ft_calloc(5, sizeof(char *));
	str = get_next_line(fd, 0);
	while (++i < 4)
	{
		if (str && ft_strlen(str) > 7 && is_wall_texture(str))
			get_wall_texture_path(str, map);
		else
		{
			get_next_line(fd, 1);
			break ;
		}
		free(str);
		str = get_next_line(fd, 0);
	}
	free(str);
	if (!map->texture_paths[0] || !map->texture_paths[1] || \
!map->texture_paths[2] || !map->texture_paths[3])
	{
		ft_dprintf(2, ERROR_PATH);
		return ;
	}
}
