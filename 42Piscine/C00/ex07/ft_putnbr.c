/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:45:47 by azeraoul          #+#    #+#             */
/*   Updated: 2020/04/18 19:30:56 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	sign;

	sign = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	if (nb >= 10 || nb <= -10)
		ft_putnbr((nb / 10) * sign);
	ft_putchar((nb % 10) * sign + '0');
}
