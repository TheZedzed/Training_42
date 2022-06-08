#include "ft_btree.h"

/*
** inorder: pour rechercher, postorder: pour free, preorder: pour ajouter
*/

void		btree_apply_by_lvl(t_btree *root, void (*applyf)(void *item, int current_lvl, int is_first_elem));

void		btree_free_post(t_btree *root)
{
	if (!root)
		return ;
	btree_free_post(root->left);
	btree_free_post(root->right);
	free(root);
}

void		display(void *item, int lvl, int elem)
{
	(void)lvl;
	if (elem)
		printf("\nFirst elem: %s\n", (char *)item);
	else
		printf("elem: %s\n", (char *)item);
}

int			main(void)
{
	t_btree *root = malloc(sizeof(t_btree));
	t_btree *node1 = malloc(sizeof(t_btree));
	t_btree *node2 = malloc(sizeof(t_btree));
	t_btree *node3 = malloc(sizeof(t_btree));
	t_btree *node4 = malloc(sizeof(t_btree));
	t_btree *node5 = malloc(sizeof(t_btree));
	t_btree *node6 = malloc(sizeof(t_btree));
	t_btree *node7 = malloc(sizeof(t_btree));
	t_btree *node8 = malloc(sizeof(t_btree));

	char	*tab0 = "root_node";
	char	*tab1 = "lvl1_node1_left";
	char	*tab2 = "lvl1_node2_right";
	char	*tab3 = "lvl2_node1_left";
	char	*tab4 = "lvl2_node2_right";
	char	*tab5 = "lvl2_node3_left";
	char	*tab6 = "lvl2_node3_right";
	char	*tab7 = "lvl3_node1_left";
	char	*tab8 = "lvl3_node2_right";

	root->left = node1;
	root->right = node2;
	root->item = tab0;

	node1->left = node3;
	node1->right = node4;
	node1->item = tab1;

	node2->left = node5;
	node2->right = node6;
	node2->item = tab2;

	node3->left = node7;
	node3->right = node8;
	node3->item = tab3;

	node4->left = NULL;
	node4->right = NULL;
	node4->item = tab4;
	
	node5->left = NULL;
	node5->right = NULL;
	node5->item = tab5;

	node6->left = NULL;
	node6->right = NULL;
	node6->item = tab6;

	node7->left = NULL;
	node7->right = NULL;
	node7->item = tab7;

	node8->left = NULL;
	node8->right = NULL;
	node8->item = tab8;

	btree_apply_by_lvl(root, &display);
	btree_free_post(root);
	return (0);
}
