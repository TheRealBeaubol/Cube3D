/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:11:15 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/03 16:13:43 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ray   **feed_ray_tab(t_player_settings *player)
{
    t_ray   **ray;
    int i;

    ray = ft_calloc(player->fov, sizeof(t_ray));
    if (!ray)
        return (NULL);
    i = 0;
    ray[i]->angle = player->looking_angle;
    ray[i]->x = get_ray_x();
    ray[i]->y = get_ray_y();
    while (++i < player->fov)
    {
        if (ray[i - 1]->angle < 90)
            ray[i]->angle = ray[i - 1]->angle - 1;
        else
        {
            if (player->looking_angle + player->fov / 2 == ray[i - 1]->angle)
                ray[i]->angle = player->looking_angle - 1;
            else
                ray[i]->angle = ray[i - 1]->angle + 1;       
        }
        ray[i]->x = get_ray_x();
        ray[i]->y = get_ray_y();
    }
    return (ray);
}