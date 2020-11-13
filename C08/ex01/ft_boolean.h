/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 21:34:58 by alex              #+#    #+#             */
/*   Updated: 2020/05/21 03:31:30 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>
# define EVEN(nbr)	(!(nbr % 2))
# define ODD_MSG	"I have an odd number of arguments.\n"
# define EVEN_MSG	"I have an even number of arguments.\n"
# define SUCCESS	0

typedef enum	e_bool
{
	TRUE = 1,
	FALSE = 0
}				t_bool;

t_bool			ft_is_even(int nbr);
void			ft_putstr(char *str);

#endif
