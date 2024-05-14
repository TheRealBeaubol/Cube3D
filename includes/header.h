/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:43 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/14 15:32:40 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "define.h"
# include "structs.h"

void	free_and_destroy(t_cube *cube);
int		free_and_destroy_exit(int i, void *cube_void);
int		key_hook(int keycode, void *cube_void);
void	init(t_cube *cube);
int     mouse_move(void *cube_void);
int	    mouse_press(int key, void *cube_void);
int	    mouse_release(int keycode, void *cube_void);
void	open_settings(t_cube *cube);
void	open_video_settings_menu(t_cube *cube);
void	open_keybinds_menu(t_cube *cube);
void	open_music_and_sounds_menu(t_cube *cube);

#endif