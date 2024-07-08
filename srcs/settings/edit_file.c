/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 22:18:31 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/08 23:47:12 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	reset_settings_file(void)
{
	int	fd;

	fd = open("/tmp/settings.txt", O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	ft_putstr_fd("move_forward = W\nmove_backward = S\nmove_left \
= A\nmove_right = D\nsprint = CTRL\nshow_map = M\nshow_fps = F\n", fd);
	close(fd);
}

void	check_settings(t_player_settings *settings)
{
	if (settings->move_forward == -1 || settings->move_backward == -1 || \
		settings->move_left == -1 || settings->move_right == -1 || \
		settings->sprint == -1 || settings->show_map == -1 || \
		settings->show_fps == -1)
	{
		reset_settings_file();
		init_player_binds(settings);
	}
}

int	add_bind_to_settings_file(char *print, char *param, int fd)
{
	if (!param)
	{
		reset_settings_file();
		close(fd);
		return (0);
	}
	ft_dprintf(fd, "%s%s\n", print, param);
	free(param);
	return (1);
}

void	edit_settings_file(t_cube *cube)
{
	int		fd;

	fd = open("/tmp/settings.txt", O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	if (!add_bind_to_settings_file("move_forward = ", \
get_line_from_key(cube->settings.move_forward, cube->settings.key_map), fd))
		return ;
	if (!add_bind_to_settings_file("move_backward = ", \
get_line_from_key(cube->settings.move_backward, cube->settings.key_map), fd))
		return ;
	if (!add_bind_to_settings_file("move_left = ", \
get_line_from_key(cube->settings.move_left, cube->settings.key_map), fd))
		return ;
	if (!add_bind_to_settings_file("move_right = ", \
get_line_from_key(cube->settings.move_right, cube->settings.key_map), fd))
		return ;
	if (!add_bind_to_settings_file("sprint = ", \
get_line_from_key(cube->settings.sprint, cube->settings.key_map), fd))
		return ;
	if (!add_bind_to_settings_file("show_map = ", \
get_line_from_key(cube->settings.show_map, cube->settings.key_map), fd))
		return ;
	if (!add_bind_to_settings_file("show_fps = ", \
get_line_from_key(cube->settings.show_fps, cube->settings.key_map), fd))
		return ;
	close(fd);
}
