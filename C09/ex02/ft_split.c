/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 02:22:23 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 21:02:20 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c, char *charset)
{
	while (*charset && c != *charset)
		charset++;
	if (*charset == '\0')
		return (0);
	return (1);
}

int		ft_nb_words(char *str, char *charset)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (!is_separator(*str, charset))
		{
			words++;
			while (*str && !is_separator(*str, charset))
				str++;
		}
		else
			str++;
	}
	return (words);
}

char		*word(char *str, char *charset)
{
	char 	*res;
	int		len;

	len = 0;
	while (str[len] && !is_separator(str[len], charset))
		len++;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = 0;
	len = 0;
	while (str[len] && !is_separator(str[len], charset))
	{
		res[len] = str[len];
		len++;
	}
	return (res);
}

char		**ft_split(char *str, char *charset)
{
	char	**tab;
	int		nb_words;
	int		i;

	i = 0;
	nb_words = ft_nb_words(str, charset);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	tab[nb_words] = 0;
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		if (*str && !is_separator(*str, charset))
		{
			tab[i] = word(str, charset);
			while (*str && !is_separator(*str, charset))
				str++;
			i++;
		}
	}
	return (tab);
}
