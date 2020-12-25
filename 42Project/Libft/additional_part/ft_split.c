/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:41:55 by alex              #+#    #+#             */
/*   Updated: 2020/05/20 18:36:06 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		is_separator(char c, char sep)
{
	return (c == sep);
}

int		ft_nb_words(char *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (!is_separator(*str, c))
		{
			words++;
			while (*str && !is_separator(*str, c))
				str++;
		}
		else
			str++;
	}
	return (words);
}

char		*word(char *str, char c)
{
	char 	*res;
	int		len;

	len = 0;
	while (str[len] && !is_separator(str[len], c))
		len++;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = 0;
	len = 0;
	while (str[len] && !is_separator(str[len], c))
	{
		res[len] = str[len];
		len++;
	}
	return (res);
}

char		**ft_split(const char *s, char c)
{
	char	**tab;
	int		nb_words;
	int		i;

	i = 0;
	nb_words = ft_nb_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	tab[nb_words] = 0;
	while (*s)
	{
		while (*s && is_separator(*s, c))
			s++;
		if (*s && !is_separator(*s, c))
		{
			tab[i] = word(s, c);
			while (*s && !is_separator(*s, c))
				s++;
			i++;
		}
	}
	return (tab);
}
