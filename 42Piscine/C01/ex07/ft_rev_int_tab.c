/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:19:29 by azeraoul          #+#    #+#             */
/*   Updated: 2020/03/12 03:39:47 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	i = -1;
	while (++i < --size)
	{
		temp = *(tab + i);
		*(tab + i) = *(tab + size);
		*(tab + size) = temp;
	}
}
