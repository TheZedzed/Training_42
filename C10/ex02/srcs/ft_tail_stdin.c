/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:13:22 by alex              #+#    #+#             */
/*   Updated: 2020/07/06 01:53:11 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_tail_stdin(void)
{
	char	*buffer;
	char	c;
	int	bytes;
	//int	count;

	bytes = 0;
	//count = 0;
	buffer = &c;
	while (read(0, &c, 1) > 0)
	{
		bytes += 2;
	//	ft_realloc(buffer, bytes);
	//	buffer[bytes - 1] = c;
	}
	write(1, buffer, bytes);
	//buffer[bytes] = 0;
/*	while (buffer[--bytes] && count < 11)
	{
		if (buffer[bytes] == '\n')
			count++;
	}
	ft_putstr(&buffer[bytes]);
	free(buffer);*/
}
