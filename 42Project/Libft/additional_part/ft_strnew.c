/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 18:00:58 by alex              #+#    #+#             */
/*   Updated: 2020/07/10 18:14:07 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *) malloc(sizeof(*str) * (size + 1));
		return (NULL);
	return ((char *)ft_memset(str, 0, size + 1));
}
