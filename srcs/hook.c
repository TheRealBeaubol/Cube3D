/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:08:52 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/05 19:11:48 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_hook(int keycode, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (keycode == ESCAPE)
		free_and_destroy(cube);
	return (0);
}
