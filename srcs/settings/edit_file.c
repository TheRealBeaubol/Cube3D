/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 22:18:31 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/05 20:08:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	reset_settings_file(void)
{
	int	fd;

	fd = open("/tmp/settings.txt", O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	ft_putstr_fd("move_forward = W\nmove_backward = S\nsprint = CTRL\nmove_left \
= A\nmove_right = D\nshow_map = M\nshift = SHIFT\n", fd);
	close(fd);
}

void	check_settings(t_player_settings *settings)
{
	int	i;

	i = -1;
	while (++i < 7)
	{
		if (settings->keybinds[i] == -1)
		{
			reset_settings_file();
			init_player_binds(settings);
		}
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
	const char	*settings_text[7] = {"move_forward = ", "move_backward = ", \
"sprint = ", "move_left = ", "move_right = ", "show_map = ", "shift = "};
	int			fd;
	int			i;

	fd = open("/tmp/settings.txt", O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	i = -1;
	while (++i < 7)
	{
		if (!add_bind_to_settings_file((char *)settings_text[i], \
get_line_from_key(cube->settings.keybinds[i], cube->settings.key_map), fd))
			return ;
	}
	close(fd);
}
