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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		ft_putchar(str[index]);
		index++;
	}
}

int	main(int argc, char **argv)
{
	int	index;

	index = argc - 1;
	while (index > 0)
	{
		ft_putstr(argv[index]);
		ft_putchar('\n');
		index--;
	}
	return (0);
}
