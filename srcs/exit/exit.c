/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:00:03 by lboiteux          #+#    #+#             */
/*   Updated: 2024/10/22 21:52:54 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exit_and_free_texture_paths(char **tab, char *line, int err, int fd)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (tab[i])
			free(tab[i]);
	}
	free(tab);
	free(line);
	get_next_line(fd, 1);
	if (err == 1)
		printf_and_exit(ERROR_MISSING_ELEMENT, fd);
	else if (err == 2)
		printf_and_exit(ERROR_UNRECOGNIZED_TOKEN, fd);
	else if (err == 3)
		printf_and_exit(ERROR_COLOR_FORMAT, fd);
}

void	free_init_and_exit(t_cube *cube, char *str, int i)
{
	ft_free_tab(cube->map.map);
	ft_free_tab(cube->map.texture_paths);
	if (i == 1 || i == 3)
		mlx_destroy_display(cube->mlx.ptr);
	if (i == 3)
		destroy_wall_textures(cube->mlx.ptr, &cube->map);
	if (i == 1 || i == 2 || i == 3)
	{
		i = -1;
		while (++i < cube->map.cpt_portal)
			free(cube->map.portal[i]);
		free(cube->map.portal);
	}
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	free_destroy_and_exit(t_cube *cube)
{
	int	i;

	i = -1;
	while (++i < cube->map.cpt_portal)
		free(cube->map.portal[i]);
	free(cube->map.portal);
	free_portal_textures(cube);
	mlx_destroy_image(cube->mlx.ptr, cube->mlx.player.image);
	free(cube->mlx.player.texture);
	free(cube->menu.sounds);
	destroy_menu_images(&cube->menu, cube->mlx.ptr);
	destroy_wall_textures(cube->mlx.ptr, &cube->map);
	ft_free_tab(cube->map.map);
	mlx_destroy_image(cube->mlx.ptr, cube->mlx.background_img);
	mlx_destroy_window(cube->mlx.ptr, cube->mlx.win);
	mlx_destroy_display(cube->mlx.ptr);
	exit(EXIT_SUCCESS);
}
