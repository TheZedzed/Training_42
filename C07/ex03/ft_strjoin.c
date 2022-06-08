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

int			ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char		*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
}

char		*ft_strcat(char *dest, char *src)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = 0;
	return (dest);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		len;
	int		i;

	i = -1;
	len = 0;
	if (size <= 0)
	{
		if (!(tab = (char *)malloc(1)))
			return (NULL);
		*tab = '\0';
		return (tab);
	}
	while (++i < size)
		len += ft_strlen(strs[i]);
	len += (ft_strlen(sep) * (size - 1));
	if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tab[len] = 0;
	i = 0;
	ft_strcpy(tab, strs[0]);
	while (++i < size)
	{
		ft_strcat(tab, sep);
		ft_strcat(tab, strs[i]);
	}
	return (tab);
}
