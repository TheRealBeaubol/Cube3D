/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:02:33 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/05 22:26:06 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_and_destroy(t_cube *cube)
{
	mlx_destroy_image(cube->mlx_ptr, cube->img);
	mlx_destroy_window(cube->mlx_ptr, cube->window_ptr);
	mlx_destroy_display(cube->mlx_ptr);
	exit (1);
}

int	free_and_destroy_exit(int i, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (i == 0)
		free_and_destroy(cube);
	return (0);
}
