/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:17:59 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/22 15:11:51 by lboiteux         ###   ########.fr       */
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

void	init_portal_sprite(t_cube *cube)
{
	const char	*paths[4] = {"./images/portal1.png", "./images/portal2.png", \
"./images/portal3.png", "./images/portal4.png"};
	char		*path;
	int			i;

	i = -1;
	while (++i < 4)
	{
		path = (char *)paths[i];
		init_textures(cube, &cube->mlx.portal[i], path);
	}
}

void	init_portal_wall_sprite(t_cube *cube, int **wall, t_image *img)
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
				if ((x < cube->mlx.portal[i].height && y < cube->mlx.portal[i].width) && (cube->mlx.portal[i].texture[y * cube->mlx.portal[i].width + x] != 0))
					wall[i][y * cube->mlx.portal[i].width + x] = \
cube->mlx.portal[i].texture[y * cube->mlx.portal[i].width + x];
				else
					wall[i][y * cube->mlx.portal[i].width + x] = \
img->texture[y * cube->mlx.portal[i].width + x];
			}
		}
	}
}

void	print_texture(t_image *img, int *img2)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->width)
	{
		x = 0;
		while (x < img->height)
		{
			printf("[%d | %d] ", img->texture[y * img->width + x], img2[y * img->width + x]);
			x++;
		}
		y++;
	}
}

void	preload_textures(t_cube *cube)
{
	init_textures(cube, &cube->map.no_texture, cube->map.texture_paths[0]);
	init_textures(cube, &cube->map.so_texture, cube->map.texture_paths[1]);
	init_textures(cube, &cube->map.we_texture, cube->map.texture_paths[2]);
	init_textures(cube, &cube->map.ea_texture, cube->map.texture_paths[3]);
	ft_free_tab(cube->map.texture_paths);
	init_textures(cube, &cube->mlx.player, "./images/player3.png");
	init_portal_sprite(cube);
	init_portal_wall_sprite(cube, cube->map.no_portal, &cube->map.no_texture);
	init_portal_wall_sprite(cube, cube->map.so_portal, &cube->map.so_texture);
	init_portal_wall_sprite(cube, cube->map.ea_portal, &cube->map.ea_texture);
	init_portal_wall_sprite(cube, cube->map.we_portal, &cube->map.we_texture);
	print_texture(&cube->map.so_texture, *cube->map.so_portal);
}
