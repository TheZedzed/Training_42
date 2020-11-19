#include "ft_list.h"
			
void		ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*current;
	t_list	*next;
	t_list	*previous;

	current = begin_list;
	next = NULL;
	previous = NULL;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	begin_list = previous;

}