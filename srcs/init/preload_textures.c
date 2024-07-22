/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:17:59 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/22 17:29:00 by lboiteux         ###   ########.fr       */
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
	wall = ft_calloc(5, sizeof(int *));
	while (++i < 4)
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
	init_textures(cube, &cube->mlx.player, "./images/player3.png");
	cube->map.portal = ft_calloc(4, sizeof(int *));
	init_textures(cube, &cube->mlx.portal[0], "./images/portal1.png");
	init_textures(cube, &cube->mlx.portal[1], "./images/portal2.png");
	init_textures(cube, &cube->mlx.portal[2], "./images/portal3.png");
	init_textures(cube, &cube->mlx.portal[3], "./images/portal4.png");
	cube->map.portal_texture = ft_calloc(4, sizeof(int **));
	cube->map.portal_texture[NORTH] = init_portal_wall_sprite(cube, cube->map.portal_texture[NORTH], &cube->map.no_texture);
	cube->map.portal_texture[SOUTH] = init_portal_wall_sprite(cube, cube->map.portal_texture[SOUTH], &cube->map.so_texture);
	cube->map.portal_texture[EAST] = init_portal_wall_sprite(cube, cube->map.portal_texture[EAST], &cube->map.ea_texture);
	cube->map.portal_texture[WEST] = init_portal_wall_sprite(cube, cube->map.portal_texture[WEST], &cube->map.we_texture);
	
}
