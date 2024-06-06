#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The value to insert
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *current, *new_node;

    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = (bst_t *)binary_tree_node(NULL, value);
        return (*tree);
    }

    current = *tree;
    while (current != NULL)
    {
        if (value == current->n)
            return (NULL); /* Value already exists in the tree */
        if (value < current->n)
        {
            if (current->left == NULL)
            {
                new_node = (bst_t *)binary_tree_node(current, value);
                if (new_node != NULL)
                    current->left = new_node;
                return (new_node);
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                new_node = (bst_t *)binary_tree_node(current, value);
                if (new_node != NULL)
                    current->right = new_node;
                return (new_node);
            }
            current = current->right;
        }
    }

    return (NULL);
}
