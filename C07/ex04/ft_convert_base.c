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

int	is_space(char c);
int	is_operator(char c);
int	ft_strlen(char *base);
int	is_inbase(char c, char *base_from);
int	invalid_base(char *base);

int	ft_atoi_base(char *nbr, char *base_from)
{
	int	nb;
	int	sign;
	int	index;
	int	len_base;

	nb = 0;
	sign = 1;
	index = 0;
	len_base = ft_strlen(base_from);
	while (is_space(nbr[index]))
		index++;
	while (is_operator(nbr[index]))
	{
		if (nbr[index] == '-')
			sign *= -1;
		index++;
	}
	while (is_inbase(nbr[index], base_from) != -1)
	{
		nb = (nb * len_base) + is_inbase(nbr[index], base_from);
		index++;
	}
	return (sign * nb);
}

int	ft_nbrlen(int nbr, char *base)
{
	int	len;
	int	len_base;

	len = 1;
	len_base = ft_strlen(base);
	if (nbr < 0)
		len++;
	while (nbr /= len_base)
		len++;
	len++;
	return (len);
}

void	ft_nbr_base(int nbr, int index_end, char *new_nbr, char *base_to)
{
	int	sign;
	int	index_beg;
	int	len_base;

	sign = 1;
	index_beg = 0;
	len_base = ft_strlen(base_to);
	if (nbr < 0)
	{
		sign = -1;
		new_nbr[index_beg] = '-';
		index_beg++;
	}
	while (nbr && index_end >= index_beg)
	{
		new_nbr[index_end] = base_to[sign * (nbr % len_base)];
		nbr /= len_base;
		index_end--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;
	int	len_tab;
	char	*tab;

	if (invalid_base(base_from) || invalid_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	len_tab = ft_nbrlen(nb, base_to);
	tab = malloc(sizeof(char) * len_tab);
	if (tab == NULL)
		return (NULL);
	ft_nbr_base(nb, len_tab - 2, tab, base_to);
	tab[len_tab - 1] = '\0';
	return (tab);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (ft_convert_base(argv[1], argv[2], argv[3]) == NULL)
			printf("Error on base\n");
		else
			printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
	}
	else
		printf ("Few arguments\n");
	return (0);
}
