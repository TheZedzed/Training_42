/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 00:35:03 by alex              #+#    #+#             */
/*   Updated: 2020/05/07 16:16:12 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	is_error(char *str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen(str) < 2)
		return (1);
	while (str[i] && str[i] != '-' && str[i] != '+' && !is_space(str[i]))
	{
		j = i + 1;
		while (str[j] && str[j] != '-' && str[j] != '+'
			&& str[j] != str[i])
			j++;
		if (str[j] != '\0')
			return (1);
		i++;
	}
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}

int	is_inbase(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (c == base[index])
			return (index);
		index++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	sign;
	int	index;
	int	the_base;

	nb = 0;
	sign = 1;
	index = 0;
	if (is_error(base))
		return (0);
	the_base = ft_strlen(base);
	while (is_space(str[index]))
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (is_inbase(str[index], base) != -1)
	{
		nb = (nb * the_base) + is_inbase(str[index], base);
		index++;
	}
	return (sign * nb);
}
