/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 00:06:52 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 00:07:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

/*
** Error: open filename
*/
void	put_error(char *filename, int error)
{
	ft_putstr("ft_tail: cannot open \'");
	ft_putstr(filename);
	ft_putstr("\' for reading: ");
	ft_putstr(strerror(error));
	ft_putstr("\n");
}
