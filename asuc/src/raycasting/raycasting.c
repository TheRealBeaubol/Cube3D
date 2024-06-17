/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:01:19 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/17 19:38:00 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_raycasting.h"

static inline void	calculate_line_height_and_draw_points(t_ray *ray,
		int *line_height, int *draw_start, int *draw_end)
{
	*line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	*draw_start = -*line_height / 2 + WIN_HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = *line_height / 2 + WIN_HEIGHT / 2;
	if (*draw_end >= WIN_HEIGHT)
		*draw_end = WIN_HEIGHT - 1;
}

static inline void	draw_texture(t_data *data, int x, t_ray_params *params)
{
	int	i;
	int	tex_y;
	int	color;

	i = params->draw_start;
	// printf("params->tex_pos = %f\n", params->tex_pos);
	params->tex_pos = (params->draw_start - WIN_HEIGHT / 2 + params->line_height
			/ 2) * params->step;
	// printf("params->tex_pos = %f\n", params->tex_pos);
	while (i < params->draw_end)
	{
		tex_y = ((int)params->tex_pos & (params->texture_height
					- 1));
		params->tex_pos += params->step;
		color = params->texture[tex_y * params->texture_width
			+ params->tex_x];
		mlx_pixel_put(data->mlx.mlx, data->mlx.win, x, i, color);
		i++;
	}
}

static inline void	cast_ray(t_data *data, int x)
{
	t_ray_params	params;

	init_ray(&params.ray, &data->player, 2 * x / (float)WIN_WIDTH - 1);
	calculate_step_and_side_dist(&params.ray);
	perform_dda(&params.ray, &data->map);
	if (params.ray.hit == 2)
		return ;
	params.texture = select_texture(&params, &data->mlx.wall_sprite);
	calculate_line_height_and_draw_points(&params.ray, &params.line_height,
		&params.draw_start, &params.draw_end);
	calculate_wall_x_and_tex_x(&params.ray, &params);
	params.step = 1.0 * params.texture_height
		/ params.line_height;
	if (params.ray.side != 0 && params.ray.dir.y <= 0 && x % 10 == 0)
	{
		printf("[%d] %d ---> %d |\n", x, params.draw_start, params.draw_end);
		// printf("ray.pos.x = %f	|	", params.ray.pos.x);
		// printf("ray.pos.y = %f\n", params.ray.pos.y);
		// printf("ray.dir.x = %f	|	", params.ray.dir.x);
		// printf("ray.dir.y = %f\n", params.ray.dir.y);
		// printf("ray.map_x = %d	|	", params.ray.map_x);
		// printf("ray.map_y = %d\n", params.ray.map_y);
		// printf("plane.x = %f	|	", data->player.plane.x);
		// printf("plane.y = %f\n", data->player.plane.y);
		// printf("step_x = %d	|	", params.ray.step_x);
		// printf("step_y = %d\n", params.ray.step_y);
		// printf("side_dist_x = %f	|	", params.ray.side_dist_x);
		// printf("side_dist_y = %f\n", params.ray.side_dist_y);
		// printf("delta_dist_x = %f	|	", params.ray.delta_dist_x);
		// printf("delta_dist_y = %f\n", params.ray.delta_dist_y);
		// printf("perp_wall_dist = %f\n", params.ray.perp_wall_dist);
		// printf("line_height = %d\n", params.line_height);
		// printf("side = %d\n", params.ray.side);
		// printf("tex_x = %d\n", params.tex_x);
		// printf("tex_pos = %f\n", params.tex_pos);
	}
	draw_texture(data, x, &params);
}

void	render_frame(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.width)
	{
		cast_ray(data, i);
		i++;
	}
}
