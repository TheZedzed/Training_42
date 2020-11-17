/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:53:15 by alex              #+#    #+#             */
/*   Updated: 2020/06/22 15:16:12 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*str;

	str = dest + ft_strlen(dest);
	n = ft_strnlen(src, n);
	str[n] = 0;
	ft_memcpy(str, src, n);
	return (dest);
}
