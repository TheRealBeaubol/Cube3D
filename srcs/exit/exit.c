/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:02:33 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/18 02:23:39 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_and_destroy(t_cube *cube)
{
	destroy_menu(cube);
	free(cube->menu->settings_menu->keys_images);
	free(cube->menu->settings_menu);
	free(cube->menu);
	free(cube->player_settings);
	mlx_destroy_image(cube->mlx_ptr, cube->img);
	mlx_destroy_window(cube->mlx_ptr, cube->window_ptr);
	mlx_destroy_display(cube->mlx_ptr);
	exit (0);
}

int	free_and_destroy_exit(int i, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (i == 0)
		free_and_destroy(cube);
	return (0);
}