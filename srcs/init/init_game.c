/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:05:36 by lboiteux          #+#    #+#             */
/*   Updated: 2024/10/24 21:34:27 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_mlx(t_cube *cube)
{
	cube->mlx.ptr = mlx_init();
	if (cube->mlx.ptr == NULL)
		free_init_and_exit (cube, "\033[1;31mError\nmlx pointer initialization \
failed\n\033[0m", 0);
	printf("\033[1;32mPreloading textures...\033[0m\n");
	cube->mlx.win = mlx_new_window(cube->mlx.ptr, WIDTH, HEIGHT, "Cube3D");
	if (cube->mlx.win == NULL)
		free_init_and_exit (cube, "\033[1;31mError\nmlx window initialization \
failed\n\033[0m", 1);
	cube->mlx.background_img = mlx_new_image(cube->mlx.ptr, WIDTH, HEIGHT);
	draw_first_background(cube);
	preload_textures(cube);
}

void	start_game(t_cube *cube, void *mlx_ptr, void *win_ptr)
{
	cube->is_in_menu = 1;
	cube->is_in_game = 0;
	cube->is_in_settings = 0;
	cube->menu.waiting_for_key = 0;
	mlx_put_image_to_window(mlx_ptr, win_ptr, cube->menu.background, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, \
cube->menu.play_button.img, (WIDTH - cube->menu.play_button.width) / \
2, ((HEIGHT - cube->menu.play_button.height) / 2) - 200);
	mlx_put_image_to_window(mlx_ptr, win_ptr, \
cube->menu.settings_button.img, (WIDTH - cube->menu.settings_button.width) / \
2, ((HEIGHT - cube->menu.settings_button.height) / 2));
	mlx_put_image_to_window(mlx_ptr, win_ptr, \
cube->menu.exit_button.img, (WIDTH - cube->menu.exit_button.width) / \
2, ((HEIGHT - cube->menu.exit_button.height) / 2) + 200);
}

void	check_images_access(t_cube *cube, const char **paths)
{
	int	i;

	i = -1;
	while (++i < 79)
	{
		if (access(paths[i], F_OK) == -1)
		{
			printf("\033[1;31mError\n%s not found\n\033[0m", paths[i]);
			free_init_and_exit(cube, NULL, 0);
		}
	}
}

void	check_images_access_init(t_cube *cube)
{
	const char	*paths[79] = {"images/1.png", "images/2.png", "images/3.png", \
"images/4.png", "images/5.png", "images/6.png", "images/7.png", "images/8.png", \
"images/9.png", "images/0.png", "images/A.png", "images/B.png", "images/C.png", \
"images/D.png", "images/E.png", "images/F.png", "images/G.png", "images/H.png", \
"images/I.png", "images/J.png", "images/K.png", "images/L.png", "images/M.png", \
"images/N.png", "images/O.png", "images/P.png", "images/Q.png", "images/R.png", \
"images/S.png", "images/T.png", "images/U.png", "images/V.png", "images/W.png", \
"images/X.png", "images/Y.png", "images/Z.png", "images/NUM0.png", \
"images/NUM1.png", "images/NUM2.png", "images/NUM3.png", "images/NUM4.png", \
"images/NUM5.png", "images/NUM6.png", "images/NUM7.png", "images/NUM8.png", \
"images/NUM9.png", "images/SHIFT.png", "images/CTRL.png", "images/SPACE.png", \
"images/TAB.png", "images/NUMMULT.png", "images/NUMPLUS.png", \
"images/NUMMINUS.png", "images/NUMDIVIDE.png", "images/portal_1.png", \
"images/portal_2.png", "images/portal_3.png", "images/portal_4.png", \
"images/portal_5.png", "images/portal_6.png", "images/portal_7.png", \
"images/portal_8.png", "images/portal_9.png", "images/portal_10.png", \
"images/portal_11.png", "images/background.png", "images/play_button.png", \
"images/settings_button.png", "images/exit_button.png", \
"images/keybinds_define_button.png", "images/keybinds_menu.png", \
"images/keybinds_define_button_hover.png", "images/play_button_hover.png", \
"images/settings_button_hover.png", "images/exit_button_hover.png", \
"images/player.png", "images/portal_0.png", "sounds/click.ogg", \
"sounds/hover.ogg"};

	check_images_access(cube, paths);
}

void	init(t_cube *cube)
{
	int	i;

	init_portal(cube);
	init_settings_file();
	init_key_map(cube);
	init_player_binds(&cube->settings);
	check_images_access_init(cube);
	i = -1;
	while (++i < 256)
		cube->settings.key_tab[i] = 0;
	init_mlx(cube);
	init_images(cube->mlx.ptr, &cube->menu);
	cube->menu.sounds = ft_calloc(7, sizeof(int));
	printf("\033[1;32mStarting game...\033[0m\n");
	start_game(cube, cube->mlx.ptr, cube->mlx.win);
}
