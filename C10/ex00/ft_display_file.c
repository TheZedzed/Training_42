/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 02:29:49 by alex              #+#    #+#             */
/*   Updated: 2020/05/28 03:41:49 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_lib.h"

void	ft_display_file(const char *filename)
{
	char	buffer[4096];
	int	file;
	int	bytes;

	file = open(filename, O_RDONLY);
	if (file == -1)
		ft_putstr("Cannot read file.\n");
	else
	{
		while ((bytes = read(file, &buffer, 4095)))
		{
			write(1, &buffer, bytes);
		}
		close(file);
	}	
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr("File name missing.\n");
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
		ft_display_file(argv[1]);
	return (0);
}
