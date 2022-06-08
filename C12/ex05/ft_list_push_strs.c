/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:16:03 by alex              #+#    #+#             */
/*   Updated: 2020/08/01 22:07:47 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_front(t_list **head, void *data)
{
	t_list	*node;

	node = ft_create_elem(data);
	node->next = (*head);
	(*head) = node;
}

t_list		*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;

	list = NULL;
	while (size--)
		ft_list_push_front(&list, *strs++);
	return (list);
}
