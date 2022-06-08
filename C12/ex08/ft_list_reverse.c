/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 00:53:41 by alex              #+#    #+#             */
/*   Updated: 2020/08/02 01:23:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*next;
	t_list	*previous;

	if (begin_list)
	{
		current = (*begin_list);
		next = NULL;
		previous = NULL;
		while (current)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		(*begin_list) = previous;
	}
}
