/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:17:09 by alex              #+#    #+#             */
/*   Updated: 2020/08/09 14:29:02 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*previous;
	t_list	*current;
	t_list	*next;

	current = (*begin_list);
	previous = NULL;
	next = NULL;
	while (current)
	{
		next = current->next;
		if (!previous && !(*cmp)(current->data, data_ref))
		{
			(*free_fct)(current->data);
			free(current);
			current = next;
		}
		if (!next->next && !(*cmp)(next->data, data_ref))
		{
			(*free_fct)(next->data);
			free(next);
		}
		else
		{
		}
	}
}
