/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:49:25 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/25 22:50:01 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*get_key_images(t_cube *cube, int key)
{
	int	i;

	i = 0;
	while (i <= 54)
	{
		if (cube->settings.key_map[i].key_value == key)
			return (cube->menu.keys[i].img);
		i++;
	}
	return (NULL);
}

void	put_keys_images(t_cube *cube, void *mlx_ptr, void *mlx_win)
{
	void	*keys_image;

	keys_image = get_key_images(cube, cube->settings.move_forward);
	mlx_put_image_to_window(mlx_ptr, mlx_win, \
keys_image, 671, 392);
	keys_image = get_key_images(cube, cube->settings.move_backward);
	mlx_put_image_to_window(mlx_ptr, mlx_win, \
keys_image, 671, 461);
	keys_image = get_key_images(cube, cube->settings.move_left);
	mlx_put_image_to_window(mlx_ptr, mlx_win, \
keys_image, 671, 530);
	keys_image = get_key_images(cube, cube->settings.move_right);
	mlx_put_image_to_window(mlx_ptr, mlx_win, \
keys_image, 671, 599);
}
