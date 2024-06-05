#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Description: This function inserts a new node as the left child of a given
 * parent node in a binary tree. If the parent already has a left child, the
 * new node becomes the left child and the existing left child becomes the left
 * child of the new node.
 *
 * Return: Pointer to the newly created node.
 *         NULL on failure.
 *         NULL if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /* Check if parent is NULL */
    if (!parent)
        return (NULL);

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);

    /* Initialize the new node */
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    /* Insert the new node as the left child */
    if (parent->left)
    {
        new_node->left = parent->left;
        parent->left->parent = new_node;
    }
    parent->left = new_node;

    return (new_node);
}
