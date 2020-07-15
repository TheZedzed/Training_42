/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:09:50 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 19:09:52 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	val_error(int op)
{
	if (operator == 37)
		ft_putstr("Stop : modulo by zero\n");
	else
		ft_putstr("Stop : division by zero\n");
}
