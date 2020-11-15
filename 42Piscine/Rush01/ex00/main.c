/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:44:45 by alex              #+#    #+#             */
/*   Updated: 2020/08/09 15:54:58 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#define SIZE 4

int			check_args(char *av)
{
	if (av[1])
		return (1);
	return (0);
}

int			is_safe_row(int **game, int column, int row, int num)
{
	int		i;

	i = 0;
	while (++i < column)
		if (game[row][i] == num)
			return (0);
	return (1);
}

int			is_safe_column(int **game, int column, int row, int num)
{
	int		i;

	i = 0;
	while (++i < row)
		if (game[i][column] == num)
			return (0);
	return (1);
}

int			respect_rowL_constraint(int **game, int row, int constraint)
{
	int		i;
	int		max;
	int		view;

	i = 0;
	max = game[row][1];
	view = 1;
	while (++i < SIZE)
	{
		if (max < game[row][i + 1])
		{
			max = game[row][i + 1];
			view++;
		}
	}
	if (view == constraint)
		return (1);
	return (0);
}

int			respect_rowR_constraint(int **game, int row, int constraint)
{
	int		i;
	int		max;
	int		view;

	i = SIZE + 1;
	max = game[row][SIZE];
	view = 1;
	while (--i > 1)
	{
		if (max < game[row][i - 1])
		{
			max = game[row][i - 1];
			view++;
		}
	}
	if (view == constraint)
		return (1);
	return (0);
}

int			respect_colU_constraint(int **game, int column, int constraint)
{
	int		i;
	int		max;
	int		view;

	i = 0;
	max = game[1][column];
	view = 1;
	while (++i < SIZE)
	{
		if (max < game[i + 1][column])
		{
			max = game[i + 1][column];
			view++;
		}
	}
	if (view == constraint)
		return (1);
	return (0);
}

int			respect_colD_constraint(int **game, int column, int constraint)
{
	int		i;
	int		max;
	int		view;

	i = SIZE + 1;
	max = game[SIZE][column];
	view = 1;
	while (--i > 1)
	{
		if (max < game[i - 1][column])
		{
			max = game[i - 1][column];
			view++;
		}
	}
	if (view == constraint)
		return (1);
	return (0);
}

int			respect_column_constraint(int **game, int column)
{
	if (!respect_colD_constraint(game, column, game[SIZE + 1][column]))
		return (0);
	if (!respect_colU_constraint(game, column, game[0][column]))
		return (0);
	return (1);
}

int			respect_row_constraint(int **game, int row)
{
	if (!respect_rowR_constraint(game, row, game[row][SIZE + 1]))
		return (0);
	if (!respect_rowL_constraint(game, row, game[row][0]))
		return (0);
	return (1);
}

void		display_game(int **game)
{
	int		i;
	int		j;
	char	nb;

	i = 0;
	while (++i <= SIZE)
	{
		j = 0;
		while (++j <= SIZE)
		{
			nb = game[i][j] + 48;
			write(1, &nb, 1);
			if (j != SIZE)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

void		fill_game(int **game, char *av)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (++i <= SIZE)
	{
		game[0][i] = av[j] - 48;
		j += 2;
	}
	i = 0;
	while (++i <= SIZE)
	{
		game[SIZE + 1][i] = av[j] - 48;
		j += 2;
	}
	i = 0;
	while (++i <= SIZE)
	{
		game[i][0] = av[j] - 48;
		j += 2;
	}
	i = 0;
	while (++i <= SIZE)
	{
		game[i][SIZE + 1] = av[j] - 48;
		j += 2;
	}
}

int			**init_game(int **game, char *av)
{
	int		i;
	int		j;

	i = -1;
	if (!(game = (int **)malloc(sizeof(int *) * (SIZE + 2))))
		return (NULL);
	while (++i <= SIZE + 1)
	{
		j = -1;
		if (!(game[i] = (int *)malloc(sizeof(int) * (SIZE + 2))))
			return (NULL);
		while (++j <= SIZE + 1)
			game[i][j] = 0;
	}
	fill_game(game, av);
	return (game);
}

int			empty_place(int **game, int *row, int *column)
{
	int		i;
	int		j;

	i = 0;
	while (++i <= SIZE)
	{
		j = 0;
		while (++j <= SIZE)
		{
			if (!game[i][j])
			{
				*row = i;
				*column = j;
				return (1);
			}
		}
	}
	return (0);
}

int			game_solver(int **game)
{
	int		num;
	int		row;
	int		column;

	num = 0;
	if (!empty_place(game, &row, &column))
	{
		display_game(game);
		return (1);
	}
	while (++num <= SIZE)
	{
		game[row][column] = num;
		if (is_safe_column(game, column, row, num) && is_safe_row(game, column, row, num))
		{
			if (column == SIZE && !respect_row_constraint(game, row))
			{
				game[row][column] = 0;
				continue ;
			}
			if (row == SIZE && !respect_column_constraint(game, column))
			{
				game[row][column] = 0;
				continue ;
			}
			if (game_solver(game))
				return (1);
		}
		game[row][column] = 0;
	}
	return (0);
}

void		ft_free(int **game)
{
	int		i;

	i = -1;
	while (++i <= SIZE + 1)
		free(game[i]);
	free(game);
}

int			main(int ac, char **av)
{
	int		**game;

	game = NULL;
	if (ac == 2 && check_args(av[1]))
	{
		if (!(game = init_game(game, av[1])))
			write(1, "Error Alloc\n", 12);
		if (!game_solver(game))
			write(1, "Error no solution\n", 18);
	}
	else
		write(1, "Error argument\n", 15);
	ft_free(game);
	return (0);
}
