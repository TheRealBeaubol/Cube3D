/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:26:40 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/15 18:51:12 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check_wall_size(t_sprite *sprite)
{
	if (sprite->wall_n.height != sprite->wall_n.width
		|| sprite->wall_s.height != sprite->wall_s.width
		|| sprite->wall_e.height != sprite->wall_e.width
		|| sprite->wall_w.height != sprite->wall_w.width)
		return (print_error("Wall texture must be square"));
	return (EXIT_SUCCESS);
}

void	init_data(t_data *d)
{
	d->map.width = WIN_WIDTH;
	d->map.height = WIN_HEIGHT;
	d->mlx.mlx = mlx_init();
	mlx_set_fps_goal(d->mlx.mlx, 60);
	mlx_mouse_hide();
	ft_bzero(d->mlx.key_states, 256);
	d->mlx.wall_sprite.wall_e.img = mlx_png_file_to_image(d->mlx.mlx,
			d->mlx.wall_sprite.path_e, &d->mlx.wall_sprite.wall_e.width,
			&d->mlx.wall_sprite.wall_e.height);
	d->mlx.wall_sprite.wall_w.img = mlx_png_file_to_image(d->mlx.mlx,
			d->mlx.wall_sprite.path_w, &d->mlx.wall_sprite.wall_w.width,
			&d->mlx.wall_sprite.wall_w.height);
	d->mlx.wall_sprite.wall_s.img = mlx_png_file_to_image(d->mlx.mlx,
			d->mlx.wall_sprite.path_s, &d->mlx.wall_sprite.wall_s.width,
			&d->mlx.wall_sprite.wall_s.height);
	d->mlx.wall_sprite.wall_n.img = mlx_png_file_to_image(d->mlx.mlx,
			d->mlx.wall_sprite.path_n, &d->mlx.wall_sprite.wall_n.width,
			&d->mlx.wall_sprite.wall_n.height);
	if (check_wall_size(&d->mlx.wall_sprite) == -1)
		exit(EXIT_FAILURE);
	d->mlx.win = mlx_new_window(d->mlx.mlx, d->map.width, d->map.height,
			"Cub3D");
	d->mlx.img_background = mlx_new_image(d->mlx.mlx, d->map.width,
			d->map.height);
}

void	init_mlx(t_data *data)
{
	mlx_on_event(data->mlx.mlx, data->mlx.win, MLX_WINDOW_EVENT, destroy,
		(void *)data);
	mlx_on_event(data->mlx.mlx, data->mlx.win, MLX_KEYDOWN, key_press,
		(void *)data);
	mlx_on_event(data->mlx.mlx, data->mlx.win, MLX_KEYUP, key_release,
		(void *)data);
	mlx_loop_hook(data->mlx.mlx, update, (void *)data);
	mlx_loop(data->mlx.mlx);
}
