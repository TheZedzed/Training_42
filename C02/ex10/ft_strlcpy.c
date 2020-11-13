/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 03:07:20 by alex              #+#    #+#             */
/*   Updated: 2020/04/16 21:07:34 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int		ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while(str[count])
		count++;
	return (count);
}
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(src);
	if (size)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
