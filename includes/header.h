/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:43 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/07 15:47:04 by lboiteux         ###   ########.fr       */
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
int     mouse_move(void *cube_void);
int	    mouse_press(int key, void *cube_void);
int	    mouse_release(int keycode, void *cube_void);

#endif