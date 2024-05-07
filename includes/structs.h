/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/07 16:13:46 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_options_menu
{
	void	*options_menu;
}	t_options_menu;

typedef struct s_menu
{
	void			*play_button;
	void			*play_button_hover;
	int				play_button_status;
	void			*options_button;
	void			*options_button_hover;
	int				options_button_status;
	void			*exit_button;
	void			*exit_button_hover;
	int				exit_button_status;
	void			*start_background;
	int				button_height;
	int				button_width;
	int				is_in_menu;
	t_options_menu	*options_menu;
}	t_menu;

typedef struct s_cube
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*img;
	t_menu	*menu;
}	t_cube;

#endif