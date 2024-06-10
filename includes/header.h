/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:55:26 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/10 18:09:51 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "define.h"
# include "structs.h"

/* ***************************************** */
/*				  INIT.C				   */
/* ***************************************** */
t_keys_images	*init_keys_images(t_cube *cube);
t_menu			*init_menu(t_cube *cube);

/* ***************************************** */
/*				  EXIT.C				   */
/* ***************************************** */
void			free_and_destroy(t_cube *cube);
int				free_and_destroy_exit(int i, void *cube_void);

/* ***************************************** */
/*			 DESTROY_IMAGES.C			  */
/* ***************************************** */
void			destroy_keys_images_end(t_cube *cube, t_keys_images *img);
void			destroy_keys_images_next(t_cube *cube, t_keys_images *img);
void			destroy_keys_images(t_cube *cube, t_keys_images *img);
void			destroy_settings_menu(t_cube *cube);
void			destroy_menu(t_cube *cube);

void			reset_settings_file(void);
void			check_settings(t_player_settings *settings);
void			init_player_binds(t_player_settings *settings);
void			edit_settings_file(t_cube *cube);
int				get_key_from_line(char *line);
char			*get_line_from_key(int key);
char			*get_line_from_key_part_one(int key);
char			*get_line_from_key_part_two(int key);
char			*get_line_from_key_part_three(int key);
char			*get_line_from_key_part_four(int key);
char			*get_line_from_key_part_five(int key);
int				get_key_from_line_part_one(char *line);
int				get_key_from_line_part_two(char *line);
int				get_key_from_line_part_three(char *line);
int				get_key_from_line_part_four(char *line);
int				get_key_from_line_part_five(char *line);
int				get_height(char *file);
t_map			*init_map(char *map_name);
void			render_key_images(t_cube *cube);
void			render_hover_button_in_keybind_menu_part_one(t_cube *cube);
void			render_hover_button_in_keybind_menu_part_two(t_cube *cube);
void			render_hover_button_in_keybind_menu_part_three(t_cube *cube);
void			render_hover_button(t_cube *cube);
void			handle_game_hook(t_cube *cube, int keycode);
void			handle_settings_hook(t_cube *cube, int keycode);
int				key_hook(int keycode, void *cube_void);
void			init(t_cube *cube);
int				mouse_move(void *cube_void);
int				mouse_press(int key, void *cube_void);
int				mouse_release(int keycode, void *cube_void);
void			open_settings(t_cube *cube);
void			open_video_settings_menu(t_cube *cube);
void			open_keybinds_menu(t_cube *cube);
void			open_music_and_sounds_menu(t_cube *cube);
void			*get_key_images(t_cube *cube, int key);
void			render_cube(t_cube *cube);
char			**parsing(t_map *map, char *file);
void			plotline(t_cube *cube, t_point point2, t_point point1);
void	        do_rays(t_cube *cube, t_ray *ray, int i);

#endif
