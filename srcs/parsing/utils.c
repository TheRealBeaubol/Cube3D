/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:47:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/29 12:44:20 by lboiteux         ###   ########.fr       */
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
	if (fd == -1)
		return (-1);
	str = get_next_line(fd, 0);
	while (str && ((str[0] == 'W' && str[1] == 'E') || (str[0] == 'N' && \
str[1] == 'O') || (str[0] == 'S' && str[1] == 'O') || (str[0] == 'E' && \
str[1] == 'A') || str[0] == 'C' || str[0] == 'F' || str[0] == '\n'))
	{
		free(str);
		str = get_next_line(fd, 0);
	}
	i = 1;
	while (str && str[0] != '\n')
	{
		free(str);
		str = get_next_line(fd, 0);
		i++;
	}
	close(fd);
	free(str);
	return (i);
}

void	init_spawn(t_player_settings *settings, char c)
{
	if (c == 'N' || c == 'S')
	{
		settings->dir.x = 0;
		settings->dir.y = 1;
		settings->plane.x = 0.66;
		settings->plane.y = 0;
	}
	if (c == 'N')
		settings->dir.y *= -1;
	if (c == 'S')
		settings->plane.x *= -1;
	if (c == 'E' || c == 'W')
	{
		settings->dir.x = 1;
		settings->dir.y = 0;
		settings->plane.x = 0;
		settings->plane.y = 0.66;
	}
	if (c == 'W')
	{
		settings->dir.x *= -1;
		settings->plane.y *= -1;
	}
}

void	get_player_pos(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map.map[i])
	{
		j = 0;
		while (cube->map.map[i][j])
		{
			if (!is_player(cube->map.map[i][j]))
			{
				cube->settings.pos.x = i + 0.5;
				cube->settings.pos.y = j + 0.5;
				init_spawn(&cube->settings, cube->map.map[i][j]);
				cube->map.map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
