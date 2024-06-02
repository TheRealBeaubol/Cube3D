/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 22:18:31 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/02 22:52:10 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_player_binds(t_player_settings *settings)
{
	int					fd;
	char				*line;

	fd = open("/tmp/settings.txt", O_RDWR, 0644);
	if (fd == -1)
		return ;
	line = get_next_line(fd, 0);
	settings->move_forward = get_key_from_line(line);
	free(line);
	line = get_next_line(fd, 0);
	settings->move_backward = get_key_from_line(line);
	free(line);
	line = get_next_line(fd, 0);
	settings->move_left = get_key_from_line(line);
	free(line);
	line = get_next_line(fd, 0);
	settings->move_right = get_key_from_line(line);
	check_settings(settings);
	free(line);
}

void	reset_settings_file(void)
{
	int	fd;

	fd = open("/tmp/settings.txt", O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	ft_putstr_fd("move_forward = W\nmove_backward = S\nmove_left \
= A\nmove_right = D\n", fd);
	close(fd);
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
get_line_from_key(cube->player_settings->move_forward), fd))
		return ;
	if (!add_bind_to_settings_file("move_backward = ", \
get_line_from_key(cube->player_settings->move_backward), fd))
		return ;
	if (!add_bind_to_settings_file("move_left = ", \
get_line_from_key(cube->player_settings->move_left), fd))
		return ;
	if (!add_bind_to_settings_file("move_right = ", \
get_line_from_key(cube->player_settings->move_right), fd))
		return ;
	close(fd);
}
