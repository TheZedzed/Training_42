/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 22:11:09 by alex              #+#    #+#             */
/*   Updated: 2020/04/18 20:24:26 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				ft_putstr_non_printable(char *str)
{
	unsigned char	*ptr;
	const char		*hex;

	ptr = (unsigned char *)str;
	hex = "0123456789abcdef";
	while (*ptr)
	{
		if (*ptr < 32 || *ptr > 126)
		{
			write(1, "\\", 1);
			write(1, &hex[(*ptr / 16)], 1);
			write(1, &hex[(*ptr % 16)], 1);
		}
		else
			write(1, ptr, 1);
		ptr++;
	}
}
