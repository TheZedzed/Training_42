/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:31:01 by alex              #+#    #+#             */
/*   Updated: 2020/07/07 13:28:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!ptr)
	{
		if (!(new = malloc(size)))
			return (NULL);
	}
	else
	{
		if(!(new = malloc(size)))
			return (NULL);
		ft_memcpy(new, ptr, size);
		free(ptr);
	}
	return (new);
}
