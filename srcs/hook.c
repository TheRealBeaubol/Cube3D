/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:08:52 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/18 00:07:34 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_hook(int keycode, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (cube->menu->settings_menu->waiting_for_key)
	{
		if ((keycode >= 4 && keycode <= 39) || keycode == 43 || keycode == \
44 || (keycode >= 84 && keycode <= 87) || (keycode >= 89 && keycode <= 98) || \
keycode == 224 || keycode == 225)
		{
			cube->menu->settings_menu->key = keycode;
			cube->menu->settings_menu->waiting_for_print = 1;
			cube->menu->settings_menu->waiting_for_key = 0;
		}
		else
			cube->menu->settings_menu->waiting_for_key = 0;
	}
	if (keycode == ESCAPE)
		free_and_destroy(cube);
	return (0);
}
