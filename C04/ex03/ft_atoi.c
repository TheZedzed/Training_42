/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 19:36:00 by alex              #+#    #+#             */
/*   Updated: 2020/04/29 02:14:25 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return (c == 32 || (c <= 13 && c >= 9));
}

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;
	int	index;

	nb = 0;
	sign = 1;
	index = 0;
	while (is_space(str[index]))
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		nb = (nb * 10) + (str[index] -'0');
		index++;
	}
	return (sign * nb);
}
