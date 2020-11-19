/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 23:25:03 by alex              #+#    #+#             */
/*   Updated: 2020/07/16 00:12:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_create_elem(void *data)
{
	t_list	*new_node;

	if (!(new_node = (t_list *) malloc(sizeof(t_list))))
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}
