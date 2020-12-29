/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:30:21 by alex              #+#    #+#             */
/*   Updated: 2020/06/25 23:46:39 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*res;

	res = NULL;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			res = ptr;
		ptr++;
	}
	if ((unsigned char)c == '\0')
		return (ptr);
	return (res);
}
