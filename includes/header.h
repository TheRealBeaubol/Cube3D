/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:55:26 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/08 00:07:40 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "define.h"
# include "structs.h"

/* ************************************ */
/*                 EXIT                 */
/* ************************************ */
void	printf_and_exit(char *str, int fd);
void	free_destroy_and_exit(t_cube *cube);
void	free_init_and_exit(t_cube *cube, char *str, int i);

/* ************************************ */
/*                PARSING               */
/* ************************************ */
int		parsing(t_cube *cube);
int		get_width(char **map);
int		get_height(char *file);
void	get_wall_texture_path(char *str, t_map *map);
void	get_colors(t_map *map, char *str);
int		get_number_of_spaces(char *str);
int		check_closed_map(char **map);
void	get_player_pos(t_cube *cube);

/* ************************************ */
/*               SETTINGS               */
/* ************************************ */
void	check_settings(t_player_settings *settings);
void	init_player_binds(t_player_settings *settings);
char	*get_line_from_key(int key, t_key_map *key_map);
int	    get_key_from_line(char *line, t_key_map *key_map);

/* ************************************ */
/*                 INIT                 */
/* ************************************ */
void	init_key_map(t_cube *cube);
void	init_settings_file(void);
void	init_player_binds(t_player_settings *settings);
void    init(t_cube *cube);
void    init_images(void *mlx_ptr, t_menu *menu);
int     is_player(char c);
void	preload_textures(t_cube *cube);
void	draw_background(t_cube *cube);

/* ************************************ */
/*                 HOOK                 */
/* ************************************ */
void	render_buttons(t_cube *cube);
int		key_press(int key, void *cube_void);
void	handle_mouse_in_menu(t_cube *cube, t_int_point pos);
void	handle_mouse_in_keybinds(t_cube *cube, t_int_point pos);
void	handle_mouse_in_settings(t_cube *cube, t_int_point pos);
int		mouse_press(int key, void *cube_void);
void	put_keys_images(t_cube *cube, void *mlx_ptr, void *mlx_win);
void	hook(t_cube *cube);
void	move_forward(t_cube *cube, double movespeed);
void	move_backward(t_cube *cube, double movespeed);
void	move_right(t_cube *cube, double movespeed);
void	move_left(t_cube *cube, double movespeed);

/* ************************************ */
/*               PRE-GAME               */
/* ************************************ */
void	open_music_and_sounds_menu(t_cube *cube);
void	open_video_settings_menu(t_cube *cube);
void	open_keybinds_menu(t_cube *cube);
void	open_settings(t_cube *cube);
void	put_keys_images(t_cube *cube, void *mlx_ptr, void *mlx_win);
void	*get_key_images(t_cube *cube, int key);

/* ************************************ */
/*                 GAME                 */
/* ************************************ */
void    render_cube(t_cube *cube);
void	perform_dda(t_ray *ray, t_map *map, t_player_settings *settings);
void	do_rays(t_cube *cube, t_ray *ray, int i);

void	check_args(int ac, char **av);

void	print_tab(char **tab);

void	check_and_do_portal(t_cube *cube);
void	init_portal(t_cube *cube);
void	draw_first_background(t_cube *cube);
int	    is_map_token(char c);

#endif
