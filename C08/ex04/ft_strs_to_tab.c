/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 03:32:32 by alex              #+#    #+#             */
/*   Updated: 2020/05/21 04:23:12 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_strs_to_tab.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	char	*copy;

	copy = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (copy == NULL)
		return (NULL);
	ft_strcpy(copy, str);
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int		i;
	t_stock_str	*tab;

	i = 0;
	tab = malloc(sizeof(*tab) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	while (i < ac)
	{
		(tab + i)->size = ft_strlen(av[i]);
		(tab + i)->str = av[i];
		(tab + i)->copy = ft_strdup(av[i]);
		i++;
	}
	(tab + i)->size = 0;
	(tab + i)->str = NULL;
	(tab + i)->copy = NULL;
	return (tab);
}

int	main(int argc, char **argv)
{
	int	i;
	struct s_stock_str	*tab;

	tab = ft_strs_to_tab(argc, argv);
	i = 0;
	while (i < argc)
	{
		printf("%d %s %s\n", tab[i].size, tab[i].str, tab[i].copy);
		i++;
	}
	return (0);
}
