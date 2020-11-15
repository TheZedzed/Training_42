/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 00:05:09 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 00:05:19 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

/*
** Error: use of option -c
*/
void	opt_error(char *argv)
{
	if (!argv)
	{
		ft_putstr("ft_tail: option requires an argument -- \'c\'\n");
		ft_putstr("Try \'ft_tail --help\' for more information.\n");
	}
	else
	{
		ft_putstr("ft_tail: invalid number of bytes: \'");
		ft_putstr(argv);
		ft_putstr("\'\n");
	}
}
