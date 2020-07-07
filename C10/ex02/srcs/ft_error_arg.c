/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 12:55:05 by alex              #+#    #+#             */
/*   Updated: 2020/07/05 16:56:18 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_error_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-c"))
		{
			if (!argv[i + 1])
			{
				ft_putstr(basename(argv[0]));
				ft_putstr(": option requires an argument --");
				ft_putstr(" \'c\'\n");
				ft_putstr("Try 'tail --help' for more ");
				ft_putstr("information.\n");
				return (1);
			}
			else if (!ft_str_isdigit(argv[i + 1]))
			{
				ft_putstr(basename(argv[0]));
				ft_putstr(": invalid number of bytes: ");
				ft_putstr("\'");
				ft_putstr(argv[i + 1]);
				ft_putstr("\'\n");
				return (1);
			}
		}
	}
	return (0);
}
