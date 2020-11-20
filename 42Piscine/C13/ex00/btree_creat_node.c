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