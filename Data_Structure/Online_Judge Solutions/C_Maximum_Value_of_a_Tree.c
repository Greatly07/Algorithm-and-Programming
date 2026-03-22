#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left, *right;
};

struct Node *createNode(int value)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct Node *insert(struct Node *root, int value)
{
	if (root == NULL)
	{
		return createNode(value);
	}

	if (value < root->data)
	{
		root->left = insert(root->left, value);
	}
	else if (value > root->data)
	{
		root->right = insert(root->right, value);
	}

	return root;
}

int maxValue(struct Node *root)
{
	struct Node *current = root;

	while (current->right != NULL)
	{
		current = current->right;
	}

	return current->data;
}

int main()
{
	int q;
	scanf("%d", &q);

	struct Node *root = NULL;

	for (int i = 0; i < q; i++)
	{
		int x;
		scanf("%d", &x);

		root = insert(root, x);

		int maxVal = maxValue(root);
		printf("%d\n", maxVal);
	}
	return 0;
}
