/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 02:17:47 by alex              #+#    #+#             */
/*   Updated: 2020/05/06 00:31:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		is_error(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) < 2)
		return (1);
	while (str[i] && str[i] != '+' && str[i] != '-')
	{
		j = i + 1;
		while (str[j] && str[j] != str[i])
			j++;
		if (str[j] != '\0')
			return (1);
		i++;
	}
	if (str[i] != '\0')
		return (1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	sign;
	int	the_base;

	sign = 1;
	if (!(is_error(base)))
	{
		the_base = ft_strlen(base);
		if (nbr < 0)
		{
			sign = -1;
			ft_putchar('-');
		}
		if (nbr >= the_base || nbr <= -the_base)
			ft_putnbr_base(sign * (nbr / the_base), base);
		ft_putchar(base[sign * (nbr % the_base)]);
	}
}
