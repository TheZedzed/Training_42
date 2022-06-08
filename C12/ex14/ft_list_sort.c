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