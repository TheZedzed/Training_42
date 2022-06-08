#include "ft_list.h"

void		ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*previous;
	t_list	*curr;

	previous = NULL;
	if (begin_list1)
	{
		curr = *begin_list1;
		while (curr)
		{
			previous = curr;
			curr = curr->next;
		}
		previous->next = begin_list2;
	}
}
