/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:28:47 by mhervoch          #+#    #+#             */
/*   Updated: 2024/06/10 14:48:46 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_map_stock(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

char	**parsing(char *file)
{
	int		i;
	int		fd;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * 8);
	while (i < 7)
	{
		map[i] = get_next_line(fd, 0);
		i++;
	}
	map[i] = 0;
	return (map);
}
