/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:20 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/18 17:26:41 by mhervoch         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_cube	cube;

	check_args(ac, av);
	cube.map_name = av[1];
	init(&cube, 0);
	mlx_on_event((&cube)->mlx_ptr, (&cube)->window_ptr, MLX_WINDOW_EVENT, \
		&free_and_destroy_exit, &cube);
	mlx_on_event((&cube)->mlx_ptr, (&cube)->window_ptr, MLX_KEYDOWN, \
		&key_hook, &cube);
	mlx_on_event((&cube)->mlx_ptr, (&cube)->window_ptr, MLX_MOUSEDOWN, \
		&mouse_press, &cube);
	mlx_on_event((&cube)->mlx_ptr, (&cube)->window_ptr, MLX_MOUSEUP, \
		&mouse_release, &cube);
	mlx_loop_hook((&cube)->mlx_ptr, &mouse_move, &cube);
	mlx_loop(cube.mlx_ptr);
	return (0);
}
