#include "ft_list.h"

void		swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*curr;
	t_list	*next;

	if (begin_list)
	{
		curr = *begin_list;
		while (curr)
		{
			next = curr->next;
			while (next)
			{
				if ((*cmp)(curr->data, next->data) > 0)
					swap(&curr->data, &next->data);
				next = next->next;
			}
			curr = curr->next;
		}
	}
}

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

void		ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
