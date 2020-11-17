/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:39:22 by alex              #+#    #+#             */
/*   Updated: 2020/06/22 23:31:27 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	else
		return (NULL);
}
