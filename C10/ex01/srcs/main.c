/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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
	int		i;
	int		fd;

	i = 0;
	if (argc == 1)
		cat_stream(0);
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-"))
			cat_stream(0);
		else
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
				ft_puterror(argv[i], errno);
			else
			{
				cat_stream(fd);
				close(fd);
			}
		}
	}
	return (0);
}
