/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_test.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 11:45:18 by alex              #+#    #+#             */
/*   Updated: 2020/08/02 11:45:56 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LIST_TEST_H
#define	FT_LIST_TEST_H

#include <stdio.h>
#include <unistd.h>

typedef struct		s_list
{
	void		*data;
	struct s_list	*next;
}			t_list;

void			ft_print(t_list *list);
void			ft_list_reverse(t_list **begin_list);
void			ft_list_push_back(t_list **begin_list, void *data);
void			ft_list_push_front(t_list **begin_list, void *data);

int			ft_list_size(t_list *begin_list);

t_list			*ft_create_elem(void *data);
t_list			*ft_list_last(t_list *begin_list);
t_list			*ft_list_at(t_list *begin_list, unsigned int nbr);
#endif
