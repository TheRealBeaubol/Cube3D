/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:26:20 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 18:02:06 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	printf_and_exit(char *str, int fd)
{
	close(fd);
	ft_dprintf(2, "%s\n", str);
	exit(EXIT_FAILURE);
}

void	free_init_and_exit(t_cube *cube, char *str, int i)
{
	ft_free_tab(cube->map.map);
	ft_free_tab(cube->map.texture_paths);
	if (i)
		mlx_destroy_display(cube->mlx.ptr);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
