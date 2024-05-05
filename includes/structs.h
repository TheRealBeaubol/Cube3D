/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:13:40 by lboiteux          #+#    #+#             */
/*   Updated: 2024/05/05 22:47:34 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_menu
{
	void	*play_button;
	void	*option_button;
	void	*exit_button;
	void	*play_button_hover;
	void	*option_button_hover;
	void	*exit_button_hover;

}	t_menu;

typedef struct s_cube
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*img;
	t_menu	*menu;
}	t_cube;

#endif