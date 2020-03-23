/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:45:49 by azeraoul          #+#    #+#             */
/*   Updated: 2020/03/12 18:46:31 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	unsigned int	i;

	i = 0;
	if (!(*str))
		return (1);
	while (*(str + i))
	{
		if (!(*(str + i) >= 'a' && *(str + i) <= 'z'))
			return (0);
		i++;
	}
	return (1);
}
