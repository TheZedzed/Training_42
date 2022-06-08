/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail_stream.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:57:51 by alex              #+#    #+#             */
/*   Updated: 2020/07/14 23:58:02 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

/*
** Tail output
** For stdin:
** read fd is slow (1 char at time)
** limited input_size <= 1000
*/
int	tail_stream(int fd, int num)
{
	char	buff[29 * 1024];
	char	*tab;
	int	cur;
	int	rlen;
	char	c;

	if (fd == 0)
	{
		rlen = 0;
		if (!(tab = (char *) malloc(sizeof(tab) * 1000)))
			return (0);
		while (read(fd, &c, 1) > 0)
			tab[rlen++] = c;
		tab[rlen] = 0;
		write(1, &tab[rlen - num], num);
		free(tab);
		return (0);
	}
	while (1)
	{
		rlen = read(fd, buff, 29696);
		if (rlen > 0)
			cur = rlen - num;
		if (rlen == 0)
		{
			write(1, buff + cur, num);
			break;
		}
	}
	return (0);
}
