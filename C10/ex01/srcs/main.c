/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 02:29:49 by alex              #+#    #+#             */
/*   Updated: 2020/07/04 18:05:45 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	main(int argc, char **argv)
{
	int	i;
	int	file;

	i = 0;
	if (argc == 1)
		ft_cat_stdin();
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-"))
			ft_cat_stdin();
		else
		{
			file = open(argv[i], O_RDONLY);
			if (file == -1)
			{
				ft_putstr(basename(argv[0]));
				ft_putstr(": ");
				ft_putstr(argv[i]);
				ft_putstr(": ");
				ft_putstr(strerror(errno));
				ft_putstr("\n");
			}
			else
				ft_cat_stdout(file);
		}
	}
	return (0);
}
