/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 21:35:30 by alex              #+#    #+#             */
/*   Updated: 2020/08/01 00:58:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*curr;
	t_list	*previous;
	t_list	*last_node;

	if (begin_list)
	{
		previous = NULL;
		curr = (*begin_list);
		last_node = ft_create_elem(data);
		while (curr)
		{
			previous = curr;
			curr = curr->next;
		}
		previous->next = last_node;
	}
}
