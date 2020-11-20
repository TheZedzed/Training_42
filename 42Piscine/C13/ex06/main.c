#include "ft_btree.h"

/*
** inorder: pour rechercher, postorder: pour free, preorder: pour ajouter
*/

void		btree_free_post(t_btree *root)
{
	if (!root)
		return ;
	btree_free_post(root->left);
	btree_free_post(root->right);
	free(root);
}

void		display(void *item)
{
	printf("%s\n", (char *)item);
}

int			ft_strcmp(void *a, void *b)
{
	while (a && a == b)
	{
		a++;
		b++;
	}
	return (*(unsigned char *)a - *(unsigned char *)b);
}

int			main(void)
{
	void	*res;
	char	*data_ref = "c";
	t_btree *root = malloc(sizeof(t_btree));
	t_btree *node1 = malloc(sizeof(t_btree));
	t_btree *node2 = malloc(sizeof(t_btree));
	t_btree *node3 = malloc(sizeof(t_btree));
	t_btree *node4 = malloc(sizeof(t_btree));

	char	*tab1 = "a";
	char	*tab2 = "b";
	char	*tab3 = "c2";
	char	*tab4 = "c1";
	char	*tab5 = "d";

	root->left = node1;
	root->right = node2;
	root->item = tab1;

	node1->left = node3;
	node1->right = node4;
	node1->item = tab2;

	node2->left = NULL;
	node2->right = NULL;
	node2->item = tab3;

	node3->left = NULL;
	node3->right = NULL;
	node3->item = tab4;

	node4->left = NULL;
	node4->right = NULL;
	node4->item = tab5;

	res = btree_search_item(root, data_ref, &ft_strcmp);
	if (res)
		display(res);
	btree_free_post(root);
	return (0);
}
