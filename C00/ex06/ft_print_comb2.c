/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 23:23:14 by alex              #+#    #+#             */
/*   Updated: 2020/08/18 00:59:28 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display(int tab[], int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		ft_putchar(tab[i] / 10 + '0');
		ft_putchar(tab[i] % 10 + '0');
		if (i < size - 1)
			ft_putchar(' ');
	}
	if (tab[0] != 98)
		write(1, ", ", 2);
}

void	init_tab(int tab[2])
{
	int	i;

	i = -1;
	while (++i < 2)
		tab[i] = 0;
}

void	ft_print_comb2(void)
{
	int	tab[2];

	init_tab(tab);
	while (tab[0] < 99)
	{
		tab[1] =  tab[0] + 1;
		while (tab[1] < 100)
		{
			display(tab, 2);
			tab[1]++;
		}
		tab[0]++;
	}
}
