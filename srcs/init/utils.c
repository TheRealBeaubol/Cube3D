/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:20:58 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/24 21:57:43 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_background(void *mlx_ptr, void *background, unsigned long c_color, \
	unsigned long f_color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_set_image_pixel(mlx_ptr, background, x, y, \
0xFF000000 + c_color);
	}
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_set_image_pixel(mlx_ptr, background, x, y, \
0xFF000000 + f_color);
	}
}

int	is_player(char c)
{
	return (c != 'N' && c != 'S' && c != 'E' && c != 'W');
}
