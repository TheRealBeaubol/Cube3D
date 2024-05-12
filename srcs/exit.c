/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:02:33 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/12 23:30:45 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_and_destroy(t_cube *cube)
{
	mlx_destroy_image(cube->mlx_ptr, cube->menu->play_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->exit_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->play_button_hover);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_button_hover);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->exit_button_hover);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->start_background);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->keybinds_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->keybinds_button_hover);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->video_settings_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->video_settings_button_hover);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->music_and_sounds_button);
	mlx_destroy_image(cube->mlx_ptr, cube->menu->settings_menu->music_and_sounds_button_hover);
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
