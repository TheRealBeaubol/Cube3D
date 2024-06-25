/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/25 22:55:36 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_fps_counter
{
	clock_t	last_time;
	clock_t	last_avg_time;
	int		frame_count;
	float	fps_sum;
}	t_fps_counter;

typedef struct s_settings_menu_images
{
	void	*img;
	int		width;
	int		height;
	void	*img_hover;
	int		width_hover;
	int		height_hover;
	int		status;
}	t_settings_menu_images;

typedef struct s_image_and_keys
{
	void	*img;
	int		key;
}	t_image_and_keys;

typedef struct s_key_map
{
    char *key_name;
    int key_value;
} t_key_map;

typedef struct s_keys
{
	char	*path;
	void	*img;
}	t_keys;

typedef struct s_point
{
    float    x;
    float    y;
}    t_point;

typedef struct s_int_point
{
	int    x;
	int    y;
}    t_int_point;

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	e_direction;

typedef struct s_ray
{
	e_direction	direction;
	t_point		pos;
	t_point		ray_dir;
	t_point		side_dist;
	t_point		delta_dist;
	t_int_point	map;
	t_int_point	step_dir;
	float		lenght;
	float		camera_x;
	float		step;
	float		tex_pos;
	int			tex_x;
	int			wall_height;
	int			side;
	int			hit_wall;

}	t_ray;

typedef struct s_menu
{
	t_keys					keys[54];
	t_image_and_keys		keybinds[54];
	void					*background;
	int						waiting_for_key;
	int						key;
	int						keybind_menu_indice;
	t_settings_menu_images	play_button;
	t_settings_menu_images	settings_button;
	t_settings_menu_images	exit_button;
	t_settings_menu_images	keybinds_button;
	t_settings_menu_images	video_settings_button;
	t_settings_menu_images	music_and_sounds_button;
	t_settings_menu_images	back_button;
	t_settings_menu_images	keybinds_define_button;
	t_settings_menu_images	video_settings_menu;
	t_settings_menu_images	keybinds_menu;
	t_settings_menu_images	music_and_sounds_menu;
}	t_menu;

typedef enum e_move
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
}	e_move;

typedef struct s_player_settings
{
	t_key_map	key_map[64];
	int		key_tab[256];
	int		move_forward;
	int		move_backward;
	int		move_left;
	int		move_right;
	t_point	pos;
	t_point	plane;
	t_point	dir;
	// e_move	move;
	// float	looking_angle;
	t_ray	**ray;
}	t_player_settings;

typedef struct s_image
{
	int		*texture;
	void	*image;
	int		width;
	int		height;
}	t_image;

typedef struct s_map
{
	int		height;
	int		width;
	char	**map;
	char	**texture_paths;
	unsigned long	ceiling_color;
	unsigned long	floor_color;
	t_image	no_texture;
	t_image	so_texture;
	t_image	we_texture;
	t_image	ea_texture;
	t_image	actual_texture;
}	t_map;

typedef	struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	void	*background_img;
	void	*minimap_img;
}	t_mlx;


typedef struct s_cube
{
	char				*map_name;
	t_map				map;
	t_player_settings	settings;
	t_mlx				mlx;
	t_menu				menu;
	int					is_in_menu;
	int					is_in_game;
	int					is_in_settings;
	// int					start_x;
	// int					start_y;
}	t_cube;

#endif
