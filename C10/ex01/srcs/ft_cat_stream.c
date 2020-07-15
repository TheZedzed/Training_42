/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_stream.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 16:32:14 by alex              #+#    #+#             */
/*   Updated: 2020/07/11 18:25:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	cat_stream(int fd)
{
	/* NOTE: 64KB buffer is optimal for many
	** filesystem files or devices
	*/
	int	rlen;
	int	wlen;
	int	err;
	char 	*cur;
	char 	buf[29 * 1024];

	/* use err = errno for error checking */
	err = 0;
	while (1)
	{
		/* read a chunk of input */
		if ((rlen = read(fd, buf, sizeof(buf))) < 0)
		{
			ft_putstr("cat_stream: read error -- ");
			ft_putstr(strerror(errno));
			break;
		}
		if (rlen == 0)
			break;
		/* write out all data read in chunk -- loop until all data
		** read in this chunk has been output, even if it could _not_ be
		** output in a single write call, advancing the pointer into the
		** buffer [and shortening the remaining length]
		*/
		cur = buf;
		while (rlen > 0)
		{
			if ((wlen = write(1, cur, rlen)) < 0)
			{
				ft_putstr("cat_stream: write error -- ");
				ft_putstr(strerror(errno));
				break;
			}
			rlen -= wlen;
			cur += wlen;
		}
	}
	return (err);
}
