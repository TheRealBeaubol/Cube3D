/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:57:12 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/06 21:36:53 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_hover_button(t_cube *cube)
{
	if (cube->menu->play_button_status)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->play_button_hover, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) - 200);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->play_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) - 200);
	if (cube->menu->options_button_status)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->options_button_hover, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2));
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->options_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2));
	if (cube->menu->exit_button_status)
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->exit_button_hover, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) + 200);
	else
		mlx_put_image_to_window(cube->mlx_ptr, cube->window_ptr, cube->menu->exit_button, (WIDTH - cube->menu->button_width) / 2, ((HEIGHT - cube->menu->button_height) / 2) + 200);
}

void	handle_mouse_in_start_menu(t_cube *cube, int x, int y)
{
	if (!cube->menu->is_in_menu)
	{
		if (x > 780 && x < 1135 && y > 280 && y < 400)
			cube->menu->play_button_status = 1;
		else
			cube->menu->play_button_status = 0;
		if (x > 780 && x < 1135 && y > 480 && y < 600)
			cube->menu->options_button_status = 1;
		else
			cube->menu->options_button_status = 0;
		if (x > 780 && x < 1135 && y > 680 && y < 800)
			cube->menu->exit_button_status = 1;
		else
			cube->menu->exit_button_status = 0;
		render_hover_button(cube);
	}
}

int	mouse_move(void *cube_void)
{
	t_cube	*cube;
	int		x;
	int		y;

	cube = (t_cube *)cube_void;
	mlx_mouse_get_pos(cube->mlx_ptr, &x, &y);
	handle_mouse_in_start_menu(cube, x, y);
	return (0);
}
