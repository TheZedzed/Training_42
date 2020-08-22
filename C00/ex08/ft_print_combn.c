/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:13:02 by azeraoul          #+#    #+#             */
/*   Updated: 2020/08/18 22:03:08 by alex             ###   ########.fr       */
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
	if (tab[0] != 10 - size)
		write(1, ", ",2);
}

void	init_tab(int tab[], int size)
{
	int	j;

	j = -1;
	while (++j < size)
		tab[j] = j;
}

void	ft_print_combn(int n)
{
	int	i;
	int	tab[9] = {0};

	if (n > 0 && n < 10)
	{
		i = -1;
		init_tab(tab, n);
		while (++i >= 0 && i < n)
		{
			if (i == n - 1)
			{
				while (tab[i] < 10)
				{
					display(tab, n);
					tab[i]++;
				}
				if (--i >= 0)
				{
					while (1)
					{
						if (i && tab[i] == 10 - n + i)
							i--;
						else
							break;
					}
					tab[i]++;
				}
				if (tab[0] == 10 - n + 1)
					break;
				while (++i < n)
					tab[i] = tab[i - 1] + 1;
				i -= 2;
			}
		}
	}
}
