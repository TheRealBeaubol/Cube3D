/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:33:56 by mhervoch          #+#    #+#             */
/*   Updated: 2024/05/28 15:44:40 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*void	print_wall(t_cube *cube, char pixel, int x, int y)
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

int	is_in_wall(t_cube *cube, char **map)
{
	int	i;
	int	j;

	i = (cube->player_settings->pos_x - WIDTH / 2 + 50 * 7 / 2) % 50;
	j = (cube->player_settings->pos_y - HEIGHT / 2 + 50 * 7 / 2) % 50;
	ft_printf("i: %d, j: %d", i, j);
	if (map[i][j] == '1')
		return (1);
	return(0);
}
void	print_player(t_cube *cube, int color, char **map)
{
	int	dx;
	int	dy;
	int	px;
	int	py;
	
	cube->player_settings->pos_x += cube->player_settings->dir_x;
	cube->player_settings->pos_y += cube->player_settings->dir_y;
	cube->player_settings->dir_x = 0;
	cube->player_settings->dir_y = 0;
	px = cube->player_settings->pos_x;
	py = cube->player_settings->pos_y;
	dx = 0;
	while (dx < 10)
	{
		dy = 0;
		while (dy < 10)
		{
			if (is_in_wall(cube, map))
				mlx_set_image_pixel(cube->mlx_ptr, cube->img, px + dx - 10 , py + dy, color);
			else
				mlx_set_image_pixel(cube->mlx_ptr, cube->img, px + dx, py + dy, color);
			dy++;
		}
		dx++;
	}
}

void	set_player(t_cube *cube, int x, int y)
{
	cube->player_settings->pos_x = x + 20;
	cube->player_settings->pos_y = y + 20;
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
	static int	b = 1;

	if (pixel == '1')
		print_global_pixel(cube, x, y, 0xFF0000FF);
	else if (pixel == '0')
		print_global_pixel(cube, x, y, 0xFFFFFFFF);	
	else if (pixel == 'P' && b)
	{
		b = 0;
		set_player(cube, x, y);
		//print_view(cube, dx + x, dy + y);
	}
	else
		print_global_pixel(cube, x, y, 0xFFFFFFFF);	
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
	print_player(cube, 0xFFFF0000, map);
	mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->img, 0, 0);
}
