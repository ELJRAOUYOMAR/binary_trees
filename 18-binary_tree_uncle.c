#include "binary_trees.h"

/**
 * find_sibling_node - Locates the sibling node of a given node
 * @node: A pointer to the node to find the sibling of
 *
 * Description: This function finds the sibling of a given node in a binary tree.
 * The sibling of a node is another node that shares the same parent node.
 *
 * Return: A pointer to the sibling node
 *         NULL if node is NULL
 *         NULL if the parent is NULL
 *         NULL if the node has no siblings
 */
binary_tree_t *find_sibling_node(binary_tree_t *node)
{
    if (!node || !node->parent)
        return (NULL);

    return (node == node->parent->left ? node->parent->right : node->parent->left);
}

/**
 * binary_tree_uncle - Locates the uncle of a given node
 * @node: A pointer to the node to find the uncle
 *
 * Description: This function finds the uncle of a given node in a binary tree.
 * An uncle of a node is a sibling of its parent node.
 *
 * Return: A pointer to the uncle node
 *         NULL if node is NULL
 *         NULL if the parent is NULL
 *         NULL if the node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (!node || !node->parent || !node->parent->parent)
        return (NULL);

    return (find_sibling_node(node->parent));
}
