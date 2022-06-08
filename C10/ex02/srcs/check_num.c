/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 13:03:34 by alex              #+#    #+#             */
/*   Updated: 2020/07/05 15:41:17 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

/*
** Checks if the string is an int 
*/
int	check_num(char *str)
{
	int	res;

	res = 0;
	if (!str)
		res = -1;
	else
	{
		while (*str >= 48 && *str <= 57)
		{
			res = (res * 10) + (*str - '0');
			str++;
		}
		if (*str)
			res = -1;			
	}
	return (res);
}
