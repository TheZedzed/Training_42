/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:06:51 by azeraoul          #+#    #+#             */
/*   Updated: 2020/03/12 19:34:15 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	unsigned int	i;

	i = 0;
	if (!(*str))
		return (1);
	while (*(str + i))
	{
		if (*(str + i) < 32 || *(str + i) > 126)
			return (0);
		i++;
	}
	return (1);
}
