/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:02:00 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/18 19:17:08 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_settings_file(t_cube *cube)
{
	int	fd;

	(void)cube;
	fd = open("/tmp/settings.txt", O_RDWR, 0644);
	if (fd == -1)
	{
		fd = open("/tmp/settings.txt", O_CREAT | O_RDWR, 0644);
		ft_putstr_fd("move_forward = W\nmove_backward = \
S\nmove_left = A\nmove_right = D\n", fd);
	}
	close(fd);
}

t_player_settings	*init_player_settings(void)
{
	t_player_settings	*settings;

	settings = ft_calloc(1, sizeof(t_player_settings));
	init_player_binds(settings);
	settings->dir_x = 0;
	settings->dir_y = -1;
	settings->plane.x = 0.66;
	settings->plane.y = 0;
	settings->fov = 8;
	settings->looking_angle = PI / 2;
	settings->ray = NULL;
	ft_bzero(settings->key_tab, 256);
	return (settings);
}

void	init_mlx(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	if (cube->mlx_ptr == NULL)
		exit (1);
	cube->img = mlx_new_image(cube->mlx_ptr, WIDTH, HEIGHT);
	cube->minimap_img = mlx_new_image(cube->mlx_ptr, WIDTH, HEIGHT);
	cube->background = mlx_new_image(cube->mlx_ptr, WIDTH, HEIGHT);
	cube->window_ptr = mlx_new_window(cube->mlx_ptr, WIDTH, HEIGHT, "Cube3D");
	if (cube->window_ptr == NULL)
		free_and_destroy(cube);
}

void	start_cube(t_cube *cube)
{
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->start_background, 0, 0);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->play_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - \
cube->menu->button_height) / 2) - 200);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->settings_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - \
cube->menu->button_height) / 2));
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, \
cube->menu->exit_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - \
cube->menu->button_height) / 2) + 200);
}

void	init_player(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map->map[i])
	{
		j = 0;
		while (cube->map->map[i][j])
		{
			if (!is_player(cube->map->map[i][j]))
			{
				cube->player_settings->pos.x = i + 0.5;
				cube->player_settings->pos.y = j + 0.5;
				cube->map->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	map_wall_image(void *mlx, t_image img, int *texture)
{
	int	x;
	int	y;

	y = 0;
	while (y < img.width)
	{
		x = 0;
		while (x < img.height)
		{
			texture[y * img.width + x] = \
mlx_get_image_pixel(mlx, img.texture, x, y);
			x++;
		}
		y++;
	}
}

#include <stdio.h>
void	init_textures(t_cube *cube, t_image img, int **texture)
{
	*texture = malloc(img.height * img.width * sizeof(int));
	map_wall_image(cube->mlx_ptr, img, *texture);
	printf("texture = %d\n", texture[0][0]);
}
void	preload_texture(t_cube *cube)
{
	init_textures(cube, cube->map->no_texture, &cube->map->north_texture);
	init_textures(cube, cube->map->so_texture, &cube->map->south_texture);
	init_textures(cube, cube->map->we_texture, &cube->map->west_texture);
	init_textures(cube, cube->map->ea_texture, &cube->map->east_texture);
}
void	init(t_cube *cube)
{
	init_mlx(cube);
	cube->menu = init_menu(cube);
	cube->map = init_map(cube, cube->map_name);
	cube->is_in_game = 0;
	init_settings_file(cube);
	cube->player_settings = init_player_settings();
	if (!cube->menu || !cube->map || !cube->player_settings)
	{
		ft_dprintf(2, "Error\nFile cannot be open or the file is missing\n");
		free_and_destroy(cube);
	}
	init_player(cube);
	preload_texture(cube);
	draw_background(cube);
	start_cube(cube);
}
