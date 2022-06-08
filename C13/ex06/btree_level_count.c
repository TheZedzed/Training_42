#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int	countl;
	int	countr;

	countl = 0;
	countr = 0;

	if (!root)
		return (0);
	if (root->left)
		countl = btree_level_count(root->left);
	if (root->right)
		countr = btree_level_count(root->right);
	if (countl > countr)
		return (countl + 1);
	return (countr + 1);
}