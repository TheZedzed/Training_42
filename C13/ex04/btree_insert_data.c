#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree	*node;

	if (!(node = (t_btree *)malloc(sizeof(t_btree))))
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->item = item;
	return (node);
}

void		btree_insert_data(t_btree **root, void *item, int ((*cmpf)(void *, void *)))
{
	if (!(*root))
		btree_create_node(item);
	else if ((*cmpf)(&(*root)->item, item) > 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}
