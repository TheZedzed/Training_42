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
		ft_putchar(tab[i] + '0');
	if (tab[0] != 7)
		write(1, ", ",2);
}

void	ft_print_comb(void)
{
	int	tab[3] = {0};

	while (tab[0] < 10)
	{
		tab[1] = tab[0] + 1;
		while (tab[1] < 10)
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
