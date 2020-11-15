/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 16:30:41 by alex              #+#    #+#             */
/*   Updated: 2020/07/11 16:31:01 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_puterror(const char *file, int error)
{
	ft_putstr("ft_cat: ");
	ft_putstr(file);
	ft_putstr(": "); 
	ft_putstr(strerror(error));
	ft_putstr("\n");
}
