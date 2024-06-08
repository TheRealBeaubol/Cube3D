/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_from_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 22:08:26 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/02 22:16:40 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_line_from_key_part_one(int key)
{
	if (key == KEY_A)
		return (ft_strdup("A"));
	if (key == KEY_B)
		return (ft_strdup("B"));
	if (key == KEY_C)
		return (ft_strdup("C"));
	if (key == KEY_D)
		return (ft_strdup("D"));
	if (key == KEY_E)
		return (ft_strdup("E"));
	if (key == KEY_F)
		return (ft_strdup("F"));
	if (key == KEY_G)
		return (ft_strdup("G"));
	if (key == KEY_H)
		return (ft_strdup("H"));
	if (key == KEY_I)
		return (ft_strdup("I"));
	if (key == KEY_J)
		return (ft_strdup("J"));
	if (key == KEY_K)
		return (ft_strdup("K"));
	if (key == KEY_L)
		return (ft_strdup("L"));
	return (NULL);
}

char	*get_line_from_key_part_two(int key)
{
	if (key == KEY_M)
		return (ft_strdup("M"));
	if (key == KEY_N)
		return (ft_strdup("N"));
	if (key == KEY_O)
		return (ft_strdup("O"));
	if (key == KEY_P)
		return (ft_strdup("P"));
	if (key == KEY_Q)
		return (ft_strdup("Q"));
	if (key == KEY_R)
		return (ft_strdup("R"));
	if (key == KEY_S)
		return (ft_strdup("S"));
	if (key == KEY_T)
		return (ft_strdup("T"));
	if (key == KEY_U)
		return (ft_strdup("U"));
	if (key == KEY_V)
		return (ft_strdup("V"));
	if (key == KEY_W)
		return (ft_strdup("W"));
	if (key == KEY_X)
		return (ft_strdup("X"));
	return (NULL);
}

char	*get_line_from_key_part_three(int key)
{
	if (key == KEY_Y)
		return (ft_strdup("Y"));
	if (key == KEY_Z)
		return (ft_strdup("Z"));
	if (key == KEY_0)
		return (ft_strdup("0"));
	if (key == KEY_1)
		return (ft_strdup("1"));
	if (key == KEY_2)
		return (ft_strdup("2"));
	if (key == KEY_3)
		return (ft_strdup("3"));
	if (key == KEY_4)
		return (ft_strdup("4"));
	if (key == KEY_5)
		return (ft_strdup("5"));
	if (key == KEY_6)
		return (ft_strdup("6"));
	if (key == KEY_7)
		return (ft_strdup("7"));
	if (key == KEY_8)
		return (ft_strdup("8"));
	if (key == KEY_9)
		return (ft_strdup("9"));
	return (NULL);
}

char	*get_line_from_key_part_four(int key)
{
	if (key == TAB)
		return (ft_strdup("TAB"));
	if (key == SPACE)
		return (ft_strdup("SPACE"));
	if (key == ARROW_RIGHT)
		return (ft_strdup("ARROW_RIGHT"));
	if (key == ARROW_LEFT)
		return (ft_strdup("ARROW_LEFT"));
	if (key == ARROW_UP)
		return (ft_strdup("ARROW_UP"));
	if (key == ARROW_DOWN)
		return (ft_strdup("ARROW_DOWN"));
	if (key == KEYPAD_DIV)
		return (ft_strdup("KEYPAD_DIV"));
	if (key == KEYPAD_MULT)
		return (ft_strdup("KEYPAD_MULT"));
	if (key == KEYPAD_PLUS)
		return (ft_strdup("KEYPAD_PLUS"));
	if (key == KEYPAD_MINUS)
		return (ft_strdup("KEYPAD_MINUS"));
	if (key == KEYPAD_0)
		return (ft_strdup("KEYPAD_0"));
	if (key == KEYPAD_1)
		return (ft_strdup("KEYPAD_1"));
	return (NULL);
}

char	*get_line_from_key_part_five(int key)
{
	if (key == KEYPAD_2)
		return (ft_strdup("KEYPAD_2"));
	if (key == KEYPAD_3)
		return (ft_strdup("KEYPAD_3"));
	if (key == KEYPAD_4)
		return (ft_strdup("KEYPAD_4"));
	if (key == KEYPAD_5)
		return (ft_strdup("KEYPAD_5"));
	if (key == KEYPAD_6)
		return (ft_strdup("KEYPAD_6"));
	if (key == KEYPAD_7)
		return (ft_strdup("KEYPAD_7"));
	if (key == KEYPAD_8)
		return (ft_strdup("KEYPAD_8"));
	if (key == KEYPAD_9)
		return (ft_strdup("KEYPAD_9"));
	if (key == CTRL)
		return (ft_strdup("CTRL"));
	if (key == SHIFT)
		return (ft_strdup("SHIFT"));
	return (NULL);
}
