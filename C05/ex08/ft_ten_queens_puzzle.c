/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ft_queen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 09:59:44 by alex              #+#    #+#             */
/*   Updated: 2020/09/13 11:10:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void		display_answer(int *tab)
{
	char	nb;
	int		i;

	i = -1;
	while (++i < 10)
	{
		nb = tab[i] + 48;
		write(1, &nb, 1);
	}
	write(1, "\n", 1);
}

int			abs(int nb)
{
	return (nb < 0 ? nb * -1 : nb);
}

int			safe_placement(int *tab, int column, int row)
{
	int		j;
	int		val;

	j = -1;
	while (++j < row)
	{
		val = tab[j];
		if (val == column || abs(row - j) == abs(column - val))
			return (0);
	}
	return (1);
}

void		ten_queens_solver(int *tab, int *count, int row)
{
	int		column;

	column = -1;
	if (row == 10)
	{
		display_answer(tab);
		(*count)++;
	}
	else
	{
		while (++column < 10)
		{
			if (safe_placement(tab, column, row))
			{
				tab[row] = column;
				ten_queens_solver(tab, count, row + 1);
			}
		}
	}
}

int			ft_ten_queens_puzzle(void)
{
	int		nb_of_solution;
	int		tab[10];
	int		i;

	i = -1;
	nb_of_solution = 0;
	while (++i < 10)
		tab[i] = 0;
	ten_queens_solver(tab, &nb_of_solution, 0);
	return (nb_of_solution);
}
