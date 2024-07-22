/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:22:06 by lboiteux          #+#    #+#             */
/*   Updated: 2024/07/22 14:02:27 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_cube			cube;

	check_args(ac, av);
	cube.map_name = av[1];
	printf("\033[1;32mParsing...\033[0m\n");
	if (parsing(&cube) == -1)
		return (-1);
	printf("\033[1;32mInit...\033[0m\n");
	init(&cube);
	hook(&cube);
	return (0);
}
