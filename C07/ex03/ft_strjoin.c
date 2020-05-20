/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 02:14:52 by alex              #+#    #+#             */
/*   Updated: 2020/05/08 19:38:51 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strslen(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		j = 0;
		while (sep[j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

char	*ft_strscpy(char *dest, char *src, int *index)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[*index] = src[i];
		(*index)++;
		i++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	char	*tab;
	int	index;
	int	words_len;

	i = 0;
	index = 0;
	if (!size)
	{
		tab = "\0";
		return (tab);
	}
	words_len = ft_strslen(size, strs, sep);
	tab = (char *)malloc(sizeof(char) * words_len);
	if (tab == NULL)
		return (NULL);
	while (i < size)
	{
		ft_strscpy(tab, strs[i], &index);
		if (i < size - 1)
			ft_strscpy(tab, sep, &index);
		i++;
	}
	tab[index] = '\0';
	return (tab);
}
