/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:22:06 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 19:34:44 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int	main(int ac, char **av)
{
	t_cube			cube;

	check_args(ac, av);
	cube.map_name = av[1];
	printf("\033[1;32mParsing...\033[0m\n");
	if (parsing(&cube) == -1)
		return (-1);
	printf("\033[1;32mInitializing...\033[0m\n");
	init(&cube);
	hook(&cube);
	return (0);
}
