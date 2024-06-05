#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse a binary tree in post-order fashion
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function traverses a binary tree using post-order
 * traversal. It visits the left subtree first, then the right subtree,
 * and finally the root node. For each node visited, the function
 * pointed to by @func is called with the node's value.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    /* Check if tree or func is NULL */
    if (!tree || !func)
        return;

    /* Recursively traverse the left subtree */
    binary_tree_postorder(tree->left, func);

    /* Recursively traverse the right subtree */
    binary_tree_postorder(tree->right, func);

    /* Call the function with the current node's value */
    func(tree->n);
}
