/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:28:47 by mhervoch          #+#    #+#             */
/*   Updated: 2024/05/06 21:26:57 by mhervoch         ###   ########.fr       */
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

/*void	ft_free_tab(void **tab)
{
	void	**tmp;

	if (!tab)
		return ;
	tmp = tab;
	while (*tmp)
		free(*(tmp++));
	free(tab);
}*/

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
