/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:26:20 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/07 23:55:30 by lboiteux         ###   ########.fr       */
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

void	destroy_menu_images(t_menu *menu, void *mlx_ptr)
{
	const t_settings_menu_images	*img[7] = {&menu->play_button,
		&menu->settings_button, &menu->exit_button, &menu->keybinds_button, \
		&menu->video_settings_button, &menu->music_and_sounds_button, \
		&menu->keybinds_define_button};
	int	i;

	i = -1;
	while (++i < 54)
		mlx_destroy_image(mlx_ptr, menu->keys[i].img);
	i = -1;
	while (++i < 7)
	{
		mlx_destroy_image(mlx_ptr, img[i]->img);
		mlx_destroy_image(mlx_ptr, img[i]->img_hover);
	}
	mlx_destroy_image(mlx_ptr, menu->video_settings_menu.img);
	mlx_destroy_image(mlx_ptr, menu->music_and_sounds_menu.img);
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

void	free_destroy_and_exit(t_cube *cube)
{
	destroy_menu_images(&cube->menu, cube->mlx.ptr);
	destroy_wall_textures(cube->mlx.ptr, &cube->map);
	ft_free_tab(cube->map.map);
	mlx_destroy_image(cube->mlx.ptr, cube->mlx.background_img);
	mlx_destroy_window(cube->mlx.ptr, cube->mlx.win);
	mlx_destroy_display(cube->mlx.ptr);
	exit(EXIT_SUCCESS);
}
