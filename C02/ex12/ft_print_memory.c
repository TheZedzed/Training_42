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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	separator(unsigned int index)
{
	unsigned int	space;

	space = (16 - (index % 16));
	if (space == 16)
		ft_putchar(' ');
	while (space < 16 && space--)
		ft_putchar(' ');
}

void	ft_conv_hexa(unsigned long nb)
{
	const char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		ft_conv_hexa(nb / 16);
	ft_putchar(hex[nb % 16]);
}

void	ft_print_addr(unsigned long addr)
{
	int	addr_size;
	unsigned long	temp;

	addr_size = 1; 
	temp = addr;
	while ((temp = temp /16))
		addr_size++;
	addr_size = 16 - addr_size;
	while (addr_size--)
		ft_putchar('0');
	ft_conv_hexa(addr);
	ft_putchar(':');
}

void	ft_print_hexa(char c, unsigned int index)
{
	const char	*hex;

	hex = "0123456789abcdef";
	if (!(index % 2))
		ft_putchar(' ');
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	index;
	unsigned int	begin;
	char	c;

	begin = 0;
	while (size > 0 && begin < size)
	{
		index = begin;
		ft_print_addr((unsigned long)(addr + index));
		while (*(char *)(addr + index) && index < begin + 16)
		{
			ft_print_hexa(*(char *)(addr + index), index);
			index++;
		}
		separator(index);
		index = begin;
		while (*(char *)(addr + index) && index < begin + 16)
		{
			c = *(char *)(addr + index++);
			if (c > 31 && c < 127)
				ft_putchar(c);
			else
				ft_putchar('.');
		}
		ft_putchar('\n');
		begin += 16;
	}
	return (addr);
}
