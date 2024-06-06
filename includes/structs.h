/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/06 12:09:56 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_keys_images
{
	void	*key_a;
	void	*key_b;
	void	*key_c;
	void	*key_d;
	void	*key_e;
	void	*key_f;
	void	*key_g;
	void	*key_h;
	void	*key_i;
	void	*key_j;
	void	*key_k;
	void	*key_l;
	void	*key_m;
	void	*key_n;
	void	*key_o;
	void	*key_p;
	void	*key_q;
	void	*key_r;
	void	*key_s;
	void	*key_t;
	void	*key_u;
	void	*key_v;
	void	*key_w;
	void	*key_x;
	void	*key_y;
	void	*key_z;
	void	*key_0;
	void	*key_1;
	void	*key_2;
	void	*key_3;
	void	*key_4;
	void	*key_5;
	void	*key_6;
	void	*key_7;
	void	*key_8;
	void	*key_9;
	void	*key_space;
	void	*key_shift;
	void	*key_num_0;
	void	*key_num_1;
	void	*key_num_2;
	void	*key_num_3;
	void	*key_num_4;
	void	*key_num_5;
	void	*key_num_6;
	void	*key_num_7;
	void	*key_num_8;
	void	*key_num_9;
	void	*key_num_div;
	void	*key_num_mult;
	void	*key_num_minus;
	void	*key_num_plus;
	void	*key_ctrl;
	void	*key_tab;
}	t_keys_images;

typedef struct s_settings_menu
{
	void			*keybinds_button;
	void			*keybinds_button_hover;
	int				keybinds_button_status;
	void			*video_settings_button;
	void			*video_settings_button_hover;
	int				video_settings_button_status;
	void			*music_and_sounds_button;
	void			*music_and_sounds_button_hover;
	int				music_and_sounds_button_status;
	void			*back_button;
	void			*back_button_hover;
	int				back_button_status;
	void			*video_settings_menu;
	void			*keybinds_menu;
	void			*music_and_sounds_menu;
	int				settings_menu_height;
	int				settings_menu_width;
	int				button_height;
	int				button_width;
	void			*keybinds_define_button;
	void			*keybinds_define_button_hover;
	int				keybinds_define_button_status;
	int				waiting_for_key;
	int				key;
	int				is_in_keybinds_menu;
	int				is_in_settings_menu;
	int				keybind_menu_indice;
	t_keys_images	*keys_images;
}	t_settings_menu;

typedef struct s_point
{
    double    x;
    double    y;
}    t_point;

typedef struct s_plotline
{
    int        dx;
    int        dy;
    int        yi;
    int        xi;
    int        d;
    double    y;
    double    x;
}    t_plotline;

typedef struct s_ray
{
	t_point	coor;
	//double	angle;
	//float	len;
	//float	wall_height;
}	t_ray;

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

typedef struct s_player_settings
{
	int		move_forward;
	int		move_backward;
	int		move_left;
	int		move_right;
	t_point	pos;
	double	dir_x;
	double	dir_y;
	float	looking_angle;
	int		fov;
	t_ray	*ray;
}	t_player_settings;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		size_case;
	int		player_size;
}	t_map;

typedef struct s_cube
{
	void				*mlx_ptr;
	void				*window_ptr;
	void				*img;
	t_menu				*menu;
	t_player_settings	*player_settings;
	t_map				*map;
	t_plotline			*plotline;
	int					is_in_game;
	char				*map_name;
	int					start_x;
	int					start_y;
}	t_cube;

#endif
