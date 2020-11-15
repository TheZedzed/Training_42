/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 02:29:49 by alex              #+#    #+#             */
/*   Updated: 2020/07/01 20:10:06 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"

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
		while ((bytes = read(file, buffer, 4096)))
		{
			write(1, buffer, bytes);
		}
		close(file);
	}
}
