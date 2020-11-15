/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:40:25 by alex              #+#    #+#             */
/*   Updated: 2020/05/17 23:40:34 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int			ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int			is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int			error(char *str)
{
	int		i;
	int		j;

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

int			is_inbase(char c, char *base)
{
	int		index;

	index = 0;
	while (base[index])
	{
		if (c == base[index])
			return (index);
		index++;
	}
	return (-1);
}

int			ft_atoi_base(char *str, char *base)
{
	int		nb;
	int		sign;
	int		the_base;

	nb = 0;
	sign = 1;
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

int			nbrlen(int nbr, int base_len)
{
	int		len;

	len = 1;
	if (nbr < 0)
		len++;
	while ((nbr /= base_len))
		len++;
	return (len);
}

char		*itoa_base(int nbr, char *base)
{
	char	*num;
	int		len;
	int		sign;
	int		len_base;

	sign = 1;
	len_base = ft_strlen(base);
	len = nbrlen(nbr, len_base);
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	num[len] = 0;
	if (nbr < 0)
	{
		sign = -1;
		num[0] = '-';
	}
	while (--len >= 0)
	{
		if (num[len] == '-')
			break ;
		num[len] = base[sign * (nbr % len_base)];
		nbr /= len_base;
	}
	return (num);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;

	if (!nbr || !base_from || !base_to || error(base_from) || error(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	return (itoa_base(nb, base_to));
}

int	main(int argc, char **argv)
{
	char	*res;

	(void)argc;
	res = ft_convert_base(argv[1], argv[2], argv[3]);
	if (res)
		printf("%s\n", res);
	return (0);
}
