/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:32:33 by lboiteux          #+#    #+#             */
/*   Updated: 2024/10/22 01:19:12 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_key_from_line(char *line, t_key_map *key_map)
{
	int	i;

	i = 0;
	while (i < 54)
	{
		if (!ft_strcmp(key_map[i].key_name, line))
			return (key_map[i].key_value);
		i++;
	}
	return (-1);
}

char	*get_line_from_key(int key, t_key_map *key_map)
{
	int	i;

	i = 0;
	while (i < 54)
	{
		if (key_map[i].key_value == key)
			return (ft_strdup(key_map[i].key_name));
		i++;
	}
	return (NULL);
}
