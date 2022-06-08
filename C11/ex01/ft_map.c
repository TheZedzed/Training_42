/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:03:12 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 16:05:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_map(int *tab, int length, int(*f)(int))
{
	while (length--)
		*tab = (*f)(*tab++);
}