#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next, *prev;
} Node;

Node *curr, *temp;

typedef struct
{
    Node *head;
    Node *tail;
} LL;

void initLL(LL *list)
{
    list->head = list->tail = NULL;
}

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

void pushTail(LL *list, int value)
{
    if (!list->head && !list->tail)
    {
        curr = createNode(value);
        list->head = list->tail = curr;

        return;
    }
    curr = createNode(value);
    list->tail->next = curr;
    curr->prev = list->tail;
    list->tail = curr;
}

void mergeLL(LL *listA, LL *listB)
{
    listA->tail->next = listB->head;
    listB->head->prev = listA->tail;
    listA->tail = listB->tail;

    // Empty list B
    listB->head = listB->tail = NULL;
}

void printLL(LL *list)
{
    curr = list->head;
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

void printLLReversed(LL *list)
{
    curr = list->tail;
    while (curr)
    {
        printf("%d", curr->data);
        if (curr->prev)
        {
            printf(" ");
        }
        curr = curr->prev;
    }
    printf("\n");
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    LL A, B;

    initLL(&A);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        pushTail(&A, x);
    }

    initLL(&B);
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        pushTail(&B, x);
    }

    mergeLL(&A, &B);
    printLL(&A);
    // printLLReversed(&A);

    return 0;
}