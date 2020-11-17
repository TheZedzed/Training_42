/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:36:48 by alex              #+#    #+#             */
/*   Updated: 2020/07/09 12:22:25 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	ft_reverse(char *s, size_t len)
{
	int	start;
	int	end;
	char	temp;

	start = -1;
	end = len;
	while (++start < --end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
	}
}

char	*ft_itoa_base(int nb, int base)
{
	size_t	temp;
	int	index;
	char	*ret;

	index = 0;
	temp = ABS((long) nb);
	if(!(ret = (char *) malloc(sizeof(*ret) * 12)))
		return (NULL);
	if (!nb || base < 2 || base > 16)
	{
		ret[index++] = '0';
		ret[index] = '\0';
		return (ret);
	}
	while (temp)
	{
		if (temp % base > 9)
			ret[index++] = ((temp % base) - 10) + 'A';
		else
			ret[index++] = temp % base + '0';
		temp /= base;
	}
	if (nb < 0 && base == 10)
		ret[index++] = '-';
	ret[index] = 0;
	ft_reverse(ret, ft_strlen(ret));
	return (ret);
}
