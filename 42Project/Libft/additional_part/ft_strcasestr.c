/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:25:13 by alex              #+#    #+#             */
/*   Updated: 2020/07/09 21:14:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	const char	*p1;
	const char	*p2;

	p1 = haystack;
	p2 = needle;
	if (!*needle)
		return ((char  *)haystack);
	if (!(p1 = ft_strchr(haystack, ft_tolower(needle[0]))))
		p1 = ft_strchr(haystack, ft_toupper(needle[0]));
	while (*p1)
	{
		if (!ft_strcasecmp(p1, needle))
			return ((char *)p1);
		p1++;
	}
	return (NULL);
}
