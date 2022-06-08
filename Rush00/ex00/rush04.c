/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:49:42 by alex              #+#    #+#             */
/*   Updated: 2020/08/09 15:40:01 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_atoi(const char *s)
{
	int	res;

	res = 0;
	while (*s && (*s == 32 || (*s >= 9 && *s <= 13)))
		s++;
	while (*s && (*s == 45 || *s == 43))
		if (*s++ == 45)
			return (0);
	while (*s && (*s >= 48 && *s <= 57))
		res = (res * 10) + (*s++ - 48);
	return (res);
}

void	rush(int x, int y)
{
	int	width;
	int	height;

	height = 1;
	while (height <= y)
	{
		width = 1;
		while (width <= x)
		{
			if (height == 1 || height == y)
			{
				if ((width == 1 && height == 1) || (width >1 &&
					height > 1))
					ft_putchar('A');
				else
					ft_putchar('C');
				while (++width < x)
					ft_putchar('B');
			}
			if (height > 1 && height < y)
			{
				ft_putchar('B');
				while (++width < x)
					ft_putchar(' ');
			}
		}
		height++;
		ft_putchar('\n');
	}
}
