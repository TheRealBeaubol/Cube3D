/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:40:22 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/25 01:11:50 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_player_binds(t_player_settings *settings)
{
	int		fd;
	char	*line;

	fd = open("/tmp/settings.txt", O_RDWR, 0644);
	if (fd == -1)
		return ;
	line = get_next_line(fd, 0);
	settings->move_forward = get_key_from_line(line, settings->key_map);
	free(line);
	line = get_next_line(fd, 0);
	settings->move_backward = get_key_from_line(line, settings->key_map);
	free(line);
	line = get_next_line(fd, 0);
	settings->move_left = get_key_from_line(line, settings->key_map);
	free(line);
	line = get_next_line(fd, 0);
	settings->move_right = get_key_from_line(line, settings->key_map);
	check_settings(settings);
	free(line);
	close(fd);
}

void	init_settings_file(void)
{
	int	fd;

	fd = open("/tmp/settings.txt", O_RDWR, 0644);
	if (fd == -1)
	{
		fd = open("/tmp/settings.txt", O_CREAT | O_RDWR, 0644);
		ft_putstr_fd("move_forward = W\nmove_backward = \
S\nmove_left = A\nmove_right = D\n", fd);
	}
	close(fd);
}

void	init_key_map(t_cube *cube)
{
	const t_key_map	key_map[54] = {{"A", SDL_SCANCODE_A}, {"B"\
, SDL_SCANCODE_B}, {"C", SDL_SCANCODE_C}, {"D", SDL_SCANCODE_D}, {\
"E", SDL_SCANCODE_E}, {"F", SDL_SCANCODE_F}, {"G", SDL_SCANCODE_G}, {\
"H", SDL_SCANCODE_H}, {"I", SDL_SCANCODE_I}, {"J", SDL_SCANCODE_J}, {\
"K", SDL_SCANCODE_K}, {"L", SDL_SCANCODE_L}, {"M", SDL_SCANCODE_M}, {\
"N", SDL_SCANCODE_N}, {"O", SDL_SCANCODE_O}, {"P", SDL_SCANCODE_P}, {\
"Q", SDL_SCANCODE_Q}, {"R", SDL_SCANCODE_R}, {"S", SDL_SCANCODE_S}, {\
"T", SDL_SCANCODE_T}, {"U", SDL_SCANCODE_U}, {"V", SDL_SCANCODE_V}, {\
"W", SDL_SCANCODE_W}, {"X", SDL_SCANCODE_X}, {"Y", SDL_SCANCODE_Y}, {\
"Z", SDL_SCANCODE_Z}, {"0", SDL_SCANCODE_0}, {"1", SDL_SCANCODE_1}, {\
"2", SDL_SCANCODE_2}, {"3", SDL_SCANCODE_3}, {"4", SDL_SCANCODE_4}, {\
"5", SDL_SCANCODE_5}, {"6", SDL_SCANCODE_6}, {"7", SDL_SCANCODE_7}, {\
"8", SDL_SCANCODE_8}, {"9", SDL_SCANCODE_9}, {"KP_0", \
SDL_SCANCODE_KP_0}, {"KP_1", SDL_SCANCODE_KP_1}, {"KP_2", SDL_SCANCODE_KP_2} \
, {"KP_3", SDL_SCANCODE_KP_3}, {"KP_4", SDL_SCANCODE_KP_4}, {"KP_5", \
SDL_SCANCODE_KP_5}, {"KP_6", SDL_SCANCODE_KP_6}, {"KP_7", SDL_SCANCODE_KP_7}, {\
"KP_8", SDL_SCANCODE_KP_8}, {"KP_9", SDL_SCANCODE_KP_9}, {"SHIFT", \
SDL_SCANCODE_LSHIFT}, {"CTRL", SDL_SCANCODE_LCTRL}, {"SPACE", \
SDL_SCANCODE_SPACE}, {"TAB", SDL_SCANCODE_TAB}, {"KP_MULT", \
SDL_SCANCODE_KP_MULTIPLY}, {"KP_PLUS", SDL_SCANCODE_KP_PLUS}, {\
"KP_MINUS", SDL_SCANCODE_KP_MINUS}, {"KP_DIV", SDL_SCANCODE_KP_DIVIDE}};

	ft_memcpy(cube->settings.key_map, key_map, sizeof(key_map));
}
