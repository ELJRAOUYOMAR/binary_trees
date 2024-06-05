#include "binary_trees.h"

size_t binary_tree_measure_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Description: This function measures the balance factor of a binary tree.
 * The balance factor of a node is defined as the height of its left subtree
 * minus the height of its right subtree. A balance factor of 0 indicates a
 * balanced tree, a positive value indicates a tree leaning to the left, and
 * a negative value indicates a tree leaning to the right.
 *
 * Return: The balance factor of the tree.
 *         0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int left_height, right_height;

    /* If tree is NULL, return balance factor 0 */
    if (!tree)
        return (0);

    /* Calculate the height of the left subtree */
    left_height = tree->left ? (int)binary_tree_measure_height(tree->left) : -1;

    /* Calculate the height of the right subtree */
    right_height = tree->right ? (int)binary_tree_measure_height(tree->right) : -1;

    /* Return the balance factor */
    return (left_height - right_height);
}

/**
 * binary_tree_measure_height - Measures the height of a binary tree
 * @tree: Tree to measure the height of
 *
 * Description: This function measures the height of a binary tree recursively.
 * The height of a tree is defined as the length of the longest path from the
 * root node to a leaf node. The height of an empty tree (NULL) is considered
 * to be 0.
 *
 * Return: Height of the tree.
 *         0 if tree is NULL.
 */
size_t binary_tree_measure_height(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    /* If tree is NULL, return height 0 */
    if (!tree)
        return (0);

    /* Calculate the height of the left subtree */
    left_height = tree->left ? 1 + binary_tree_measure_height(tree->left) : 0;

    /* Calculate the height of the right subtree */
    right_height = tree->right ? 1 + binary_tree_measure_height(tree->right) : 0;

    /* Return the maximum height */
    return (left_height > right_height ? left_height : right_height);
}
