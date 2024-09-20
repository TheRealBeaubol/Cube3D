/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:00:03 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 19:54:49 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	destroy_menu_images(t_menu *menu, void *mlx_ptr)
{
	const t_settings_menu_images	*img[4] = {&menu->play_button,
		&menu->settings_button, &menu->exit_button, \
		&menu->keybinds_define_button};
	int								i;

	i = -1;
	while (++i < 54)
		mlx_destroy_image(mlx_ptr, menu->keys[i].img);
	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(mlx_ptr, img[i]->img);
		mlx_destroy_image(mlx_ptr, img[i]->img_hover);
	}
	mlx_destroy_image(mlx_ptr, menu->keybinds_menu.img);
	mlx_destroy_image(mlx_ptr, menu->background);
}

void	destroy_wall_textures(void *mlx_ptr, t_map *map)
{
	mlx_destroy_image(mlx_ptr, map->we_texture.image);
	mlx_destroy_image(mlx_ptr, map->no_texture.image);
	mlx_destroy_image(mlx_ptr, map->so_texture.image);
	mlx_destroy_image(mlx_ptr, map->ea_texture.image);
	free(map->we_texture.texture);
	free(map->no_texture.texture);
	free(map->so_texture.texture);
	free(map->ea_texture.texture);
}

void	free_portal_textures(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 12)
			free(cube->map.portal_texture[i][j]);
		free(cube->map.portal_texture[i]);
	}
	free(cube->map.portal_texture);
}

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
