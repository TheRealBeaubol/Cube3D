/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/12 23:20:43 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_settings_menu
{
	void	*keybinds_button;
	void	*keybinds_button_hover;
	int		keybinds_button_status;
	void	*video_settings_button;
	void	*video_settings_button_hover;
	int		video_settings_button_status;
	void	*music_and_sounds_button;
	void	*music_and_sounds_button_hover;
	int		music_and_sounds_button_status;
	void	*back_button;
	void	*back_button_hover;
	int		back_button_status;
	int		button_height;
	int		button_width;
	int		is_in_settings_menu;
}	t_settings_menu;

typedef struct s_menu
{
	void			*play_button;
	void			*play_button_hover;
	int				play_button_status;
	void			*settings_button;
	void			*settings_button_hover;
	int				settings_button_status;
	void			*exit_button;
	void			*exit_button_hover;
	int				exit_button_status;
	void			*start_background;
	int				button_height;
	int				button_width;
	int				is_in_menu;
	t_settings_menu	*settings_menu;
}	t_menu;

typedef struct s_cube
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*img;
	t_menu	*menu;
}	t_cube;

#endif