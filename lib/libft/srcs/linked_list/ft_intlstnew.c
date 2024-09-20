/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:58:15 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 10:19:48 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_intlist	*ft_intlstnew(int content)
{
	t_intlist	*var;

	var = malloc (sizeof(t_intlist));
	if (var == NULL)
		return (NULL);
	var->content = content;
	var->next = NULL;
	return (var);
}
