/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:43 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/05 22:46:22 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "define.h"
# include "structs.h"

void	free_and_destroy(t_cube *cube);
int		free_and_destroy_exit(int i, void *cube_void);
int		key_hook(int keycode, void *cube_void);
void	init(t_cube *cube);
void	print_map(char **map, t_cube *cube);

#endif
