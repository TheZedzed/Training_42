/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:38:27 by alex              #+#    #+#             */
/*   Updated: 2020/07/04 23:14:43 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	main(int argc, char **argv)
{
	int	file;
	int	i;

	i = 0;
	if (argc == 1)
		ft_tail_stdin();
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-c"))
		{
			if (!argv[i + 1])
			{
				ft_putstr(basename(argv[0]));
				ft_putstr(": option requires an argument -- \'c\'\n");
				ft_putstr("Try 'tail --help' for more information.\n");
			}
			else if (!ft_str_isdigit(argv[i + 1]))
			{
				ft_putstr(basename(argv[0]));
				ft_putstr(": invalid number of bytes: ");
				ft_putstr("\'");
				ft_putstr(argv[i + 1]);
				ft_putstr("\'\n");
			}
		}
	}
	return (0);
}
