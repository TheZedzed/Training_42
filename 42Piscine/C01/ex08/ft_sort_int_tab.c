/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 01:55:25 by azeraoul          #+#    #+#             */
/*   Updated: 2020/03/12 03:42:11 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i + 1 < size)
	{
		if (*(tab + i) > *(tab + i + 1))
		{
			temp = *(tab + i);
			*(tab + i) = *(tab + i + 1);
			*(tab + i + 1) = temp;
			i = 0;
		}
		else
			i++;
	}
}
