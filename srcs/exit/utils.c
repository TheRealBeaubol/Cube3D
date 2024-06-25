/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:26:20 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/20 02:19:03 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	printf_and_exit(char *str, int fd)
{
	close(fd);
	ft_dprintf(2, "%s\n", str);
	exit(EXIT_FAILURE);
}

void	free_init_and_exit(t_cube *cube, char *str, int i)
{
	ft_free_tab(cube->map.map);
	ft_free_tab(cube->map.texture_paths);
	if (i)
		mlx_destroy_display(cube->mlx.ptr);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	free_destroy_and_exit(t_cube *cube)
{
	mlx_destroy_image(cube->mlx.ptr, cube->map.we_texture.image);
	mlx_destroy_image(cube->mlx.ptr, cube->map.no_texture.image);
	mlx_destroy_image(cube->mlx.ptr, cube->map.so_texture.image);
	mlx_destroy_image(cube->mlx.ptr, cube->map.ea_texture.image);
	ft_free_tab(cube->map.map);
	free(cube->map.we_texture.texture);
	free(cube->map.no_texture.texture);
	free(cube->map.so_texture.texture);
	free(cube->map.ea_texture.texture);
	mlx_destroy_image(cube->mlx.ptr, cube->mlx.background_img);
	mlx_destroy_window(cube->mlx.ptr, cube->mlx.win);
	mlx_destroy_display(cube->mlx.ptr);
	exit(EXIT_SUCCESS);
}
