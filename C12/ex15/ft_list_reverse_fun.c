#include "ft_list.h"

void		swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int			ft_list_size(t_list *begin_list)
{
	int		size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

void		ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*curr;
	t_list	*next;
	int		begin;
	int		end;
	int		i;

	if (begin_list)
	{
		begin = -1;
		curr = begin_list;
		end = ft_list_size(begin_list);
		while (++begin < --end)
		{
			i = begin;
			next = curr->next;
			while (++i < end)
				next = next->next;
			swap(&curr->data, &next->data);
			curr = curr->next;
		}
	}
}
