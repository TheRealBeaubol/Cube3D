/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:11:15 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/04 13:54:03 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*int	is_wall(t_cube *cube, int n)
{
	int	i;
	int	j;

	ft_printf("rayx: %d, rayy: %d\n", cube->player_settings->ray[n]->x, cube->player_settings->ray[n]->y);
	i = (cube->player_settings->ray[n]->y - (HEIGHT - cube->map->size_case * cube->map->height) / 2) / cube->map->size_case;
	j = (cube->player_settings->ray[n]->x - (WIDTH - cube->map->size_case * cube->map->width) / 2) / cube->map->size_case;
	if (cube->map->map[i][j] == '1')
		return (1);
	return (0);
}

char	*get_direction(t_cube *cube, int i)
{
	//if (135 < cube->player_settings->ray[i]->angle < 225)
		//return ("WEST");
	//if ( cube->player_settings->ray[i]->angle < 45)
		//return ("EAST");
	if ( 130 <= cube->player_settings->ray[i]->angle && cube->player_settings->ray[i]->angle >= 50)
		return ("NORTH");
	//if (cube->player_settings->ray[i]->angle)
		//return ("SOUTH");
	return ("CACA");
}

void	check_ray_north(t_cube *cube, int i)
{
	int	ox;
	int	oy;
	
	ft_printf("posx: %d, posy: %d\n", cube->player_settings->pos_x, cube->player_settings->pos_y);
	cube->player_settings->ray[i]->y = cube->player_settings->pos_y + cube->map->size_case;
	cube->player_settings->ray[i]->x = (cube->player_settings->pos_y - cube->player_settings->ray[i]->y) / -tan(cube->player_settings->looking_angle) + cube->player_settings->pos_x;
	oy = 50;
	ox = oy * tan(cube->player_settings->looking_angle);
	ft_printf("rayx: %d, rayy: %d\n", cube->player_settings->ray[i]->x, cube->player_settings->ray[i]->y);
	while (!is_wall(cube, i))
	{
		cube->player_settings->ray[i]->y += oy;
		cube->player_settings->ray[i]->x += ox;
	}
}

	void	check_ray_south(t_cube *cube, int i)
{
	int	ox;
	int	oy;

	cube->player_settings->ray[i]->y = cube->player_settings->pos_y - cube->map->size_case;
	cube->player_settings->ray[i]->x = (cube->player_settings->pos_y - cube->player_settings->ray[i]->y) / -tan(cube->player_settings->looking_angle) + cube->player_settings->pos_x;
	oy = 50;
	ox = oy * tan(cube->player_settings->looking_angle);
	while (!is_wall(cube, i))
	{
		cube->player_settings->ray[i]->y += oy;
		cube->player_settings->ray[i]->x += ox;
	}
}

void	check_ray_west(t_cube *cube, int i)
{
	int	ox;
	int	oy;

	cube->player_settings->ray[i]->x = cube->player_settings->pos_x + cube->map->size_case;
	cube->player_settings->ray[i]->y = (cube->player_settings->pos_x - cube->player_settings->ray[i]->x) / -tan(cube->player_settings->looking_angle) + cube->player_settings->pos_y;
	oy = 50;
	ox = oy * tan(cube->player_settings->looking_angle);
	while (!is_wall(cube, i))
	{
		cube->player_settings->ray[i]->y += oy;
		cube->player_settings->ray[i]->x += ox;
	}
}

void	check_ray_east(t_cube *cube, int i)
{
	int	ox;
	int	oy;

	cube->player_settings->ray[i]->x = cube->player_settings->pos_x - cube->map->size_case;
	cube->player_settings->ray[i]->y = (cube->player_settings->pos_x - cube->player_settings->ray[i]->x) / -tan(cube->player_settings->looking_angle) + cube->player_settings->pos_y;
	oy = 50;
	ox = oy * tan(cube->player_settings->looking_angle);
	while (!is_wall(cube, i))
	{
		cube->player_settings->ray[i]->y += oy;
		cube->player_settings->ray[i]->x += ox;
	}
}

void	drawing_wall(t_cube *cube)
{
	int	i;
	int	j;
	int	begin;
	int	end;

	i = -1;
	while (cube->player_settings->ray[++i])
	{
		cube->player_settings->ray[i]->len = sqrt(powf(cube->player_settings->ray[i]->x - cube->player_settings->pos_x, 2) + powf(cube->player_settings->ray[i]->y - cube->player_settings->pos_y, 2));
		
		cube->player_settings->ray[i]->wall_height = (cube->map->size_case * HEIGHT) / cube->player_settings->ray[i]->len;
		begin = (HEIGHT / 2) - cube->player_settings->ray[i]->wall_height;
		end = (HEIGHT / 2) + cube->player_settings->ray[i]->wall_height;
		j = begin - 1;
		while(++j < end)
			mlx_set_image_pixel(cube->mlx_ptr, cube->img, i, j, 0xFFCACAFF);
	}
}

void    find_player(t_cube *cube)
{
    int    i;
    int    j;

    i = -1;
    while (cube->map->map[++i])
    {
        j = -1;
        while (cube->map->map[i][++j])
        {
            if (cube->map->map[i][j] == 'N' || cube->map->map[i][j] == 'S' || cube->map->map[i][j] == 'W' || cube->map->map[i][j] == 'E')
            {
                cube->player_settings->pos_x = j * cube->map->size_case + cube->map->size_case / 2 + (HEIGHT - cube->map->size_case * cube->map->height) / 2;
                cube->player_settings->pos_y = i * cube->map->size_case + cube->map->size_case / 2 + (WIDTH - cube->map->size_case * cube->map->width) / 2;
                ft_printf("cube->player_settings->pos_x = %d\n", cube->player_settings->pos_x);
                ft_printf("cube->player_settings->pos_y = %d\n", cube->player_settings->pos_y);
                if (cube->map->map[i][j] == 'N')
                    cube->player_settings->looking_angle = 90;
                else if (cube->map->map[i][j] == 'S')
                    cube->player_settings->looking_angle = 180;
                else if (cube->map->map[i][j] == 'W')
                    cube->player_settings->looking_angle = 270;
                else if (cube->map->map[i][j] == 'E')
                    cube->player_settings->looking_angle = 0;
            }
        }
    }
}

void	search_looking(t_cube *cube)
{
	int	i;

	i = -1;
	find_player(cube);
	cube->player_settings->ray = feed_ray_tab(cube->player_settings);
	while (cube->player_settings->ray[++i])
	{
		if (ft_strncmp(get_direction(cube, i), "NORTH", 5))
			check_ray_north(cube, i);
		if (ft_strncmp(get_direction(cube, i), "SOUTH", 5))
			check_ray_south(cube, i);
		if (ft_strncmp(get_direction(cube, i), "WEST", 4))
			check_ray_west(cube, i);
		if (ft_strncmp(get_direction(cube, i), "EAST", 4))
			check_ray_east(cube, i);
	}
	drawing_wall(cube);
}*/
