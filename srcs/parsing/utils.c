/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:47:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 20:15:18 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_map_token(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' || \
	c == 'W' || c == 'E' || c == 'P' || c == 'D' \
	|| c == 'V' || c == 'M' || c == 'O');
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
	int		height;
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
	height = 1;
	while (str && str[0] != '\n' && height++)
	{
		free(str);
		str = get_next_line(fd, 0);
	}
	get_next_line(fd, 1);
	close(fd);
	free(str);
	return (height);
}

void	init_spawn(t_point *dir, t_point *plane, char c)
{
	if (c == 'N' || c == 'S')
	{
		dir->x = 0;
		dir->y = 1;
		plane->x = 0.66;
		plane->y = 0;
	}
	if (c == 'N')
		dir->y *= -1;
	if (c == 'S')
		plane->x *= -1;
	if (c == 'E' || c == 'W')
	{
		dir->x = 1;
		dir->y = 0;
		plane->x = 0;
		plane->y = 0.66;
	}
	if (c == 'W')
	{
		dir->x *= -1;
		plane->y *= -1;
	}
}

void	get_player_pos(t_cube *cube)
{
	static int	is_found;
	int			i;
	int			j;

	i = -1;
	while (cube->map.map[++i])
	{
		j = -1;
		while (cube->map.map[i][++j])
		{
			if (!is_player(cube->map.map[i][j]))
			{
				cube->settings.pos = (t_point){j + 0.5, i + 0.5};
				init_spawn(&cube->settings.dir, \
&cube->settings.plane, cube->map.map[i][j]);
				cube->map.map[i][j] = '0';
				is_found++;
			}
		}
	}
	if (is_found > 1)
		free_init_and_exit(cube, ERROR_MULTIPLE_SPAWN, 0);
	if (!is_found)
		free_init_and_exit(cube, ERROR_NO_SPAWN, 0);
}
