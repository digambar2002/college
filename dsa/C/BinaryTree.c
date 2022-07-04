#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Represent a node of binary tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// Represent the root of binary tree
struct node *root = NULL;
// createNode() will create a new node
struct node *createNode(int data)
{
    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    // Assign data to newNode, set left and right children to NULL
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// insert() will add new node to the binary search tree
void insert(int data)
{
    // Create a new node
    struct node *newNode = createNode(data); // node creation
    // Check whether tree is empty
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    else
    {
        // current node point to root of the tree
        struct node *current = root, *parent = NULL;
        while (true)
        {
            // parent keep track of the parent node of current node.
            parent = current;
            // If data is less than current's data,
            // node will be inserted to the left of tree
            if (data < current->data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = newNode;
                    return;
                }
            }
            // If data is greater than current's data,
            // node will be inserted to the right of tree
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}
// inorder() will perform inorder traversal on binary search tree
void inorderTraversal(struct node *node)
{
    // Check whether tree is empty
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    else
    {
        if (node->left != NULL)
            inorderTraversal(node->left);
        printf("%d ", node->data);
        if (node->right != NULL)
            inorderTraversal(node->right);
    }
}
void main()
{
    // Add nodes to the binary tree
    insert(50);
    insert(30);
    insert(70);
    insert(60);
    insert(10);
    insert(90);
    printf("Binary search tree in Inorder Traversal: \n");
    // Displays the binary tree
    inorderTraversal(root);
}