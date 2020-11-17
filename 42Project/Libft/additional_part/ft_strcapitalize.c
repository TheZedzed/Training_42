/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:18:16 by alex              #+#    #+#             */
/*   Updated: 2020/07/09 19:33:17 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strcapitalize(char *s)
{
	char	*ptr;

	ptr = s;
	ft_str_lowcase(s);
	if (ft_islower(*s))
		*s -= 32;
	while (*s++)
	{
		while (*s && !ft_is_alpha(*s))
			s++;
		if (!(ft_isdigit(*--s) || ft_isalpha(*s)))
			*++s -= 32;
		else
			s++;
	}
	return (ptr);
}
