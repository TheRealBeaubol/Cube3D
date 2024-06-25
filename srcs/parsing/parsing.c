/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:44:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/24 22:28:51 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}

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
			else
				new_tab[i][j] = tab[i][j];
		}
	}
	ft_free_tab(tab);
	return (new_tab);
}

char	**read_map(t_map *map, int fd)
{
	int		i;
	char	**tab;

	i = 0;
	get_wall_texture(map, fd);
	get_colors(map, fd);
	get_colors(map, fd);
	tab = ft_calloc(map->height + 2, sizeof(char *));
	if (!tab)
		printf_and_exit("Error\n", fd);
	tab[0] = get_next_line(fd, 0);
	free(tab[0]);
	i = 0;
	tab[i] = get_next_line(fd, 0);
	while (tab[i++])
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
	get_map_data(&map, cube->map_name);
	map.width = get_width(map.map);
	cube->map = map;
	return (0);
}
