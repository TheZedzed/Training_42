/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:36:48 by alex              #+#    #+#             */
/*   Updated: 2020/07/09 12:22:25 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

size_t		nbrlen(int nbr)
{
	size_t	len;

	len = 1;
	if (nbr < 0)
		len++;
	while ((nbr /= 10))
		len++;
	return (len);
}

char		*itoa(int n)
{
	char	*num;
	size_t	len;
	int		sign;

	sign = 1;
	len = nbrlen(n);
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	num[len] = 0;
	if (n < 0)
	{
		sign = -1;
		num[0] = '-';
	}
	while (--len >= 0)
	{
		if (num[len] == '-')
			break ;
		num[len] = sign * (n % 10) + 48;
		n /= 10;
	}
	return (num);
}
