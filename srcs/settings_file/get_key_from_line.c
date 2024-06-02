/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_from_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:49:56 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/02 22:28:29 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_key_from_line_part_one(char *line)
{
	if (!ft_strncmp(line, "A", 2))
		return (KEY_A);
	if (!ft_strncmp(line, "B", 2))
		return (KEY_B);
	if (!ft_strncmp(line, "C", 2))
		return (KEY_C);
	if (!ft_strncmp(line, "D", 2))
		return (KEY_D);
	if (!ft_strncmp(line, "E", 2))
		return (KEY_E);
	if (!ft_strncmp(line, "F", 2))
		return (KEY_F);
	if (!ft_strncmp(line, "G", 2))
		return (KEY_G);
	if (!ft_strncmp(line, "H", 2))
		return (KEY_H);
	if (!ft_strncmp(line, "I", 2))
		return (KEY_I);
	if (!ft_strncmp(line, "J", 2))
		return (KEY_J);
	if (!ft_strncmp(line, "K", 2))
		return (KEY_K);
	if (!ft_strncmp(line, "L", 2))
		return (KEY_L);
	return (-1);
}

int	get_key_from_line_part_two(char *line)
{
	if (!ft_strncmp(line, "M", 2))
		return (KEY_M);
	if (!ft_strncmp(line, "N", 2))
		return (KEY_N);
	if (!ft_strncmp(line, "O", 2))
		return (KEY_O);
	if (!ft_strncmp(line, "P", 2))
		return (KEY_P);
	if (!ft_strncmp(line, "Q", 2))
		return (KEY_Q);
	if (!ft_strncmp(line, "R", 2))
		return (KEY_R);
	if (!ft_strncmp(line, "S", 2))
		return (KEY_S);
	if (!ft_strncmp(line, "T", 2))
		return (KEY_T);
	if (!ft_strncmp(line, "U", 2))
		return (KEY_U);
	if (!ft_strncmp(line, "V", 2))
		return (KEY_V);
	if (!ft_strncmp(line, "W", 2))
		return (KEY_W);
	if (!ft_strncmp(line, "X", 2))
		return (KEY_X);
	return (-1);
}

int	get_key_from_line_part_three(char *line)
{
	if (!ft_strncmp(line, "Y", 2))
		return (KEY_Y);
	if (!ft_strncmp(line, "Z", 2))
		return (KEY_Z);
	if (!ft_strncmp(line, "1", 2))
		return (KEY_1);
	if (!ft_strncmp(line, "2", 2))
		return (KEY_2);
	if (!ft_strncmp(line, "3", 2))
		return (KEY_3);
	if (!ft_strncmp(line, "4", 2))
		return (KEY_4);
	if (!ft_strncmp(line, "5", 2))
		return (KEY_5);
	if (!ft_strncmp(line, "6", 2))
		return (KEY_6);
	if (!ft_strncmp(line, "7", 2))
		return (KEY_7);
	if (!ft_strncmp(line, "8", 2))
		return (KEY_8);
	if (!ft_strncmp(line, "9", 2))
		return (KEY_9);
	if (!ft_strncmp(line, "0", 2))
		return (KEY_0);
	return (-1);
}

int	get_key_from_line_part_four(char *line)
{
	if (!ft_strncmp(line, "TAB", 4))
		return (TAB);
	if (!ft_strncmp(line, "SPACE", 6))
		return (SPACE);
	if (!ft_strncmp(line, "ARROW_RIGHT", 12))
		return (ARROW_RIGHT);
	if (!ft_strncmp(line, "ARROW_LEFT", 11))
		return (ARROW_LEFT);
	if (!ft_strncmp(line, "ARROW_DOWN", 11))
		return (ARROW_DOWN);
	if (!ft_strncmp(line, "ARROW_UP", 9))
		return (ARROW_UP);
	if (!ft_strncmp(line, "KEYPAD_DIV", 10))
		return (KEYPAD_DIV);
	if (!ft_strncmp(line, "KEYPAD_MULT", 11))
		return (KEYPAD_MULT);
	if (!ft_strncmp(line, "KEYPAD_MINUS", 12))
		return (KEYPAD_MINUS);
	if (!ft_strncmp(line, "KEYPAD_PLUS", 11))
		return (KEYPAD_PLUS);
	if (!ft_strncmp(line, "KEYPAD_1", 9))
		return (KEYPAD_1);
	if (!ft_strncmp(line, "KEYPAD_2", 9))
		return (KEYPAD_2);
	return (-1);
}

int	get_key_from_line_part_five(char *line)
{
	if (!ft_strncmp(line, "KEYPAD_3", 9))
		return (KEYPAD_3);
	if (!ft_strncmp(line, "KEYPAD_4", 9))
		return (KEYPAD_4);
	if (!ft_strncmp(line, "KEYPAD_5", 9))
		return (KEYPAD_5);
	if (!ft_strncmp(line, "KEYPAD_6", 9))
		return (KEYPAD_6);
	if (!ft_strncmp(line, "KEYPAD_7", 9))
		return (KEYPAD_7);
	if (!ft_strncmp(line, "KEYPAD_8", 9))
		return (KEYPAD_8);
	if (!ft_strncmp(line, "KEYPAD_9", 9))
		return (KEYPAD_9);
	if (!ft_strncmp(line, "KEYPAD_0", 9))
		return (KEYPAD_0);
	if (!ft_strncmp(line, "CTRL", 5))
		return (CTRL);
	if (!ft_strncmp(line, "SHIFT", 6))
		return (SHIFT);
	return (-1);
}
