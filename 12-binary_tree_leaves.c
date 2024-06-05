#include "binary_trees.h"

/**
 * binary_tree_leaves - Count the leaves in a binary tree
 * @tree: Tree to count the leaves from
 *
 * Description: This function counts the number of leaves in a binary tree.
 * A leaf is a node that does not have any children (both left and right
 * child nodes are NULL).
 *
 * Return: Number of leaves in the tree.
 *         0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    /* Check if tree is NULL */
    if (!tree)
        return (0);

    /* If the current node is a leaf, return 1 */
    if (!tree->left && !tree->right)
        return (1);

    /* Recursively count the leaves in the left and right subtrees */
    return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
