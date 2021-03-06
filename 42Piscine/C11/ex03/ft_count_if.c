/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:13:47 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 16:28:37 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char *))
{
	int	count;

	count = 0;
	while (length--)
	{
		if ((*f)(*tab++))
			count++;
	}
	return (count);
}
