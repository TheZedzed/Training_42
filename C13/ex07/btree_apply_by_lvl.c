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

void	apply_level(t_btree *root, int level, int first, void (*applyf)(void *item, int current_lvl, int is_first_elem))
{
	if (!root)
		return ;
	if (!level)
		(*applyf)(root->item, level, first);
	else if (level > 0)
	{
		apply_level(root->left, level - 1, first, applyf);
		first = 0;
		apply_level(root->right, level - 1, first, applyf);
	}
}

void	btree_apply_by_lvl(t_btree *root, void (*applyf)(void *item, int current_lvl, int is_first_elem))
{
	int	level;
	int	height;

	level = -1;
	height = btree_level_count(root);
	while (++level < height)
		apply_level(root, level, 1, applyf);
}
