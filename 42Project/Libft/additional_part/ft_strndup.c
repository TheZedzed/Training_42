/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 11:28:11 by alex              #+#    #+#             */
/*   Updated: 2020/06/22 11:44:40 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	size;
	char	*new_s;

	size = ft_strnlen(s, n);
	if(!(new_s = (char *)malloc(size + 1)))
		return (NULL);
	new_s[size] = 0;
	return (ft_memcpy(new_s, s, size));
}
