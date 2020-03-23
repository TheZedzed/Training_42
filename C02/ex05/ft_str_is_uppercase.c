/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:55:50 by azeraoul          #+#    #+#             */
/*   Updated: 2020/03/12 18:59:44 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	unsigned int	i;

	i = 0;
	if (!(*(str + i)))
		return (1);
	while (*(str + i))
	{
		if (!(*(str + i) >= 'A' && *(str + i) <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}
