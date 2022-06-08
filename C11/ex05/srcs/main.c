/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:11:19 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 22:16:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

int	main(int ac, char **av)
{
	int	val1;
	int	val2;
	int	res;
	int	operator;
	int	(*f[])(int, int) = {ft_add, ft_subs, ft_multi, ft_div, ft_mod};

	if (ac == 4)
	{
		val1 = ft_atoi(av[1]);
		val2 = ft_atoi(av[3]);
		operator = (int)av[2][0];
		if (!val2 && (operator == 37 || operator == 47))
			val_error(operator);
		else
		{
			res = chosen_func(operator);
			if (res < 0)
				ft_putstr("0");
			else
				ft_putnbr(do_op(val1, val2, f[res]));
		}
		write(1, "\n", 1);
	}
	return (0);
}
