/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:41:05 by alex              #+#    #+#             */
/*   Updated: 2020/07/11 11:08:52 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	ft_striter(char *s, void (*f)(char *))
{
	while (*s)
		f(s++);
}
/*int	main(void)
{
	char	tab[10] = "salut fdp";

	printf("%p\n", tab);
	ft_striter(tab, ft_putstr);
	printf("%p\n", tab);
	return (0);
}*/
