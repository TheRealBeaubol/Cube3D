/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:42 by lboiteux          #+#    #+#             */
/*   Updated: 2024/09/20 19:22:58 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <SDL2/SDL_scancode.h>
# include "mlx.h"
# include "mlx_profile.h"

# define PI 3.1415926536
# define WIDTH 1920
# define HEIGHT 1080
# define ERROR_MISSING_ELEMENT "\033[1;31mError\nColor(s) or/and wall \
sprite(s) is(are) missing\n\033[0m"
# define ERROR_UNRECOGNIZED_TOKEN "\033[1;31mError\nUnrecognized token \
while parsing map\n\033[0m"
# define ERROR_COLOR_FORMAT "\033[1;31mError\nWrong color format\n\033[0m"
# define ERROR_NO_SPAWN "\033[1;31mError\nNo player spawn found\n\033[0m"
# define ERROR_MULTIPLE_SPAWN "\033[1;31mError\nMultiple player spawns \
found\n\033[0m"
#endif