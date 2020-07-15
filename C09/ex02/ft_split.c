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

/*
** si ta du mal:
** if(!condition) <=> if (!nombre (soit 0 / NULL))
** if(condition)  <=> if (nombre > 0)
*/
int	ft_nb_split(const char *str, const char *charset)
{
	int	words;

	words = 0;
	/* tant qui a un caratere dans str (str finit par 0 ou '\0') */
	while (*str)
	{
		/* tant qu'il y a un caractere dans str et qu'il est dans charset */
		/* strchr retourne une adresse ou NULL */
		while (*str && ft_strchr(charset, *str))
			str++;
		/* tant qu'il y a un caractere dans str et qu'il n'est pas dans charset */
		while (*str && !ft_strchr(charset, *str))
			str++;
		/* si str n'est pas fermé --> *str != 0 ou '\0' on recense un mot */
		if (*str)
			words++;
	}
	return (words);
}

/* char **tab dans la mémoire:
**
** 	tab (adresse d'un tableau de pointeur sur char *)
** 	 |
** 	tab[i] (adresse d'un tableau de char (char *))
** 	tab[i + 1]
** 	..
**	0
*/

/*
** Du coup pour acceder a un tableau:
**	tab[index] ou *(tab + index)
*/
void	ft_print_split(char **tab, const char *str, const char *charset)
{
	int	size;
	int	index;

	index = 0;
	while (*str)
	{
		/* si *str est pas dans charset (strchr retourne NULL)*/
		if (!ft_strchr(charset, *str))
		{
			/* size = 1 car *str est pas dans charset */
			/* size++ tant qu'il n'y a pas *str dans charset */
			size = 1;
			while (str[size] && !ft_strchr(charset, str[size]))
				size++;
			/* *str est dans charset donc arret */
			/* on allou de la memoire pour le mot de taille size */
			/* a tableau_de_pointeur[index] (tab[index])*/
			/* on copy ce mot dans le taleau_de_poiteur[index] */
			tab[index] = (char *)malloc((size + 1) * sizeof(char));
			ft_strncpy(tab[index], str, size);
			tab[index++][size] = 0; //on ferme le tableau de char
			/* on incremente str du mot qu'on vient de copier */
			/* pour avancer dans str */
			str += size;
		}
		/* si *str est dans charset */
		/* on avance dans str */
		else
			str++;
	}
	/* fermer le tableau_de_pointeur */
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
