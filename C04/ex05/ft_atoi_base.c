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

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int		is_error(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) < 2)
		return (1);
	while (str[i] && !is_space(str[i]) && str[i] != '+' && str[i] != '-')
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

int		is_inbase(char c, char *base)
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

int		ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	sign;
	int	the_base;

	nb = 0;
	sign = 1;
	if (is_error(base))
		return (0);
	the_base = ft_strlen(base);
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_inbase(*str, base) != -1)
	{
		nb = (nb * the_base) + is_inbase(*str, base);
		str++;
	}
	return (sign * nb);
}
