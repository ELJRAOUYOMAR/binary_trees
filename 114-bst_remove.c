#include "binary_trees.h"

/**
 * find_minimum - Finds the node with the minimum value in a BST
 * @node: Pointer to the root of the BST
 *
 * Return: Pointer to the node with the minimum value
 */
bst_t *find_minimum(bst_t *node)
{
    while (node->left != NULL)
        node = node->left;
    return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *temp = NULL;

    if (root == NULL)
        return (NULL);

    if (value < root->n)
    {
        root->left = bst_remove(root->left, value);
    }
    else if (value > root->n)
    {
        root->right = bst_remove(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            if (root->parent && root->parent->left == root)
                root->parent->left = temp;
            else if (root->parent && root->parent->right == root)
                root->parent->right = temp;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return (temp);
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            if (root->parent && root->parent->left == root)
                root->parent->left = temp;
            else if (root->parent && root->parent->right == root)
                root->parent->right = temp;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return (temp);
        }
        temp = find_minimum(root->right);
        root->n = temp->n;
        root->right = bst_remove(root->right, temp->n);
    }
    return (root);
}
