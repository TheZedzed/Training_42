/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:22:38 by alex              #+#    #+#             */
/*   Updated: 2020/07/11 11:31:13 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*ret;
	char	*ptr;

	if (!(ptr = (char *) malloc(sizeof(*ptr) * (ft_strlen(s) + 1))))
		return (NULL);
	ret = ptr;
	while (*s)
		*ptr++ = f(*s++);
	*ptr = 0;
	return (ret);
}
