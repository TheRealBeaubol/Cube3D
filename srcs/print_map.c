/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:33:56 by mhervoch          #+#    #+#             */
/*   Updated: 2024/05/23 15:55:59 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*void	print_player(t_cube *cube, char pixel, int x, int y)
{
	
}*/

void	print_global_pixel(t_cube *cube, int x, int y, int color)
{
	int	dx;
	int	dy;

	dx = 0;
	while (dx < 50)
	{
		dy = 0;
		while (dy < 50)
		{
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, x + dx, y + dy, color);
			dy++;
		}
		dx++;
	}
}

void	print_player(t_cube *cube, int x, int y, int color)
{
	int	dx;
	int	dy;
	int	px;
	int	py;
	
	cube->player_settings->pos_x = x + ((50 - 10) / 2);
	cube->player_settings->pos_y = y + ((50 - 10) / 2);
	px = cube->player_settings->pos_x + 10;
	py = cube->player_settings->pos_y + 10;
	ft_printf("x: %d, y: %d\n", x, y);
	ft_printf("px: %d, py: %d\n", px, py);
	dx = 0;
	while (dx < 50)
	{
		dy = 0;
		while (dy < 50)
		{
			if (dx > px - x && dx < px + 10 - x && dy > py - y && dy < py - y + 10)
				mlx_set_image_pixel(cube->mlx_ptr, cube->img, x + dx, y + dy, color);
			else
				mlx_set_image_pixel(cube->mlx_ptr, cube->img, x + dx, y + dy, 0xFFFFFFFF);
			dy++;
		}
		dx++;
	}
}

/*void	print_view(t_cube *cube, int x, int y)
{
	int	posx;
	int	posy;

	posx = x + 500;
	posy = y + 500;

}*/

void	print_pixel(t_cube *cube, char pixel, int x, int y)
{
	if (pixel == '1')
		print_global_pixel(cube, x, y, 0xFF0000FF);
	if (pixel == '0')
		print_global_pixel(cube, x, y, 0xFFFFFFFF);	
	if (pixel == 'P')
	{
		print_player(cube, x, y, 0xFFFF0000);
		//print_view(cube, dx + x, dy + y);
	}
}

void	print_map(char **map, t_cube *cube)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = HEIGHT / 2 - 7 * 50 / 2;
	i = 0;
	while (map[i])
	{
		x = WIDTH / 2 - 7 * 50 / 2;
		j = 0;
		while (map[i][j])
		{
			print_pixel(cube, map[i][j], x, y);
			x += 50;
			j++;
		}
		y += 50;
		i++;
	}
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->img, 0, 0);
}
