/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:24:05 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/24 19:08:04 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}

void	check_args(int ac, char **av)
{
	if (WIDTH != 1920 || HEIGHT != 1080)
	{
		ft_printf("\033[1;31mError\nResolution must be 1920x1080\n\033[0m");
		exit(1);
	}
	if (ac == 2)
	{
		if (!(ft_strlen(av[1]) > 4 && av[1][ft_strlen(av[1]) - 1] == 'b' && \
			av[1][ft_strlen(av[1]) - 2] == 'u' && \
			av[1][ft_strlen(av[1]) - 3] == 'c' && \
			av[1][ft_strlen(av[1]) - 4] == '.'))
		{
			ft_printf("\033[1;31mError\nMap file must be a .cub file\n\033[0m");
			exit(1);
		}
	}
	else
	{
		ft_printf("\033[1;31mError\nUsage: ./cub3D map.cub\n\033[0m");
		exit(1);
	}
}
