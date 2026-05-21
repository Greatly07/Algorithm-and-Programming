#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right /*, *parent */;
    int height;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = /*newNode->parent  = */ NULL;
    newNode->height = 0;
    return newNode;
}

int height(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return root->height;
}

int maxH(int a, int b)
{
    return (a > b) ? a : b;
}

/* void fixParent(Node *root, Node *parent)
{
    if (root)
    {
        fixParent(root->left, root);
        fixParent(root->right, root);
        root->parent = parent;
    }
} */

void fixHeight(Node *root)
{
    if (root)
    {
        fixHeight(root->left);
        fixHeight(root->right);
        root->height = maxH(height(root->left), height(root->right)) + 1;
    }
}

Node *rightRotate(Node *root)
{
    // Node *parent = root->parent;
    Node *newRoot = root->left;
    Node *subTree = newRoot->right;

    newRoot->right = root;
    root->left = subTree;

    root->height = maxH(height(root->left), height(root->right)) + 1;
    newRoot->height = maxH(height(newRoot->left), height(newRoot->right)) + 1;

    // fixHeight(newRoot);
    // fixParent(newRoot, parent);

    return newRoot;
}

Node *leftRotate(Node *root)
{
    // Node *parent = root->parent;
    Node *newRoot = root->right;
    Node *subTree = newRoot->left;

    newRoot->left = root;
    root->right = subTree;

    root->height = maxH(height(root->left), height(root->right)) + 1;
    newRoot->height = maxH(height(newRoot->left), height(newRoot->right)) + 1;

    // fixHeight(newRoot);
    // fixParent(newRoot, parent);

    return newRoot;
}

Node *successor(Node *root)
{
    root = root->right;
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

Node *predecessor(Node *root)
{
    root = root->left;
    while (root->right)
    {
        root = root->right;
    }
    return root;
}

int getBalance(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return (!root) ? 0 : height(root->left) - height(root->right);
}

Node *rebalance(Node *root)
{
    if (!root)
    {
        return root; // NULL
    }

    int balance = getBalance(root);
    int balanceLeft = getBalance(root->left);
    int balanceRight = getBalance(root->right);

    if (balance > 1 && balanceLeft >= 0) // LL
    {
        return rightRotate(root);
    }
    if (balance < -1 && balanceRight < 0) // RR
    {
        return leftRotate(root);
    }
    if (balance > 1 && balanceLeft < 0) // LR
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && balanceRight >= 0) // RL
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *insert(Node *root, int value)
{
    if (!root)
    {
        root = createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    root->height = maxH(height(root->left), height(root->right)) + 1;

    return rebalance(root);
}

Node *deleteNode(Node *root, int value)
{
    if (!root)
    {
        return NULL;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL || root->right == NULL) // One or no child
        {
            Node *temp = (root->left) ? root->left : root->right;

            // Node *parent = root->parent;

            if (!temp) // No child
            {
                temp = root;
                root = NULL;
            }
            else // One child
            {
                *root = *temp;
            }
            free(temp);
            // fixParent(root, parent);
        }
        else // Two child
        {
            Node *temp = predecessor(root);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
    }

    if (!root)
    {
        return NULL;
    }

    root->height = maxH(height(root->left), height(root->right)) + 1;

    return rebalance(root);
}

void printAll(Node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        printAll(root->left);
        printAll(root->right);
    }
}

void popAll(Node *root)
{
    if (root)
    {
        popAll(root->left);
        popAll(root->right);
        free(root);
    }
}

void findKthSmallestNum(Node *root, int *count, int k)
{
    if (!root || (*count) >= k)
    {
        return;
    }
    // In-Order Traversal
    findKthSmallestNum(root->left, count, k); // left

    (*count)++;
    if ((*count) == k) // root
    {
        printf("%d\n", root->data);
        return;
    }

    findKthSmallestNum(root->right, count, k); // right
}

int main()
{
    Node *root = NULL;

    int n, q, k;
    scanf("%d %d %d", &n, &q, &k);

    int val;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &val);
        root = deleteNode(root, val);

        int count = 0;
        findKthSmallestNum(root, &count, k);
    }

    popAll(root);
    return 0;
}