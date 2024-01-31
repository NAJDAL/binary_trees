#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, and 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * check_parent - Checks if a parent node has a greater value than its children.
 *
 * @tree: A pointer to the node to check.
 *
 * Return: 1 if the parent node has a greater value than its children, 0 otherwise.
 */
int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, and 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (tree == NULL)
		return (0);

	cnodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, cnodes));
}

/**
 * tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: A pointer to the root node of the tree to check.
 * @i: The index of the current node.
 * @cnodes: The number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, and 0 otherwise.
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The size of the tree or 0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
