/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:47:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/28 23:02:32 by lboiteux         ###   ########.fr       */
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
