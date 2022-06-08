#include "ft_list.h"

void		del_begin(t_list **begin_list, t_list **current, t_list *next, void (*free_fct)(void *))
{
	*begin_list = (*current)->next;
	(*free_fct)((*current)->data);
	free((*current));
}

void		del_elem(t_list **previous, t_list **current, void (*free_fct)(void *))
{
	(*previous)->next = (*current)->next;
	(*free_fct)((*current)->data);
	free((*current));
}

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*previous;

	if (begin_list)
	{
		curr = *begin_list;
		previous = NULL;
		while (curr)
		{
			if (!previous && !(*cmp)(curr->data, data_ref))
				del_begin(begin_list, &curr, free_fct);
			else if (previous && !(*cmp)(curr->data, data_ref))
				del_elem(&previous, &curr, free_fct);
			else
				previous = curr;
			curr = curr->next;
		}
	}
}

