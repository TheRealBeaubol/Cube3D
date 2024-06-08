/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:19:57 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/31 17:36:12 by lboiteux         ###   ########.fr       */
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

	new_tab = ft_calloc(height + 1, sizeof(char *));
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

char	**read_map(t_map *map, char *file)
{
	int		i;
	int		fd;
	char	**tab;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	map->height = get_height(file);
	tab = ft_calloc(map->height + 1, sizeof(char *));
	i = 0;
	tab[i] = get_next_line(fd, 0);
	if (!tab[i])
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	while (tab[i])
	{
		i++;
		tab[i] = get_next_line(fd, 0);
	}
	return (tab);
}

char	**parsing(t_map *map, char *file)
{
	char	**tab;

	tab = read_map(map, file);
	if (!tab)
		return (NULL);
	tab = format_tab(tab, map->height);
	print_tab(tab);
	return (tab);
}
