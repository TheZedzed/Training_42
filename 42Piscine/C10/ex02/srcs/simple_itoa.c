/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 00:00:45 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 00:00:57 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

/*
** Converts an int to a string
*/
char	*simple_itoa(int nb)
{
	int	len;
	int	temp;
	char	*tab;

	len = 1;
	temp = nb;
	while ((temp /= 10))
		len++;
	if (!(tab = (char *) malloc(sizeof(tab) * (len + 1))))
		return (NULL);
	tab[len] = 0;
	while (--len >= 0)
	{
		tab[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (tab);
}
