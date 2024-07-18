/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:17:59 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/18 15:48:50 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	map_wall_image(void *mlx_ptr, t_image *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->width)
	{
		x = 0;
		while (x < img->height)
		{
			img->texture[y * img->width + x] = \
mlx_get_image_pixel(mlx_ptr, img->image, x, y);
			x++;
		}
		y++;
	}
}

void	init_textures(void	*mlx_ptr, t_image *img, char *path)
{
	img->image = mlx_png_file_to_image(mlx_ptr, path, &img->width, \
&img->height);
	free(path);
	img->texture = malloc(img->height * img->width * sizeof(int));
	map_wall_image(mlx_ptr, img);
}

void	preload_textures(t_cube *cube)
{
	init_textures(cube->mlx.ptr, &cube->map.we_texture, \
cube->map.texture_paths[0]);
	init_textures(cube->mlx.ptr, &cube->map.no_texture, \
cube->map.texture_paths[1]);
	init_textures(cube->mlx.ptr, &cube->map.so_texture, \
cube->map.texture_paths[2]);
	init_textures(cube->mlx.ptr, &cube->map.ea_texture, \
cube->map.texture_paths[3]);
	free(cube->map.texture_paths);
	cube->mlx.player.image = mlx_png_file_to_image(cube->mlx.ptr, \
"./images/player3.png", &cube->mlx.player.width, &cube->mlx.player.height);
	cube->mlx.player.texture = ft_calloc(cube->mlx.player.height * \
cube->mlx.player.width, sizeof(int));
	map_wall_image(cube->mlx.ptr, &cube->mlx.player);
	cube->map.portal_texture.image = mlx_png_file_to_image(cube->mlx.ptr, \
"./images/portal.png", &cube->map.portal_texture.width, &cube->map.portal_texture.height);
	cube->map.portal_texture.texture = ft_calloc(cube->map.portal_texture.height * \
cube->map.portal_texture.width, sizeof(int));
	map_wall_image(cube->mlx.ptr, &cube->map.portal_texture);
}
