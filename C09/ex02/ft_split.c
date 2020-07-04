/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 02:22:23 by alex              #+#    #+#             */
/*   Updated: 2020/07/01 19:49:31 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (unsigned char)c)
		str++;
	if (*str == (unsigned char)c)
		return ((char *)str);
	else
		return (NULL);
}

char	*ft_strncpy(char *dest, const char *src, int n)
{
	while (*src && n--)
		*dest++ = *src++;
	if (n > 0)
	{
		while (n--)
			*dest++ = 0;
	}
	return (dest);
}

int	ft_nb_split(const char *str, const char *charset)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && ft_strchr(charset, *str))
			str++;
		while (*str && !ft_strchr(charset, *str))
			str++;
		if (*str)
			words++;
	}
	return (words);
}

void	ft_print_split(char **tab, const char *str, const char *charset)
{
	int	size;
	int	index;

	index = 0;
	while (*str)
	{
		if (!ft_strchr(charset, *str))
		{
			size = 1;
			while (str[size] && !ft_strchr(charset, str[size]))
				size++;
			tab[index] = (char *)malloc((size + 1) * sizeof(char));
			ft_strncpy(tab[index], str, size);
			tab[index++][size] = 0;
			str += size;
		}
		else
			str++;
	}
	tab[index] = 0;
}

char	**ft_split(const char *str, const char *charset)
{
	int	size;
	char	**tab;

	size = ft_nb_split(str, charset);
	if (!(tab = (char **)malloc((size + 1) * sizeof(char *))))
		return (NULL);
	ft_print_split(tab, str, charset);
	return (tab);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	char	**word;

	if (argc == 3)
	{
		word = ft_split(argv[1], argv[2]);
		while (word[i])
			printf("%s\n", word[i++]);
	}
	return (0);
}
