/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 22:11:09 by alex              #+#    #+#             */
/*   Updated: 2020/04/18 20:24:26 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hexa(int c)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c >= 16)
		ft_print_hexa(c / 16);
	ft_putchar(hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 0 && str[i] < 32) || str[i] == 127)
		{
			ft_putchar('\\');
			if (str[i] < 10)
				ft_putchar('0');
			ft_print_hexa(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
