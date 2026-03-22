#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next, *prev;
} Node;

Node *head, *tail, *curr, *temp;

Node *createNode(int value)
{
	curr = (Node *)malloc(sizeof(Node));
	curr->data = value;
	curr->next = curr->prev = NULL;
	return curr;
}

void pushTail(int value)
{
	curr = createNode(value);

	if (head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
}

void findOdd(int n)
{
	curr = head;
	for (int i = 0; i < n; i++)
	{
		temp = curr->next;
		if (curr->data % 2 == 1)
		{
			if (curr == head && curr == tail)
			{
				head = tail = NULL;
			}
			else
			{
				if (curr == head)
				{
					head = head->next;
					head->prev = NULL;
				}
				else if (curr == tail)
				{
					tail = tail->prev;
					tail->next = NULL;
				}
				else
				{
					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;
				}
			}
			free(curr);
		}
		curr = temp;
	}
}

void displayAll()
{
	curr = head;
	if (!curr)
	{
		printf("-1\n");
		return;
	}
	while (curr)
	{
		printf("%d", curr->data);
		if (curr->next)
		{
			printf(" ");
		}
		curr = curr->next;
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		pushTail(x);
	}

	findOdd(n);
	displayAll();

	return 0;
}
