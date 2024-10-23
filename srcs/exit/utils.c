/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:26:20 by lboiteux          #+#    #+#             */
/*   Updated: 2024/10/23 17:21:13 by lboiteux         ###   ########.fr       */
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

void	printf_and_exit(char *str, int fd)
{
	close(fd);
	ft_dprintf(2, "%s\n", str);
	exit(EXIT_FAILURE);
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

void	free_parsing_map_and_exit(t_map *map, char **tab, char **new_tab)
{
	ft_free_tab(tab);
	ft_free_tab(new_tab);
	ft_free_tab(map->texture_paths);
	printf("\033[1;31mError\nUnrecognized token while parsing map\n\033[0m");
	exit(1);
}
