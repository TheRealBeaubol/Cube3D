/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:22:06 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/02 16:23:49 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_cube			cube;

	check_args(ac, av);
	cube.map_name = av[1];
	if (parsing(&cube) == -1)
		return (-1);
	init(&cube);
	hook(&cube);
	return (0);
}
