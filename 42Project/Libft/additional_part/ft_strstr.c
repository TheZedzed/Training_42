/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 12:26:56 by alex              #+#    #+#             */
/*   Updated: 2020/06/27 15:44:35 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		needle_size;

	if (!*needle)
		return ((char *)haystack);
	needle_size = ft_strlen(needle);
	haystack = ft_strchr(haystack, needle[0]);
	while (*haystack)
	{
		if (!(ft_memcmp(haystack, needle, needle_size)))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
