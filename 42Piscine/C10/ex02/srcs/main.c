/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:38:27 by alex              #+#    #+#             */
/*   Updated: 2020/07/13 20:41:33 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	main(int argc, char **argv)
{
	int	fd;
	int	nb_bytes;
	int	i;
	char	**av;

	i = 0;
	if ((nb_bytes = check_option(argc, argv)) <= 0)
		return (0);
	if (!(av = set_command(argv, nb_file, simple_itoa)))
		return (0);
	while (av[++i])
	{
		if (!ft_strncmp(av[i], "-", 1))
		{
			head_arg(av[i], i, av[0]);
			tail_stream(0, nb_bytes);
		}
		else
		{
			if ((fd = open(av[i], O_RDONLY)) < 0)
				put_error(av[i], errno);
			else
			{
				head_arg(av[i], i, av[0]);
				tail_stream(fd, nb_bytes);
				close(fd);
			}
		}
	}
	free(av[0]);
	free(av);
	return (0);
}
