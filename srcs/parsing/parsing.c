/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:44:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 18:40:29 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_parsing_map_and_exit(t_map *map, char **tab, char **new_tab)
{
	ft_free_tab(tab);
	ft_free_tab(new_tab);
	ft_free_tab(map->texture_paths);
	printf("\033[1;31mError\nUnrecognized token while parsing map\n\033[0m");
	exit(1);
}

void	fill_new_tab(char **tab, char **new_tab, t_map *map, int i)
{
	int	k;
	int	j;

	k = 0;
	j = -1;
	while (tab[i][++j])
	{
		if (tab[i][j] == '\n')
			new_tab[i][k] = '\0';
		else if (tab[i][j] == '\t')
		{
			new_tab[i][k] = '1';
			new_tab[i][k + 1] = '1';
			new_tab[i][k + 2] = '1';
			new_tab[i][k + 3] = '1';
			k += 3;
		}
		else if (ft_iswhitespace(tab[i][j]))
			new_tab[i][k] = '1';
		else if (is_map_token(tab[i][j]))
			new_tab[i][k] = tab[i][j];
		else
			free_parsing_map_and_exit(map, tab, new_tab);
		k++;
	}
}

char	**format_tab(char **tab, t_map *map)
{
	int		i;
	char	**new_tab;

	new_tab = ft_calloc(map->height + 2, sizeof(char *));
	i = -1;
	while (tab[++i])
	{
		new_tab[i] = ft_calloc(get_line_width(tab[i]) + 1, sizeof(char));
		fill_new_tab(tab, new_tab, map, i);
	}
	ft_free_tab(tab);
	return (new_tab);
}

void	parse_wall_textures_and_colors(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	map->texture_paths = ft_calloc(5, sizeof(char *));
	while (i < 6)
	{
		line = get_next_line(fd, 0);
		if (!line)
			exit_and_free_texture_paths(map->texture_paths, line, 1, fd);
		if (line[0] == 'C' || line[0] == 'F')
			get_colors(map, line, fd);
		else if (((line[0] == 'N' || line[0] == 'S') && line[1] == 'O') || \
	(line[0] == 'W' && line[1] == 'E') || (line[0] == 'E' && line[1] == 'A'))
			get_wall_texture_path(line, map);
		else if (line[0] == '\n')
			i--;
		else
			exit_and_free_texture_paths(map->texture_paths, line, 2, fd);
		free(line);
		i++;
	}
	if (!map->ceiling_color || !map->floor_color || !map->texture_paths[0] || \
!map->texture_paths[1] || !map->texture_paths[2] || !map->texture_paths[3])
		exit_and_free_texture_paths(map->texture_paths, NULL, 1, fd);
}

int	parsing(t_cube *cube)
{
	t_map	map;

	map.height = get_height(cube->map_name);
	if (map.height <= 2)
	{
		ft_printf("\033[1;31mError\nThe map is too small or missing\n\033[0m");
		exit(EXIT_FAILURE);
	}
	get_map_data(&map, cube->map_name);
	map.width = get_width(map.map);
	cube->map = map;
	get_player_pos(cube);
	if (check_closed_map(cube->map.map) == -1)
		free_init_and_exit(cube, NULL, 0);
	return (0);
}
