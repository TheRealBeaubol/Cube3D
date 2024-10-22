/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:17:59 by lboiteux          #+#    #+#             */
/*   Updated: 2024/10/22 20:25:10 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	map_wall_image(t_cube *cube, t_image *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			img->texture[y * img->width + x] = \
mlx_get_image_pixel(cube->mlx.ptr, img->image, x, y);
			x++;
		}
		y++;
	}
}

void	init_textures(t_cube *cube, t_image *img, char *path)
{
	img->width = 0;
	img->height = 0;
	img->image = mlx_png_file_to_image(cube->mlx.ptr, path, &img->width, \
&img->height);
	img->texture = ft_calloc(img->height * img->width, sizeof(int));
	map_wall_image(cube, img);
	free(path);
}

int	**init_portal_wall_sprite(t_cube *cube, int **wall, t_image *img)
{
	int	i;

	i = -1;
	wall = ft_calloc(12, sizeof(int *));
	while (++i < 12)
	{
		wall[i] = ft_calloc(img->height * img->width, sizeof(int));
		fill_wall_sprite(cube, wall, i, img);
	}
	return (wall);
}

void	init_portal_textures(t_cube *cube)
{
	int	i;

	cube->mlx.portal = ft_calloc(12, sizeof(t_image));
	i = -1;
	while (++i < 12)
		init_textures(cube, &cube->mlx.portal[i], \
ft_strjoin("./images/portal_", ".png", ft_itoa(i), 0b100));
	cube->map.portal_texture = ft_calloc(4, sizeof(int **));
	cube->map.portal_texture[NORTH] = init_portal_wall_sprite(\
	cube, cube->map.portal_texture[NORTH], &cube->map.no_texture);
	cube->map.portal_texture[SOUTH] = init_portal_wall_sprite(\
cube, cube->map.portal_texture[SOUTH], &cube->map.so_texture);
	cube->map.portal_texture[EAST] = init_portal_wall_sprite(\
cube, cube->map.portal_texture[EAST], &cube->map.ea_texture);
	cube->map.portal_texture[WEST] = init_portal_wall_sprite(\
cube, cube->map.portal_texture[WEST], &cube->map.we_texture);
}

void	preload_textures(t_cube *cube)
{
	int	i;

	init_textures(cube, &cube->map.no_texture, cube->map.texture_paths[0]);
	init_textures(cube, &cube->map.so_texture, cube->map.texture_paths[1]);
	init_textures(cube, &cube->map.we_texture, cube->map.texture_paths[2]);
	init_textures(cube, &cube->map.ea_texture, cube->map.texture_paths[3]);
	if ((cube->map.no_texture.width != cube->map.no_texture.height) || (\
cube->map.so_texture.width != cube->map.so_texture.height) || (\
cube->map.we_texture.width != cube->map.we_texture.height) || (\
cube->map.ea_texture.width != cube->map.ea_texture.height) || (\
cube->map.no_texture.width != cube->map.so_texture.width) || (\
cube->map.no_texture.width != cube->map.we_texture.width) || (\
cube->map.no_texture.width != cube->map.ea_texture.width))
		free_init_and_exit(cube, "Error\nTextures are not consistent\n", 3);
	free(cube->map.texture_paths);
	init_textures(cube, &cube->mlx.player, ft_strdup("./images/player.png"));
	init_portal_textures(cube);
	i = -1;
	while (++i < 12)
	{
		mlx_destroy_image(cube->mlx.ptr, cube->mlx.portal[i].image);
		free(cube->mlx.portal[i].texture);
	}
	free(cube->mlx.portal);
}
