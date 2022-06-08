/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:27:47 by alex              #+#    #+#             */
/*   Updated: 2020/05/07 22:37:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		main(int argc, char **argv)
{
	int	index;

	index = argc;
	while (--index > 0)
	{
		write(1, argv[index], ft_strlen(argv[index]));
		write(1, "\n", 1);
	}
	return (0);
}
