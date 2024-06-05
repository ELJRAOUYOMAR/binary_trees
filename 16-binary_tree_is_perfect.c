#include "binary_trees.h"

/**
 * calculate_power - Calculates the power of a number recursively
 * @base: The base number
 * @exponent: The exponent to raise the base to
 *
 * Return: The result of base raised to the power of exponent
 */
int calculate_power(int base, int exponent)
{
    if (exponent < 0)
        return (-1);
    if (exponent == 0)
        return (1);
    else
        return (base * calculate_power(base, exponent - 1));
}

/**
 * calculate_tree_nodes - Counts the number of nodes in a binary tree
 * @tree: The root node of the tree
 *
 * Return: The number of nodes in the tree
 */
size_t calculate_tree_nodes(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (calculate_tree_nodes(tree->left) + calculate_tree_nodes(tree->right) + 1);
}

/**
 * calculate_tree_height - Computes the height of a binary tree
 * @tree: The root node of the tree
 *
 * Return: The height of the tree
 */
size_t calculate_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;

    if (!tree)
        return (0);

    left_height = tree->left ? 1 + calculate_tree_height(tree->left) : 0;
    right_height = tree->right ? 1 + calculate_tree_height(tree->right) : 0;

    return (left_height > right_height ? left_height : right_height);
}

/**
 * is_perfect_binary_tree - Determines if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to check
 *
 * Description: This function checks if a binary tree is perfect. A binary tree
 * is considered perfect if all levels are completely filled except possibly for
 * the last level, which is filled from left to right.
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 *         0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height = 0;
    size_t nodes = 0;
    size_t power = 0;

    /* If tree is NULL, return 0 */
    if (!tree)
        return (0);

    /* If the tree has no children, it is perfect */
    if (!tree->left && !tree->right)
        return (1);

    /* Calculate the height and number of nodes in the tree */
    height = calculate_tree_height(tree);
    nodes = calculate_tree_nodes(tree);

    /* Calculate the number of nodes in a perfect tree with the given height */
    power = (size_t)calculate_power(2, height + 1);

    /* Check if the number of nodes matches the expected number */
    return (power - 1 == nodes);
}