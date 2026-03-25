#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *curr, *temp;

typedef struct
{
    Node *head, *tail;
} SLL;

void initSLL(SLL *list)
{
    list->head = list->tail = NULL;
}

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void pushTail(SLL *list, int value)
{
    if (!list->head && !list->tail)
    {
        list->head = list->tail = createNode(value);
        return;
    }
    curr = createNode(value);
    list->tail->next = curr;
    list->tail = curr;
}

void createHybrid(SLL *hybrid, SLL *listA, SLL *listB)
{
    Node *currA = listA->head;
    Node *currB = listB->head;

    while (currA && currB)
    {
        pushTail(hybrid, currA->data);
        currA = currA->next;

        pushTail(hybrid, currB->data);
        currB = currB->next;
    }

    while (currA)
    {
        pushTail(hybrid, currA->data);
        currA = currA->next;
    }
    while (currB)
    {
        pushTail(hybrid, currB->data);
        currB = currB->next;
    }
}

void popSearch(SLL *list, int value)
{
    curr = list->head;

    while (curr)
    {
        if (curr->data == value)
        {
            if (curr == list->head && curr == list->tail)
            {
                list->head = list->tail = NULL;
                free(curr);
                return;
            }
            if (curr == list->head)
            {
                list->head = curr->next;
                free(curr);
                return;
            }
            if (curr == list->tail)
            {
                list->tail = temp;
                temp->next = NULL;
                free(curr);
                return;
            }

            temp->next = curr->next;
            free(curr);
            return;
        }
        temp = curr;
        curr = curr->next;
    }
}

void printSLL(SLL *list)
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

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    SLL online, walkIn, hybrid;

    initSLL(&online);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        pushTail(&online, x);
    }

    initSLL(&walkIn);
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        pushTail(&walkIn, x);
    }

    int l;
    scanf("%d", &l);
    initSLL(&hybrid);
    createHybrid(&hybrid, &online, &walkIn);
    for (int i = 0; i < l; i++)
    {
        int x;
        scanf("%d", &x);
        popSearch(&hybrid, x);
    }
    printSLL(&hybrid);

    return 0;
}