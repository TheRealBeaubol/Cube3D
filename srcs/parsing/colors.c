/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:50:45 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 18:37:29 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_colors(char **colors)
{
	int	i;
	int	j;

	i = -1;
	while (colors[++i])
	{
		j = -1;
		while (colors[i][++j])
		{
			if (!ft_isdigit(colors[i][j]) || ft_strlen(colors[i]) > 3)
			{
				ft_free_tab(colors);
				return (0);
			}
		}
	}
	return (1);
}

unsigned long	convert_rgb_to_hexa(char **colors)
{
	int				r;
	int				g;
	int				b;
	unsigned long	color;

	if (!check_colors(colors))
		return (0);
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_free_tab(colors);
		return (0);
	}
	color = 0xFF000000;
	color += ((r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF));
	ft_free_tab(colors);
	return (color);
}

int	get_number_of_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

void	get_colors(t_map *map, char *str, int fd)
{
	char			**colors;
	unsigned long	color;

	if (!str || (str[0] != 'C' && str[0] != 'F') || str[1] != ' ')
	{
		free(str);
		return ;
	}
	colors = ft_str_split(str + get_number_of_spaces(str + 1) + 1, "\n,");
	if (!colors || ft_tablen(colors) != 3)
	{
		ft_free_tab(colors);
	}
	color = convert_rgb_to_hexa(colors);
	if (color == 0)
		exit_and_free_texture_paths(map->texture_paths, str, \
3, fd);
	if (str[0] == 'C')
		map->ceiling_color = color;
	if (str[0] == 'F')
		map->floor_color = color;
}
