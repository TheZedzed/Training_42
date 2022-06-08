/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:02:30 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 19:08:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_DO_OP_H
#define	FT_DO_OP_H

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
void	val_error(int op);
int	ft_multi(int a, int b);
int	ft_div(int a, int b);
int	ft_add(int a, int b);
int	ft_subs(int a, int b);
int	ft_mod(int a, int b);
int	chosen_func(int op);
int	ft_atoi(char *s);
int	do_op(int val1, int val2, int(*f)(int, int));
#endif
