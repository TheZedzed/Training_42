/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:14:58 by azeraoul          #+#    #+#             */
/*   Updated: 2020/03/11 11:44:49 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_alphabet(void)
{
	char	c;

	c = 96;
	while (++c <= 122)
		write(1, &c, 1);
}
