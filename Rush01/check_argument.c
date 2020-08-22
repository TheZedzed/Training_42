/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 00:53:22 by alex              #+#    #+#             */
/*   Updated: 2020/08/15 19:39:05 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	check_nums(char **av, int higher)
{
	if (!check_double(av, higher) && !check_corner
int	check_opposite(char **av, int higher)
{
	int	i;

	i = 0;
	while (av[i + higher])
	{
		if (av[i + 1][0] == '1' && av[
		if (av[higher][0]== '1')
int	check_double(char **av, int higher)
{
	int	i;
	int	j;

	i = 0;
	while (av[i + higher])
	{
		j = i + 1;
		if (av[j][0] == higher + '0')
			while (++j <= i + higher)
				if (av[j][0] == higher + '0')
					return (1);
		else if (av[j][0] == '1')
			while (++j <= i + higher)
				if (av[j][0] == '1')
					return (1);
		i += higher;
	}
	return (0);
}

int	check_ifnums(char **av, int higher)
{
	int	i;

	i = 0;
	while (av[++i])
		if (av[i][1] || av[i][0] > higher + '0' || av[i][0] < '1')
			return (-1);
	return (0);
}

int	check_args(char **av, int higher)
{
	if (!check_ifnums(av, higher) && !check_nums(av, higher))
		return (0);
	return (1);
}
