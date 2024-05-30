/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:02:00 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/30 15:23:43 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_map	*init_map(t_map *map_data)
{
	map_data->size_x = 7;
	map_data->size_y = 7;
	map_data->size_case = 50;
	map_data->player_size = 10;
	return (map_data);
}
