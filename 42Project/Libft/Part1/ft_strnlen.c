/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 00:10:12 by alex              #+#    #+#             */
/*   Updated: 2020/07/11 00:10:30 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	const unsigned char	*ptr;

	ptr = ft_memchr(s, 0, maxlen);
	return (ptr ? (ptr - s) : maxlen);
}
