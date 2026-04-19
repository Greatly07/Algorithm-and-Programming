#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node *insert(Node *root, int val)
{
    if (!root)
    {
        printf("SUCCESS!\n");
        return createNode(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        printf("Already Exists!\n");
    }

    return root;
}

void sortAscending(Node *root)
{
    if (!root)
    {
        return;
    }
    sortAscending(root->left);
    printf("%d ", root->data);
    sortAscending(root->right);
}

void popAll(Node *root)
{
    if (!root)
    {
        return;
    }
    popAll(root->left);
    popAll(root->right);
    // printf("%d ", root->data);
    free(root);
}

int main()
{
    int val;
    char s[20];

    Node *root;
    root = NULL;

    do
    {
        scanf("%s", s);
        if (strcmp(s, "Insert") == 0)
        {
            scanf("%d", &val);
            root = insert(root, val);
        }
        else if (strcmp(s, "SortAscending") == 0)
        {
            sortAscending(root);
            puts("");
        }
    } while (s[0] != '0'); // 0 to exit

    popAll(root);

    return 0;
}