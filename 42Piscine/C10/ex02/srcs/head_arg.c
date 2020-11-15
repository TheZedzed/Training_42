/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 00:05:56 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 00:06:07 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

/*
** Check for filename header
*/
void	head_arg(char *filename, int index, char *argc)
{
	if (check_num(argc) > 1)
	{
		if (index != 1)
			ft_putstr("\n");
		if (!ft_strncmp(filename, "-", 1))
			ft_putstr("==> standard input <==\n");
		else
		{
			ft_putstr("==> ");
			ft_putstr(filename);
			ft_putstr(" <==\n");
		}
	}
}
