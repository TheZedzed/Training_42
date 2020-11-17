#include "ft_list.h"

void 		free_fct(void *data)
{
	free(data);
}

int			cmp(void *a, void *b)
{
	if(*(int*)a == *(int*)b)
		return 0;
	return 1;
}

/*
** tu peux découper en trois fct: begin del, middle del, end del
*/

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*next;
	t_list	*previous;

	curr = *begin_list;
	previous = NULL;
	while (curr)
	{
		next = curr->next;
		if (!previous && !(*cmp)(curr->data, data_ref))
		{
			printf("beg deleted\n");
			(*free_fct)(curr->data);
			free(curr);
			*begin_list = next;
			curr = next;
		}
		else if (previous && next && !(*cmp)(curr->data, data_ref))
		{
			printf("Middle deleted\n");
			previous->next = next;
			(*free_fct)(curr->data);
			free(curr);
			curr = next;
		}
		else if (previous && !next && !(*cmp)(curr->data, data_ref))
		{
			printf("End deleted\n");
			previous->next = NULL;
			(*free_fct)(curr->data);
			free(curr);
			curr = NULL;
		}
		else
		{
			printf("nothing deleted\n");
			previous = curr;
			curr = next;
		}
	}
}

int main(void)
{
	int *tab1 = malloc(sizeof(int));
	int *tab2 = malloc(sizeof(int));
	int *tab3 = malloc(sizeof(int));
	int *tab4 = malloc(sizeof(int));
	int *tab5 = malloc(sizeof(int));

	*tab1 = 1;
	*tab2 = 1;
	*tab3 = 1;
	*tab4 = 1;
	*tab5 = 1;

	t_list *head = malloc(sizeof(t_list));
	t_list *list2 = malloc(sizeof(t_list));
	t_list *list3 = malloc(sizeof(t_list));
	t_list *list4 = malloc(sizeof(t_list));
	t_list *list5 = malloc(sizeof(t_list));

	head->data = tab1;
	list2->data = tab2;
	list3->data = tab3;
	list4->data = tab4;
	list5->data = tab5;

	head->next = list2;
	list2->next = list3;
	list3->next = list4;
	list4->next = list5;
	list5->next = NULL;

	int one = 1;
	ft_list_remove_if(NULL, (void*)&one, &cmp, &free_fct);
	while (head)
	{
		printf("%d\n", *(int*)head->data);
		head = head->next;
	}
	return 0;
}
