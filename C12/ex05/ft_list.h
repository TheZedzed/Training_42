/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 23:06:06 by alex              #+#    #+#             */
/*   Updated: 2020/08/01 12:15:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LIST_H
#define	FT_LIST_H

#include <stdlib.h>

typedef struct		s_list
{
	void		*data;
	struct s_list	*next;
}			t_list;

void			ft_list_push_front(t_list **head, void *data);
t_list			*ft_create_elem(void *data);
t_list			*ft_list_push_strs(int size, char **strs);
#endif
