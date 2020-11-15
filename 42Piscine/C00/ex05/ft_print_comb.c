/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:13:02 by azeraoul          #+#    #+#             */
/*   Updated: 2020/08/18 01:16:59 by alex             ###   ########.fr       */
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
		ft_putchar(tab[i] + 48);
	if (tab[0] != (10 - size))
		write(1, ", ", 2);
}

void	init_tab(int tab[3])
{
	int	i;

	i = -1;
	while (++i < 3)
		tab[i] = 0;
}

void	ft_print_comb(void)
{
	int	tab[3];

	init_tab(tab);
	while (tab[0] < 8)
	{
		tab[1] = tab[0] + 1;
		while (tab[1] < 9)
		{
			tab[2] = tab[1] + 1;
			while (tab[2] < 10)
			{
				display(tab, 3);
				tab[2]++;
			}
			tab[1]++;
		}
		tab[0]++;
	}
}
