/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:49:37 by alex              #+#    #+#             */
/*   Updated: 2020/07/10 22:50:03 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char	*psrc;
	unsigned char	*pdest;

	pdest = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	while (*psrc && n--)
	{
		*pdest++ = *psrc;
		if (*psrc++ == (unsigned char)c)
			return ((void *)pdest);
	}
	return (NULL);
}
