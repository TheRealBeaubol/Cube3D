/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:49:25 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/05 20:06:37 by lboiteux         ###   ########.fr       */
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
	const t_int_point	pos[7] = {{671, 461}, {671, 530}, \
	{671, 599}, {1037, 464}, {1037, 533}, \
	{1037, 602}, {844, 673}};
	void				*keys_image;
	int					i;

	i = -1;
	while (++i < 7)
	{
		keys_image = get_key_images(cube, cube->settings.keybinds[i]);
		mlx_put_image_to_window(mlx_ptr, mlx_win, keys_image, \
pos[i].x, pos[i].y);
	}
}
