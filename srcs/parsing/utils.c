/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:47:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/18 23:59:47 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	i = 0;
	str = get_next_line(fd, 0);
	while (str)
	{
		free(str);
		str = get_next_line(fd, 0);
		i++;
	}
	close(fd);
	free(str);
	if (i > 8)
		return (i - 8);
	return (-1);
}
