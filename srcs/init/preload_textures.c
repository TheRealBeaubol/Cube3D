/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:17:59 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/23 15:22:45 by lboiteux         ###   ########.fr       */
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
	int	x;
	int	y;

	i = -1;
	wall = ft_calloc(13, sizeof(int *));
	while (++i < 12)
	{
		wall[i] = ft_calloc(img->height * img->width, sizeof(int));
		y = -1;
		while (++y < img->width)
		{
			
			x = -1;
			while (++x < img->height)
			{
				if ((x < cube->mlx.portal[i].height && y < cube->mlx.portal[i].width) && (cube->mlx.portal[i].texture[y * img->width + x] != 0))
				{
					wall[i][y * img->width + x] = \
cube->mlx.portal[i].texture[y * img->width + x];
				}
				else
				{
					wall[i][y * img->width + x] = \
img->texture[y * img->width + x];

				}
			}
		}
	}
	return (wall);
}

void	preload_textures(t_cube *cube)
{
	init_textures(cube, &cube->map.no_texture, cube->map.texture_paths[0]);
	init_textures(cube, &cube->map.so_texture, cube->map.texture_paths[1]);
	init_textures(cube, &cube->map.we_texture, cube->map.texture_paths[2]);
	init_textures(cube, &cube->map.ea_texture, cube->map.texture_paths[3]);
	ft_free_tab(cube->map.texture_paths);
	init_textures(cube, &cube->mlx.player, "./images/player.png");
	cube->mlx.portal = ft_calloc(13, sizeof(t_image));
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
	cube->map.portal_texture = ft_calloc(13, sizeof(int **));
	cube->map.portal_texture[NORTH] = init_portal_wall_sprite(cube, cube->map.portal_texture[NORTH], &cube->map.no_texture);
	cube->map.portal_texture[SOUTH] = init_portal_wall_sprite(cube, cube->map.portal_texture[SOUTH], &cube->map.so_texture);
	cube->map.portal_texture[EAST] = init_portal_wall_sprite(cube, cube->map.portal_texture[EAST], &cube->map.ea_texture);
	cube->map.portal_texture[WEST] = init_portal_wall_sprite(cube, cube->map.portal_texture[WEST], &cube->map.we_texture);
	
}
