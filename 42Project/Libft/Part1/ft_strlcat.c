/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:02:14 by alex              #+#    #+#             */
/*   Updated: 2020/04/28 19:01:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen((const char *)dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	src_len = 0;
	while (src[src_len] && (dst_len + src_len) < size - 1)
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
	}
	dst[dst_len + src_len] = '\0';
	return (src_len + dst_len);
}
