/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:18:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:19 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_map(char **tab)
{
	int	i;

	i = -1;
	ft_printf("\n\033[1;34m+");
	while (++i != (int)ft_strlen(tab[0]) + 2)
		ft_printf("=");
	ft_printf("+\n|");
	i = -1;
	while (++i != (int)ft_strlen(tab[0]) / 2)
		ft_printf(" ");
	ft_printf("\033[1;31mMAP\033[1;34m");
	i += 3;
	while (++i != (int)ft_strlen(tab[0]) + 3)
		ft_printf(" ");
	ft_printf("|\n");
	i = -1;
	while (tab[++i])
		ft_printf("| \033[0m%s \033[1;34m|\n", tab[i]);
	i = -1;
	ft_printf("+");
	while (++i != (int)ft_strlen(tab[0]) + 2)
		ft_printf("=");
	ft_printf("+\n\n");
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
	tab[0] = ft_strdup(tmp);
	free(tmp);
	while (tab[i] && ++i < map->height)
		tab[i] = get_next_line(fd, 0);
	return (tab);
}

void	get_map_data(t_map *map, char *map_name)
{
	char	**tab;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		printf_and_exit("\033[1;31mError\nMap file \
cannot be opened\n\033[0m", fd);
	tab = read_map(map, fd);
	get_next_line(fd, 1);
	close(fd);
	tab = format_tab(tab, map);
	print_map(tab);
	map->map = tab;
}

int	get_line_width(char *str)
{
	int	width;

	width = 0;
	while (*str && *str != '\n')
	{
		width++;
		if (*str == '\t')
			width += 3;
		str++;
	}
	return (width);
}
