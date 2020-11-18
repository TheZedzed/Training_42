/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:19:27 by alex              #+#    #+#             */
/*   Updated: 2020/06/22 01:02:13 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void					*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*psrc;
	unsigned char		*pdest;

	psrc = (const unsigned char *)src;
	pdest = (unsigned char *)dest;
	if (psrc != pdest)
	{
		if (psrc < pdest && pdest < psrc + n)
		{
			psrc += n;
			pdest += n;
			while (n--)
				*--pdest = *--psrc;
		}
		else
		{
			while (n--)
				*pdest++ = *psrc++;
		}
	}
	return (dest);
}
