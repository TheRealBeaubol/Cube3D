/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:50:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/24 17:41:18 by lboiteux         ###   ########.fr       */
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

	texture_path = ft_strdup(str + get_number_of_spaces(str + 2) + 2);
	texture_path[ft_strlen(texture_path) - 1] = '\0';
	if (is_wall_texture(str) == 1)
		map->texture_paths[0] = ft_strdup(texture_path);
	if (is_wall_texture(str) == 2)
		map->texture_paths[1] = ft_strdup(texture_path);
	if (is_wall_texture(str) == 3)
		map->texture_paths[2] = ft_strdup(texture_path);
	if (is_wall_texture(str) == 4)
		map->texture_paths[3] = ft_strdup(texture_path);
	free(texture_path);
}
