/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:02:14 by alex              #+#    #+#             */
/*   Updated: 2020/04/28 19:01:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	len;

	dest_len = 0;
	src_len = 0;
	len = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size < dest_len)
		len = src_len + size;
	else
		len = src_len + dest_len;
	src_len = 0;
	while (src[src_len] && (dest_len + src_len) < size - 1)
	{
		dest[dest_len + src_len] = src[src_len];
		src_len++;
	}
	dest[dest_len + src_len] = '\0';
	return (len);
}
