/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 02:29:49 by alex              #+#    #+#             */
/*   Updated: 2020/07/04 02:06:50 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cat.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_cat(const char *filename)
{
	char	buffer[29696];
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
	int	size;
	//char	*prog_name;
	//char	*arg_name;
	char	word[29696];
	char	c;

	if (!strcmp(argv[1], "-") || argc == 1)
	{
		while (read(0, &c, 1) > 0)
		{
			write(1, &c, 1);
			size = 0;
			word[size++] = c;
		}
		word[size] = 0;
		write(1, word, size);
	}
/*	while (argv[++i])
	
	if (!argv[i])
	{
		arg_name = basename argv[i];
		ft_putstr(prog_name);
		strerror(errno);
	}
	if (argc < 2)
		ft_putstr("File name missing.\n");
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
		ft_display_file(argv[1]);*/
	return (0);
}
