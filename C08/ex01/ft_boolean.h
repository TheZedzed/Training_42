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

#ifndef	FT_BOOLEAN_H
#define	FT_BOOLEAN_H

#ifndef	EVEN
#define EVEN(nbr)	(!(nbr % 2))
#endif

#ifndef	ODD_MSG
#define	ODD_MSG		"I have an odd number of arguments.\n"
#endif

#ifndef	EVEN_MSG
#define	EVEN_MSG	"I have an even number of arguments.\n"
#endif

#ifndef	SUCCESS
#define	SUCCESS		0
#endif

typedef enum	e_bool
{
	TRUE,
	FALSE
}		t_bool;

t_bool		ft_is_even(int nbr);
void		ft_putstr(char *str);

#endif
