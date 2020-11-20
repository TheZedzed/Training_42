/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 00:04:02 by alex              #+#    #+#             */
/*   Updated: 2020/08/02 00:37:49 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

unsigned int		ft_list_size(t_list *begin_list)
{
	unsigned int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

t_list				*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	size;

	if (begin_list)
	{
		size = ft_list_size(begin_list);
		if (nbr < 1 || nbr > size)
			return (NULL);
		while (--nbr)
			begin_list = begin_list->next;
		return (begin_list);
	}
}
