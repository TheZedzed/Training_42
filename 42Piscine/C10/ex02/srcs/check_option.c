/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 00:03:59 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 00:04:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

/*
** Checks the valid use of '-c' option
*/
int	check_option(int ac, char **av)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (++i < ac)
	{
		if (!ft_strncmp(av[i], "-c", 2))
		{
			if (ft_strlen(av[i]) > 2)
			{
				count = check_num(*(av + i) + 2);
				if (count < 0)
				{
					opt_error(*(av + i) + 2);
					count = -1;
					break;
				}
			}
			else
			{
				count = check_num(av[i + 1]);
				if (count < 0)
				{
					opt_error(av[i + 1]);
					count = -1;
					break;
				}
			}
		}
	}
	return (count);
}
