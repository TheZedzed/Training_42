/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:25:28 by alex              #+#    #+#             */
/*   Updated: 2020/06/22 15:39:01 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	size;

	size = ft_strnlen(src, n);
	if (size != n)
		ft_memset(dest + size, 0, n - size);
	return (ft_memcpy(dest, src, size));
}
