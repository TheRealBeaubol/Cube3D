/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:24:05 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/19 16:12:01 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_args(int ac, char **av)
{
	if (WIDTH != 1920 || HEIGHT != 1080)
	{
		ft_printf("Error\nResolution must be 1920x1080\n");
		exit(1);
	}
	if (ac == 2)
	{
		if (!(ft_strlen(av[1]) > 4 && av[1][ft_strlen(av[1]) - 1] == 'b' && \
			av[1][ft_strlen(av[1]) - 2] == 'u' && \
			av[1][ft_strlen(av[1]) - 3] == 'c' && \
			av[1][ft_strlen(av[1]) - 4] == '.'))
		{
			ft_printf("Error\nMap file must be a .cub file\n");
			exit(1);
		}
	}
	else
	{
		ft_printf("Error\nUsage: ./cub3D map.cub\n");
		exit(1);
	}
}
