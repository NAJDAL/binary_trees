#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (maxDepth(tree) - 1);
}

/**
 * maxDepth - Calculates the maximum depth of a binary tree.
 *
 * @node: Pointer to the current node.
 *
 * Return: The maximum depth of the subtree rooted at the given node.
 */
int maxDepth(const binary_tree_t *node)
{
    if (node == NULL)
        return (0);
    else
    {
        /* Compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* Use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
