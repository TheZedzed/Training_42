/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 21:21:36 by alex              #+#    #+#             */
/*   Updated: 2020/08/10 19:10:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_matrice(int **tab, int size);
void	print_resolved_matrice(int **tab, int size);
void	free_fct(int **tab, int size);
void	*ft_memset(void *s, int c, int n);

void	argv_to_matrice(char **argv, int **tab, int size);
int	first_step(int **tab, int size);

int	check_args(char **av, int size);
int	check_nums(char **av, int size);
int	check_double(char **av, int size);
int	ft_strlen(const char *s);

int	fill_with_colup(int **tab, int size);
int	fill_with_rowlt(int **tab, int size);
int	is_free(int **tab, int row, int column);
int	fill_step(int **tab, int size);
int	good_vision(int **tab, int size);
int	**init_matrice(char **argv, int argc);

int	good_vision(int **tab, int size)
{
	int	i;
	int	j;
	int	val;
	int	count;

	i = 0;
	while (++i < size)
	{
		j = 0;
		count = 0;
		val = tab[i][j];
		while (++i < size)
		{
			if (val != 1 && val != size)
				count++;
		}
	}
	return (1);
}

int	solveNQUtil(int **tab, int size, int col)
{
	int	i;

	i = -1;
	if (col >= size)
		return (1);
	/* Consider this column and try placing 
	this queen in all rows one by one */
	while (++i < size)
	{
		/* Check if the queen can be placed on 
		  board[i][col] */
		if (is_free(tab, i, col))
		{
		    /* Place this queen in board[i][col] */
			tab[i][col] = 1;
		    /* recur to place rest of the queens */
		    if (solveNQUtil(tab, col + 1))
			return (1);
		    /* If placing queen in board[i][col] 
		       doesn't lead to a solution, then 
		       remove queen from board[i][col] */
			tab[i][col] = 0;// BACKTRACK 
		}
	}
	/* If the queen cannot be placed in any row in 
	this colum col  then return false */
	return (0);
}

int	is_free(int **tab, int row, int column, int val)
{
	int	i;
	int	j; 

	i = 0;
	j = 0;
	if (tab[row][column])
		return (0);
	while (++i < size - 1)
	{
		if (i == row)
			i++;
		if (i < size - 1 && tab[i][column] == val)
			return (0);
	}
	while (++j < size - 1)
	{
		if (j == column)
			j++;
		if (j < size - 1 && tab[row][j] == val)
			return (0);
	}
	return (1);
}

int	fill_step(int **tab, int size, int column)
{
	int	i;
	int	j;
	int	number;

	number = 0;
	while (++number < 10)
	{
		i = 0;
		j = 0;
		while ()
		{
			is_free(tab, i, j, number)
	}
	return (0);
}

int	fill_with_rowlt(int **tab, int row, int column, int size)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	j = 0;
	while (++i < size - 1)
	{
		if (tab[i][j] == 1)
		{
			if (tab[i][size - 1] != 1)
				tab[i][j + 1] = size - 2;
			else
				return (1);
		}
		if (tab[i][j] == size - 2)
		{
			if (tab[i][size - 1] == 1)
			{
				pos = 0;
				while (++pos < size - 1)
					tab[i][pos] = pos;
			}
			else
				return (1);
		}
	}
	return (0);
}

int	fill_with_colup(int **tab, int size)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	j = 0;
	while (++j < size - 1)
	{
		if (tab[i][j] == 1)
		{
			if (tab[size - 1][j] != 1)
				tab[i + 1][j] = size - 2;
			else
				return (1);
		}
		if (tab[i][j] == size - 2)
		{
			if (tab[size - 1][j] == 1)
			{
				pos = 0;
				while (++pos < size - 1)
					tab[pos][j] = pos;
			}
			else
				return (1);
		}
	}
	return (0);
}

