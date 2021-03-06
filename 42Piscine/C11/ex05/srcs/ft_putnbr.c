/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:11:00 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 19:11:01 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	ft_putnbr(int nb)
{
	int	sign;

	sign = 1;
	if (nb < 0)
	{
		sign = -1;
		ft_putchar('-');
	}
	if (nb >= 10 || nb <= -10)
		ft_putnbr(sign * (nb / 10));
	ft_putchar(sign * (nb % 10) + '0');
}
