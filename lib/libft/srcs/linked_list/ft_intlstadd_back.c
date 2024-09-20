/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlstadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:48:25 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 10:23:37 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intlstadd_back(t_intlist **lst, t_intlist *new)
{
	t_intlist	*l;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		l = ft_intlstlast(*lst);
		l->next = new;
	}
}
