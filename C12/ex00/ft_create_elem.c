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

t_list	*ft_create_elem(void *data)
{
	t_list	*new_elem;

	if (!(new_elem = (t_list*) malloc(sizeof(*new_elem))))
		return (NULL);
	(*new_elem).data = data;
	new_elem->next = NULL;
	return (new_elem);
}

int	main(void)
{
	t_list	*tronc;

	tronc = ft_create_elem("dur");

	/* write into a struct */
	(*tronc).data = "mou";
	tronc->data = "mou";
	tronc[0].data = "lol";
	/* print */
	write(1, (*tronc).data, 4);
	write(1, tronc->data, 4);
	write(1, tronc[0].data, 4);
	return (0);
}
