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

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] && c != charset[i])
		i++;
	if (charset[i] == '\0')
		return (0);
	return (1);
}

int	ft_word_len(int *index, char *str, char *charset)
{
	int	begin;
	int	end;

	while (str[*index] && is_separator(str[*index], charset))
		(*index)++;
	begin = *index;
	end = begin;
	while (str[end] && !is_separator(str[end], charset))
		end++;
	return (end - begin);
}

int	ft_nb_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		while (str[i] && !is_separator(str[i], charset))
			i++;
		words++;
	}
	return (words);
}

char	*ft_new_strncpy(int *index, char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[*index] && *index < n)
	{
		dest[i] = src[*index];
		i++;
		(*index)++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int	i;
	int	nb_words;
	int	word_len;
	int	index;
	char	**tab;

	i = 0;
	index = 0;
	nb_words = ft_nb_words(str, charset);
	tab = (char **)malloc(sizeof(char *) * nb_words + 1);
	if (tab == NULL)
		return (NULL);
	while (i < nb_words)
	{
		word_len = ft_word_len(&index, str, charset);
		tab[i] = (char *)malloc(sizeof(char) * word_len + 1);
		ft_new_strncpy(&index, tab[i], str, (index + word_len));
		i++;
	}
	tab[i] = 0;
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
