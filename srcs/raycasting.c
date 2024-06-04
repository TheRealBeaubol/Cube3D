/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:11:15 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/04 09:42:36 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// t_ray   **feed_ray_tab(t_player_settings *player)
// {
//     t_ray   **ray;
//     int i;

//     ray = ft_calloc(player->fov, sizeof(t_ray));
//     if (!ray)
//         return (NULL);
//     i = 0;
//     ray[i]->angle = player->looking_angle;
//     ray[i]->x = get_ray_x();
//     ray[i]->y = get_ray_y();
//     while (++i < player->fov)
//     {
//         if (ray[i - 1]->angle < 90)
//             ray[i]->angle = ray[i - 1]->angle - 1;
//         else
//         {
//             if (player->looking_angle + player->fov / 2 == ray[i - 1]->angle)
//                 ray[i]->angle = player->looking_angle - 1;
//             else
//                 ray[i]->angle = ray[i - 1]->angle + 1;       
//         }
//         ray[i]->x = get_ray_x();
//         ray[i]->y = get_ray_y();
//     }
//     return (ray);
// }


void	print_pixel_low(t_cube *cube, int is_inverted)
{
	if (is_inverted == 1)
		mlx_set_image_pixel(cube->mlx_ptr, cube->img, cube->plotline->x, \
			cube->plotline->y, 0xFFFFFFFF);
	else
		mlx_set_image_pixel(cube->mlx_ptr, cube->img, cube->plotline->x, \
			cube->plotline->y, 0xFFFFFFFF);
}

void	print_pixel_high(t_cube *cube, int is_inverted)
{
	if (is_inverted == 1)
		mlx_set_image_pixel(cube->mlx_ptr, cube->img, cube->plotline->x, \
			cube->plotline->y, 0xFFFFFFFF);
	else
		mlx_set_image_pixel(cube->mlx_ptr, cube->img, cube->plotline->x, \
			cube->plotline->y, 0xFFFFFFFF);
}

void	plotline_low(t_cube *cube, t_point point1, t_point point2, int is_inverted)
{
	t_plotline	plotline;

	plotline.yi = 1;
	plotline.dx = point2.x - point1.x;
	plotline.dy = point2.y - point1.y;
	if (plotline.dy < 0)
	{
		plotline.yi = -1;
		plotline.dy *= -1;
	}
	plotline.d = (2 * plotline.dy) - plotline.dx;
	plotline.y = point1.y;
	plotline.x = point1.x;
	while (plotline.x <= point2.x)
	{
		cube->plotline = &plotline;
		print_pixel_low(cube, is_inverted);
		if (plotline.d > 0)
		{
			plotline.y += plotline.yi;
			plotline.d += -2 * plotline.dx;
		}
		plotline.d += 2 * plotline.dy;
		plotline.x++;
	}
}

void	plotline_high(t_cube *cube, t_point point1, t_point point2, int is_inverted)
{
	t_plotline	plotline;

	plotline.dx = point2.x - point1.x;
	plotline.dy = point2.y - point1.y;
	plotline.xi = 1;
	if (plotline.dx < 0)
	{
		plotline.xi = -1;
		plotline.dx *= -1;
	}
	plotline.d = (2 * plotline.dx) - plotline.dy;
	plotline.x = point1.x;
	plotline.y = point1.y;
	while (plotline.y <= point2.y)
	{
		cube->plotline = &plotline;
		print_pixel_high(cube, is_inverted);
		if (plotline.d > 0)
		{
			plotline.x += plotline.xi;
			plotline.d += -2 * plotline.dy;
		}
		plotline.d += 2 * plotline.dx;
		plotline.y++;
	}
}

void	plotline(t_cube *cube, t_point point2, t_point point1)
{
    int is_inverted;

    is_inverted = 0;
	if (abs((int)point2.y - (int)point1.y) < abs((int)point2.x - (int)point1.x))
	{
		if ((point2.x - point1.x) > 0)
			plotline_low(cube, point1, point2, is_inverted);
		else
		{
			is_inverted = 1;
			plotline_low(cube, point2, point1, is_inverted);
		}
	}
	else
	{
		if ((point2.y - point1.y) > 0)
			plotline_high(cube, point1, point2, is_inverted);
		else
		{
	        is_inverted = 1;
			plotline_high(cube, point2, point1, is_inverted);
		}
	}
}