#include "ft_list.h"

void		del_begin(t_list **begin_list, t_list **current, t_list *next, void (*free_fct)(void *))
{
	(*free_fct)((*current)->data);
	free((*current));
	*begin_list = next;
	*current = next;
}

void		del_middle(t_list **previous, t_list **current, t_list *next, void (*free_fct)(void *))
{
	(*previous)->next = next;
	(*free_fct)((*current)->data);
	free((*current));
	*current = next;
}

void		del_end(t_list **previous, t_list **current, void (*free_fct)(void *))
{
	(*previous)->next = NULL;
	(*free_fct)((*current)->data);
	free((*current));
	(*current) = NULL;
}

void		del_nothing(t_list **previous, t_list **current, t_list *next)
{
	(*previous) = (*current);
	(*current) = next;
}

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*next;
	t_list	*previous;

	if (begin_list)
	{
		curr = *begin_list;
		previous = NULL;
		while (curr)
		{
			next = curr->next;
			if (!previous && !(*cmp)(curr->data, data_ref))
				del_begin(begin_list, &curr, next, free_fct);
			else if (previous && next && !(*cmp)(curr->data, data_ref))
				del_middle(&previous, &curr, next, free_fct);
			else if (previous && !next && !(*cmp)(curr->data, data_ref))
				del_end(&previous, &curr, free_fct);
			else
				del_nothing(&previous, &curr, next);
		}
	}
}