int	first_step(int **tab, int size)
{
	if (!fill_with_colup(tab, size))
		if (!fill_with_rowlt(tab, size))
				return (0);
	return (1);
}

int	check_double(char **av, int size)
{
	int	higher;
	int	i;
	int	j;

	i = 0;
	higher = size;
	while (av[size])
	{
		while (av[++i] && i <= size)
		{
			j = i;
			if (av[i][0] == higher + '0')
				while (++j <= size)
					if (av[j][0] == higher + '0')
						return (1);
			if (av[i][0] == '1')
				while (++j <= size)
					if (av[j][0] == '1')
						return (1);
		}
		i--;
		size += higher;
	}
	return (0);
}

int	check_nums(char **av, int size)
{
	int	i;

	i = 0;
	while (av[++i])
		if (!(ft_strlen(av[i]) == 1 && av[i][0] <= size + '0'
			&& av[i][0] >= '0'))
			return (1);
	return (0);
}

int	check_args(char **av, int size)
{
	if (size > 2 && size < 10)
		if (!check_nums(av, size) && !check_double(av, size))
			return (0);
	return (1);
}

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	*ft_memset(void *s, int c, int n)
{
	unsigned char	*ptr;
	unsigned char	*end;

	ptr = (unsigned char *)s;
	end = ptr + n;
	while (ptr < end)
		*ptr++ = (unsigned char)c;
	return (s);
}

void	argv_to_matrice(char **argv, int **tab, int size)
{
	int	j;

	j = 1;
	while (j < size - 1)
	{
		++argv;
		tab[0][j++] = *argv[0] - 48;
	}
	j = 1;
	while (j < size - 1)
	{
		++argv;
		tab[size - 1][j++] = *argv[0] - 48;
	}
	j = 1;
	while (j < size - 1)
	{
		++argv;
		tab[j++][0] = *argv[0] - 48;
	}
	j = 1;
	while (j < size - 1)
	{
		++argv;
		tab[j++][size - 1] = *argv[0] - 48;
	}
}

void	print_matrice(int **tab, int size)
{
	int	i;
	int	j;
	int	nb;

	i = -1;
	while (++i < size)
	{
		j = - 1;
		while (++j < size)
		{
			nb = tab[i][j] + 48;
			write(1, &nb, 1);
		}
		write(1, "\n", 1);
	}
}

void	print_resolved_matrice(int **tab, int size)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (++i < size - 1)
	{
		j = 0;
		while (++j < size - 1)
		{
			nb = tab[i][j] + 48;
			write(1, &nb, 1);
		}
		write(1, "\n", 1);
	}
}

int	**init_matrice(char **argv, int size)
{
	int	**tab;
	int	i;

	i = -1;
	if (!(tab = (int **) malloc(sizeof(int *) * size)))
		return (NULL);
	while (++i < size)
	{
		if (!(tab[i] = (int *) malloc(sizeof(int) * size)))
			return (NULL);
		ft_memset(tab[i], 0, sizeof(int) * size);
	}
	argv_to_matrice(argv, tab, size);
	return (tab);
}

void	free_fct(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}

int	main(int argc, char **argv)
{
	int	**mat;
	int	size;

	size = (argc - 1) / 4;
	if (!((argc - 1) % 4) && !check_args(argv, size))
	{
		size += 2;
		if (mat = init_matrice(argv, size))
		{
			write(1, "Actual matrice:\n", 16);
			print_matrice(mat, size);
			if (!first_step(mat, size))
			{
				write(1, "\nFirst step passed:\n", 20);
				//if (!fill_step(mat, size))
				//{
					write(1, "Bactracking success:\n", 21);
					print_resolved_matrice(mat, size);
				//}
			}
			else
				write(1, "No solution\n", 12);
			free_fct(mat, size);
		}
		else
			write(1, "Error when init matrice\n", 24);
	}
	else
		write(1, "Error arguments\n", 16);
	return (0);
}
