/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:17:59 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 18:53:39 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	map_wall_image(t_cube *cube, t_image *img)
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
	cube->mlx.portal = ft_calloc(12, sizeof(t_image));
	init_textures(cube, &cube->mlx.portal[0], "./images/portal_0.png");
	init_textures(cube, &cube->mlx.portal[1], "./images/portal_1.png");
	init_textures(cube, &cube->mlx.portal[2], "./images/portal_2.png");
	init_textures(cube, &cube->mlx.portal[3], "./images/portal_3.png");
	init_textures(cube, &cube->mlx.portal[4], "./images/portal_4.png");
	init_textures(cube, &cube->mlx.portal[5], "./images/portal_5.png");
	init_textures(cube, &cube->mlx.portal[6], "./images/portal_6.png");
	init_textures(cube, &cube->mlx.portal[7], "./images/portal_7.png");
	init_textures(cube, &cube->mlx.portal[8], "./images/portal_8.png");
	init_textures(cube, &cube->mlx.portal[9], "./images/portal_9.png");
	init_textures(cube, &cube->mlx.portal[10], "./images/portal_10.png");
	init_textures(cube, &cube->mlx.portal[11], "./images/portal_11.png");
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
	init_textures(cube, &cube->mlx.player, "./images/player.png");
	i = -1;
	while (++i < 4)
		free(cube->map.texture_paths[i]);
	free(cube->map.texture_paths);
	init_portal_textures(cube);
	i = -1;
	while (++i < 12)
	{
		mlx_destroy_image(cube->mlx.ptr, cube->mlx.portal[i].image);
		free(cube->mlx.portal[i].texture);
	}
	free(cube->mlx.portal);
}
