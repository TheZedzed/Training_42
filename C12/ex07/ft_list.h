/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 23:06:06 by alex              #+#    #+#             */
/*   Updated: 2020/07/16 00:16:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LIST_H
#define	FT_LIST_H

typedef struct		s_list
{
	void		*data;
	struct s_list	*next;
}			t_list;

int			ft_list_size(t_list *begin_list);
t_list			*ft_list_at(t_list *begin_list, unsigned int nbr);
#endif
