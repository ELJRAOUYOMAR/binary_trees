#include "binary_trees.h"

/**
 * binary_tree_depth - Measure the depth of a node in a binary tree
 * @tree: Node to calculate the depth of
 *
 * Description: This function calculates the depth of a given node
 * in a binary tree. The depth of a node is defined as the number
 * of edges between the node and the tree's root node. The depth of
 * the root node is 0.
 *
 * Return: Depth of the node.
 *         0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    /* Check if tree is NULL */
    if (!tree)
        return (0);

    /* Traverse up the tree until reaching the root */
    while (tree->parent)
    {
        depth++;
        tree = tree->parent;
    }

    return (depth);
}
