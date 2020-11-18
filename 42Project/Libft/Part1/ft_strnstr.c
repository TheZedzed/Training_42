/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 12:26:56 by alex              #+#    #+#             */
/*   Updated: 2020/06/27 15:44:35 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	res = (char *)big;
	if (!little || !len)
		return (res);
	while (res[i])
	{
		j = 0;
		while (j < len && res[i + j] == little[j])
		{
			if (j + 1 == len)
				return (&res[i]);
			j++;
		}
		i++;
	}
	return (0);
}
