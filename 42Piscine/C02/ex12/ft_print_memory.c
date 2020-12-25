/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 21:00:01 by alex              #+#    #+#             */
/*   Updated: 2020/04/27 18:13:21 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
# define uint unsigned int
# define ulong unsigned long
# define uchar unsigned char
# define cchar const char

void		convert_addr(cchar *hex, ulong addr)
{
	if (addr >= 16)
		convert_addr(hex, addr / 16);
	write(1, &hex[addr % 16], 1);
}

void		print_addr(cchar *hex, ulong addr)
{
	ulong	temp;
	ulong	addr_size;

	temp = addr;
	addr_size = 1;
	while ((temp = temp / 16))
		addr_size++;
	addr_size = 16 - addr_size;
	while (addr_size--)
		write(1, "0", 1);
	convert_addr(hex, addr);
}

void		print_hexa(cchar *hex, uchar *addr, uint index, uint limit)
{
	uint	i;

	i = 0;
	while (((index + i) < limit) && i < 16)
	{
		write(1, &hex[addr[i] / 16], 1);
		write(1, &hex[addr[i] % 16], 1);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void		print_char(uchar *str, uint index, uint limit)
{
	uint	i;

	i = 0;
	while (((index + i) < limit) && i < 16)
	{
		if (str[i] < 32 || str[i] > 126)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void		*ft_print_memory(void *addr, uint size)
{
	cchar	*hex;
	uint	i;
	uchar	*content;

	hex = "0123456789abcdef";
	content = (uchar *)addr;
	i = 0;
	while (i < size)
	{
		print_addr(hex, (ulong)(addr + i));
		write(1, ": ", 2);
		print_hexa(hex, &content[i], i, size);
		print_char(&content[i], i, size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
