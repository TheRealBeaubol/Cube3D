/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:44:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/08 00:05:48 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**format_tab(char **tab, int height)
{
	int		i;
	int		j;
	char	**new_tab;

	new_tab = ft_calloc(height + 2, sizeof(char *));
	i = -1;
	while (tab[++i])
	{
		new_tab[i] = ft_calloc(ft_strlen(tab[i]) + 1, sizeof(char));
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '\n')
				new_tab[i][j] = '\0';
			else if (ft_iswhitespace(tab[i][j]))
				new_tab[i][j] = '1';
			else if (is_map_token(tab[i][j]))
				new_tab[i][j] = tab[i][j];
			else
				printf_and_exit("Unrecognized token while parsing map\n", 0);
		}
	}
	ft_free_tab(tab);
	return (new_tab);
}

void	parse_wall_textures_and_colors(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd, 0);
		if (!line)
			printf_and_exit("Error\n", fd);
		if (line[0] == 'C' || line[0] == 'F')
			get_colors(map, line);
		else if (((line[0] == 'N' || line[0] == 'S') && line[1] == 'O') || \
	(line[0] == 'W' && line[1] == 'E') || (line[0] == 'E' && line[1] == 'A'))
			get_wall_texture_path(line, map);
		else if (line[0] == '\n')
			i--;
		else
			printf_and_exit("Error\n", fd);
		free(line);
		i++;
	}
	if (!map->ceiling_color || !map->floor_color || !map->texture_paths[0] || \
!map->texture_paths[1] || !map->texture_paths[2] || !map->texture_paths[3])
		printf_and_exit("Error\n", fd);
}

char	**read_map(t_map *map, int fd)
{
	int		i;
	char	**tab;
	char	*tmp;

	parse_wall_textures_and_colors(map, fd);
	tmp = get_next_line(fd, 0);
	while (tmp[0] == '\n')
	{
		free(tmp);
		tmp = get_next_line(fd, 0);
	}
	i = 0;
	tab = ft_calloc(map->height + 1, sizeof(char *));
	if (!tab)
		printf_and_exit("Error\n", fd);
	tab[0] = ft_strdup(tmp);
	free(tmp);
	while (tab[i] && ++i < map->height)
		tab[i] = get_next_line(fd, 0);
	if (i <= 2)
		ft_free_tab(tab);
	if (i <= 2)
		printf_and_exit("Error\n", fd);
	return (tab);
}

void	get_map_data(t_map *map, char *map_name)
{
	char	**tab;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		printf_and_exit("Error\n", fd);
	tab = read_map(map, fd);
	if (!tab)
		printf_and_exit("Error\n", fd);
	get_next_line(fd, 1);
	close(fd);
	tab = format_tab(tab, map->height);
	print_tab(tab);
	map->map = tab;
}

int	parsing(t_cube *cube)
{
	t_map	map;

	map.height = get_height(cube->map_name);
	if (map.height <= 2)
	{
		ft_printf(HEIGHT_ERROR);
		exit(EXIT_FAILURE);
	}
	map.texture_paths = ft_calloc(5, sizeof(char *));
	get_map_data(&map, cube->map_name);
	map.width = get_width(map.map);
	cube->map = map;
	get_player_pos(cube);
	check_closed_map(cube->map.map);
	return (0);
}
