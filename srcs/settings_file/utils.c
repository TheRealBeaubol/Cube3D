/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 22:47:30 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/02 22:48:04 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_key_from_line(char *line)
{
	int	key;

	line[ft_strlen(line) - 1] = 0;
	while (*line != '=')
		line++;
	line += 2;
	key = get_key_from_line_part_one(line);
	if (key != -1)
		return (key);
	key = get_key_from_line_part_two(line);
	if (key != -1)
		return (key);
	key = get_key_from_line_part_three(line);
	if (key != -1)
		return (key);
	key = get_key_from_line_part_four(line);
	if (key != -1)
		return (key);
	key = get_key_from_line_part_five(line);
	if (key != -1)
		return (key);
	return (-1);
}

char	*get_line_from_key(int key)
{
	char	*line;

	line = get_line_from_key_part_one(key);
	if (line)
		return (line);
	line = get_line_from_key_part_two(key);
	if (line)
		return (line);
	line = get_line_from_key_part_three(key);
	if (line)
		return (line);
	line = get_line_from_key_part_four(key);
	if (line)
		return (line);
	line = get_line_from_key_part_five(key);
	if (line)
		return (line);
	return (NULL);
}

void	check_settings(t_player_settings *settings)
{
	if (settings->move_forward == -1 || settings->move_backward == -1 || \
		settings->move_left == -1 || settings->move_right == -1)
	{
		reset_settings_file();
		init_player_binds(settings);
	}
}
