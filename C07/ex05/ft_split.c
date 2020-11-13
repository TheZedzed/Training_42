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

#include <stdlib.h>
#include <stdio.h>

int		is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] && c != charset[i])
		i++;
	if (charset[i] == '\0')
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
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[i] = 0;
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
	int		i;
	int		nb_words;
	char	**tab;

	i = 0;
	nb_words = ft_nb_words(str, charset);
	tab = (char **)malloc(sizeof(char *) * nb_words + 1);
	if (tab == NULL)
		return (NULL);
	tab[i] = 0;
	while (*str)
	{
		while (*str && is_separator(*str))
			str++;
		if (*str && !is_separator(*str))
		{
			tab[i] = word(str, charset);
			while (*str && !is_separator(*str, charset))
				str++;
			i++;
		}
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	int	i;
	char	**word;

	if (argc == 3)
	{
		word = ft_split(argv[1], argv[2]);
		for (i = 0; i < 5; i++)
			printf("%s ", word[i]);
	}
	return (0);
}
