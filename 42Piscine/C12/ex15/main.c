#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list);

int		main(void)
{
	int *tab1 = malloc(sizeof(int));
	int *tab2 = malloc(sizeof(int));
	int *tab3 = malloc(sizeof(int));
	int *tab4 = malloc(sizeof(int));
	int *tab5 = malloc(sizeof(int));

	*tab1 = 1;
	*tab2 = 2;
	*tab3 = 4;
	*tab4 = 8;
	*tab5 = 10;

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

	ft_list_reverse(&head);
	while (head)
	{
		printf("%d\n", *(int*)head->data);
		head = head->next;
	}
	while (head)
	{
		t_list *tmp = head->next;
		free(head->data);
		free(head);
		head = tmp;
	}
	return 0;
}
