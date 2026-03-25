#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *root, *temp;

Node createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node insert(Node *curr, int value)
{
    if (!curr)
    {
        return createNode(value);
    }

    if (value < curr->data)
    {
        curr->left = insert(curr->left, value);
    }
    else if (value > curr->data)
    {
        curr->right = insert(curr->right, value);
    }

    return curr;
}

Node deleteNode(Node *curr, int value)
{
    if (!curr)
    {
        return curr;
    }

    if (value < curr->data)
    {
        curr->left = deleteNode(curr->left);
    }
    else if (value > curr->data)
    {
        curr->right = deleteNode(curr->right);
    }
    else
    {
        // One or no child
        if (root->left == NULL || root->right == NULL)
        {
            temp = root->left ? root->left : root->right;

            if (!temp)
            {
                temp = curr;
                curr = NULL;
            }
            else
            {
                *curr = *temp
            }
            free(temp);
        }
        else
        {
            // Two child
        }
    }

    return curr;
}

int main()
{
    // unfinished brah

    return 0;
}