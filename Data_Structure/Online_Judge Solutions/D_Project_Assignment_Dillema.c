#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Queue for devs
typedef struct
{
    int size;
    Node *front, *rear;
} Queue;

void initQueue(Queue *q)
{
    q->size = 0;
    q->front = q->rear = NULL;
}

void enQueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->front == NULL && q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

void deQueue(Queue *q)
{
    Node *curr = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(curr);
    q->size--;
}

void rotate(Queue *q)
{
    if (q->size <= 1)
    {
        return;
    }

    Node *curr = q->front;
    q->front = q->front->next;
    q->rear->next = curr;
    q->rear = curr;
    curr->next = NULL;
}

// Stack for projects
typedef struct
{
    Node *top;
} Stack;

void initStack(Stack *s)
{
    s->top = NULL;
}

void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

void pop(Stack *s)
{
    Node *curr = s->top;
    s->top = s->top->next;
    free(curr);
}

int main()
{
    int n;
    scanf("%d", &n);

    Queue devs;
    Stack proj;

    // Create the Queue
    initQueue(&devs);
    for (int i = 0; i < n; i++)
    {
        int pref;
        scanf("%d", &pref);
        enQueue(&devs, pref);
    }

    // Create the Stack
    int *tArr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", tArr + i);
    }

    initStack(&proj);
    for (int i = n - 1; i >= 0; i--)
    {
        push(&proj, *(tArr + i));
    }
    free(tArr);

    int rejects = 0;
    while (devs.size > 0 && rejects < devs.size)
    {
        if (devs.front->data == proj.top->data)
        {
            deQueue(&devs);
            pop(&proj);
            rejects = 0;
        }
        else
        {
            rotate(&devs);
            rejects++;
        }
    }
    printf("%d\n", devs.size);

    while (devs.size > 0)
    {
        deQueue(&devs);
    }
    while (proj.top != NULL)
    {
        pop(&proj);
    }

    return 0;
}