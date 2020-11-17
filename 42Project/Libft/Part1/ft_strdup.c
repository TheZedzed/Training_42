/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 11:20:39 by alex              #+#    #+#             */
/*   Updated: 2020/06/22 11:32:45 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strdup(const char *s)
{
	char		*new_s;
	size_t		size;

	size = ft_strlen(s) + 1;
	if (!(new_s = (char *) malloc(size)))
		return (NULL);
	ft_memcpy(new_s, s, size);
	return (new_s);
}
