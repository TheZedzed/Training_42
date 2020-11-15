/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 23:16:49 by alex              #+#    #+#             */
/*   Updated: 2020/07/18 23:16:52 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_test.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*new_node;

	if (!(new_node = (t_list *) malloc(sizeof(new_node))))
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*last_node;

	elem = (*begin_list);
	last_node = ft_create_elem(data);
	while (elem->next)
		elem = elem->next;
	elem->next = last_node;
}

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	size;

	size = (unsigned int) ft_list_size(begin_list);
	if (nbr < 1 || nbr > size)
		return (NULL);
	while (--nbr)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_print(t_list *list)
{
	while (list)
	{
		printf("address: %p, data: %s\n", list, (char *)list->data);
		list = list->next;
	}
	printf("\n");
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*first_node;

	first_node = ft_create_elem(data);
	first_node->next = (*begin_list);
	(*begin_list) = first_node;
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*next;
	t_list	*previous;

	current = (*begin_list);
	next = NULL;
	previous = NULL;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	(*begin_list) = previous;
}

int	main(void)
{
	t_list	*list;

	ft_list_push_front(&list, "1");
	ft_list_push_front(&list, "11");
	ft_list_push_front(&list, "111");
	ft_list_push_front(&list, "1111");
	ft_list_push_back(&list, "1234");
	printf("list size: %d\n", ft_list_size(list));
    	printf("list[%d], address: %p\n\n", 1, ft_list_at(list, 2));
	ft_print(list);
	printf("last data: ");
	ft_print(ft_list_last(list));
	ft_list_reverse(&list);
	ft_print(list);
	return (0);
}
