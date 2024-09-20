/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:32:33 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/05 20:04:31 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_key_from_line(char *line, t_key_map *key_map)
{
	int	i;

	i = 0;
	line[ft_strlen(line) - 1] = '\0';
	while (*line != '=')
		line++;
	line += 2;
	while (i <= 256)
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
	while (i <= 256)
	{
		if (key_map[i].key_value == key)
			return (ft_strdup(key_map[i].key_name));
		i++;
	}
	return (NULL);
}
