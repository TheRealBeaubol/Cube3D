/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:20 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/06 20:57:24 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av, char **env)
{
	t_cube	cube;

	(void)ac;
	(void)av;
	(void)env;
	init(&cube);
	mlx_on_event((&cube)->mlx_ptr, (&cube)->window_ptr, MLX_WINDOW_EVENT, \
		&free_and_destroy_exit, &cube);
	mlx_on_event((&cube)->mlx_ptr, (&cube)->window_ptr, MLX_KEYDOWN, \
		&key_hook, &cube);
	mlx_loop_hook((&cube)->mlx_ptr, &mouse_move, &cube);
	mlx_loop(cube.mlx_ptr);
	return (0);
}
