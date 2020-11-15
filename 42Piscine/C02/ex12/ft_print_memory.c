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

void				convert_to_hexa(unsigned long addr)
{
	const char		*hex;

	hex = "0123456789abcdef";
	if (addr >= 16)
		convert_to_hexa(addr / 16);
	write(1, &hex[addr % 16], 1);
}

void				ft_print_addr(unsigned long addr)
{
	unsigned long	temp;
	unsigned long	addr_size;

	temp = addr;
	addr_size = 1;
	while ((temp = temp / 16))
		addr_size++;
	addr_size = 16 - addr_size;
	while (addr_size--)
		write(1, "0", 1);
	convert_to_hexa(addr);
}

void				print_hexa(unsigned	char *addr, unsigned int index, unsigned int limit)
{
	unsigned int	i;
	const char		*hex;

	i = 0;
	hex = "0123456789abcdef";
	if ((index + i) < limit)
	{
		while (i < 16 && (index + i) < limit)
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
}

void				print_char(unsigned char *str, unsigned int index, unsigned int limit)
{
	unsigned int	i;

	i = 0;
	if ((index + i) < limit)
	{
		while (i < 16 && ((index + i) < limit))
		{
			if (str[i] < 32 || str[i] > 126)
				write(1, ".", 1);
			else
				write(1, &str[i], 1);
			i++;
		}
	}
}

void				*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*content;

	content = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ft_print_addr((unsigned long)(addr + i));
		write(1, ": ", 2);
		print_hexa(&content[i], i, size);
		print_char(&content[i], i, size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
