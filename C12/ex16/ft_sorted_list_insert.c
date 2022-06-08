#include "ft_list.h"

void		swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list		*ft_create_elem(void *ref)
{
	t_list	*new_node;

	if (!(new_node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_node->data = ref;
	new_node->next = NULL;
	return (new_node);
}

void		ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*next;
	t_list	*curr;
	t_list	*elem;

	if (begin_list)
	{
		curr = *begin_list;
		elem = ft_create_elem(data);
		while (curr)
		{
			next = curr->next;
			if ((*cmp)(curr->data, data) > 0)
			{
				swap(&curr->data, &elem->data);
				curr->next = elem;
				elem->next = next;
				break ;
			}
			curr = next;
		}
	}
}
