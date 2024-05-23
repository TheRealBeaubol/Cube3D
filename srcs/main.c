/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:20 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/23 15:19:37 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av, char **env)
{
	t_cube	cube;

	(void)ac;
	(void)av;
	(void)env;
	cube.map = av[1];
	if (WIDTH != 1920 || HEIGHT != 1080)
	{
		ft_printf("Error\nResolution must be 1920x1080\n");
		exit(1);
	}
	init(&cube);
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
