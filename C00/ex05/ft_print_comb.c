/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:13:02 by azeraoul          #+#    #+#             */
/*   Updated: 2020/03/11 14:43:53 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display(int a, int b, int c)
{
	if (a != 7 || b != 8 || c != 9)
	{
		ft_putchar(a + '0');
		ft_putchar(b + '0');
		ft_putchar(c + '0');
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
	{
		ft_putchar(a + '0');
		ft_putchar(b + '0');
		ft_putchar(c + '0');
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 9)
	{
		j = i + 1;
		while (j <= 9)
		{
			k = j + 1;
			while (k <= 9)
			{
				display(i, j, k);
				k++;
			}
			++j;
		}
		++i;
	}
}
