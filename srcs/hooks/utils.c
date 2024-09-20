/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:06:15 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 18:07:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fps_counter(void)
{
	static t_fps_counter	fps_counter = {0, 0, 0, 0};
	clock_t					current_time;
	float					fps;
	float					avg_fps;

	current_time = clock();
	fps = CLOCKS_PER_SEC / (float)(current_time - fps_counter.last_time);
	fps_counter.last_time = current_time;
	fps_counter.fps_sum += fps;
	fps_counter.frame_count++;
	if ((current_time - fps_counter.last_avg_time) >= CLOCKS_PER_SEC * 10)
	{
		avg_fps = fps_counter.fps_sum / fps_counter.frame_count;
		printf("\033[1;31mAverage FPS (10s): %.2f\033[0m\n", avg_fps);
		fps_counter.fps_sum = 0.0;
		fps_counter.frame_count = 0;
		fps_counter.last_avg_time = current_time;
	}
}

void	rotate(t_cube *cube, float angle)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = cube->settings.dir.x;
	cube->settings.dir.x = cube->settings.dir.x * cos(angle) - \
		cube->settings.dir.y * sin(angle);
	cube->settings.dir.y = old_dir_x * sin(angle) + \
		cube->settings.dir.y * cos(angle);
	old_plane_x = cube->settings.plane.x;
	cube->settings.plane.x = cube->settings.plane.x * cos(angle) - \
		cube->settings.plane.y * sin(angle);
	cube->settings.plane.y = old_plane_x * sin(angle) + \
		cube->settings.plane.y * cos(angle);
}

int	key_release(int key, void *cube_void)
{
	t_cube	*cube;

	cube = (t_cube *)cube_void;
	if (key <= 256)
		cube->settings.key_tab[key] = 0;
	return (0);
}
