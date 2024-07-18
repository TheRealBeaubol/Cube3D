/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:17:59 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/18 16:38:23 by lboiteux         ###   ########.fr       */
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
	cube->map.portal_texture1.image = mlx_png_file_to_image(cube->mlx.ptr, \
"./images/portal1.png", &cube->map.portal_texture1.width, &cube->map.portal_texture1.height);
	cube->map.portal_texture1.texture = ft_calloc(cube->map.portal_texture1.height * \
cube->map.portal_texture1.width, sizeof(int));
	map_wall_image(cube->mlx.ptr, &cube->map.portal_texture1);
	cube->map.portal_texture2.image = mlx_png_file_to_image(cube->mlx.ptr, \
"./images/portal2.png", &cube->map.portal_texture2.width, &cube->map.portal_texture2.height);
	cube->map.portal_texture2.texture = ft_calloc(cube->map.portal_texture2.height * \
cube->map.portal_texture2.width, sizeof(int));
	map_wall_image(cube->mlx.ptr, &cube->map.portal_texture2);
	cube->map.portal_texture3.image = mlx_png_file_to_image(cube->mlx.ptr, \
"./images/portal3.png", &cube->map.portal_texture3.width, &cube->map.portal_texture3.height);
	cube->map.portal_texture3.texture = ft_calloc(cube->map.portal_texture3.height * \
cube->map.portal_texture3.width, sizeof(int));
	map_wall_image(cube->mlx.ptr, &cube->map.portal_texture3);
	cube->map.portal_texture4.image = mlx_png_file_to_image(cube->mlx.ptr, \
"./images/portal4.png", &cube->map.portal_texture4.width, &cube->map.portal_texture4.height);
	cube->map.portal_texture4.texture = ft_calloc(cube->map.portal_texture4.height * \
cube->map.portal_texture4.width, sizeof(int));
	map_wall_image(cube->mlx.ptr, &cube->map.portal_texture4);
	cube->map.portal_animation = 0;
}
