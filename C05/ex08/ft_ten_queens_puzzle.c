/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 20:21:40 by alex              #+#    #+#             */
/*   Updated: 2020/08/19 22:08:58 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define  SIZE	2
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_answer(int tab[SIZE])
{
	char	nb;
	int	i;

	i = -1;
	while (++i < SIZE)
	{
		nb = tab[i] + 48;
		write(1, &nb, 1);
	}
	write(1, "\n", 1);
}

int	is_safe(int tab[SIZE][SIZE], int row, int col)
{
	int	i;
	int	j;

	j = -1;
	while (++j < col)
		if (tab[row][j])
			return (0);
	i = row + 1;
	j = col + 1;
	while (--i >= 0 && --j >= 0)
		if (tab[i][j])
			return (0);
	i = row - 1;
	j = col + 1;
	while (++i < SIZE && --j >= 0)
		if (tab[i][j])
			return (0); 	
	return (1);
}

int	solver(int tab[SIZE][SIZE], int solution[SIZE + 1], int col)
{
	int	i;

	i = -1;
	if (col == SIZE)
	{
		solution[SIZE]++;
		display_answer(solution);
		return (1);
	}
	while (++i < SIZE)
	{
		if (is_safe(tab, i, col))
		{
			tab[i][col] = 1;
			solution[i] = col;
			if (solver(tab, solution, col + 1))
				return (1);
			tab[i][col] = 0;
		}
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[SIZE][SIZE] = {0};
	int	res[SIZE + 1] = {0};

	solver(tab, res, 0);
	return (res[SIZE]);
}

int	main(void)
{
	if (ft_ten_queens_puzzle() > 0)
		printf("%d\n", ft_ten_queens_puzzle());
	printf("No solutions.\n");
	return (0);
}
