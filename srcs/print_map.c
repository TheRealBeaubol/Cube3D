/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:33:56 by mhervoch          #+#    #+#             */
/*   Updated: 2024/06/17 19:24:41 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_global_pixel(t_cube *cube, int x, int y, int color)
{
	int	dx;
	int	dy;

	dx = 0;
	while (dx < cube->map->size_case)
	{
		dy = 0;
		while (dy < cube->map->size_case)
		{
			mlx_set_image_pixel(cube->mlx_ptr, cube->minimap_img, x + dx, y + dy, color);
			dy++;
		}
		dx++;
	}
}

int	is_in_wall(t_cube *cube)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	while (x < cube->map->player_size)
	{
		y = 0;
		while (y < cube->map->player_size)
		{
			i = (cube->player_settings->pos.y + y) / cube->map->size_case;
			j = (cube->player_settings->pos.x + x - (WIDTH - cube->map->size_case * cube->map->width)) / cube->map->size_case;
			if (cube->map->map[i][j] == '1')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void	print_player(t_cube *cube, int color)
{
	int	dx;
	int	dy;
	int	px;
	int	py;

	px = WIDTH - (2.5 * cube->map->size_case);
	py = (2.5 * cube->map->size_case);
	dx = -1;
	while (++dx < cube->map->player_size)
	{
		dy = -1;
		while (++dy < cube->map->player_size)
			mlx_set_image_pixel(cube->mlx_ptr, cube->minimap_img, px + dx, py + dy, color);
	}
}

void	draw_background(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_set_image_pixel(cube->mlx_ptr, cube->background, x, y, 0xFF000000 + cube->map->ceiling_color);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_set_image_pixel(cube->mlx_ptr, cube->background, x, y, 0xFF000000 + cube->map->floor_color);
			x++;
		}
		y++;
	}
}

int	is_player(char c)
{
	return (c != 'N' && c != 'S' && c != 'E' && c != 'W');
}

void	print_map(t_cube *cube)
{
	int			i;
	int			j;
	int			save_i;
	int			save_j;
	int			x;
	int			y;

	i = (int)cube->player_settings->pos.y;
	j = (int)cube->player_settings->pos.x;
	i -= 2;
	j -= 2;
	save_i = i + 5;
	save_j = j + 5;
	y = 0;
	while (i < save_i)
	{
		x = WIDTH - (5 * cube->map->size_case);
		j = save_j - 5;
		while (j < save_j)
		{
			if (i < 0 || j < 0 || i >= cube->map->height || j >= cube->map->width)
				print_global_pixel(cube, x, y, 0x00000000);
			else if (cube->map->map[i][j] == '1')
				print_global_pixel(cube, x, y, 0xFF0000FF);
			else if (cube->map->map[i][j] == '0')
				print_global_pixel(cube, x, y, 0xFFFFFFFF);
			else if (cube->map->map[i][j] == 'D')
				print_global_pixel(cube, x, y, 0xFF00FF00);
			else if (cube->map->map[i][j] == 'P')
				print_global_pixel(cube, x, y, 0xFF000000);
			else
				print_global_pixel(cube, x, y, 0x00000000);
			x += cube->map->size_case;
			j++;
		}
		y += cube->map->size_case;
		i++;
	}
}

void	clear_window(void *mlx_ptr, void *window_ptr)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_set_image_pixel(mlx_ptr, window_ptr, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	render_cube(t_cube *cube)
{
	int	i;
	
	i = -1;
	clear_window(cube->mlx_ptr, cube->img);
	print_map(cube);
	print_player(cube, 0xFFFF0000);
	cube->player_settings->ray = ft_calloc(WIDTH + 1, sizeof(t_ray *));
	while (++i < WIDTH)
		cube->player_settings->ray[i] = ft_calloc(1, sizeof(t_ray));
	i = -1;
	while (++i < WIDTH)
		do_rays(cube, cube->player_settings->ray[i], i);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->background, 0, 0);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->img, 0, 0);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->minimap_img, 0, 0);
}
