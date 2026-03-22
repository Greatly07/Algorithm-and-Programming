#include <stdio.h>
#include <stdlib.h>

// 1. Define the Single Linked List Node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 2. Queue Implementation (for Developers)
typedef struct
{
    Node *front;
    Node *rear;
    int size;
} Queue;

void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
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

int dequeue(Queue *q)
{
    if (q->front == NULL)
        return -1;

    Node *temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return val;
}

// 3. Stack Implementation (for Projects)
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

int pop(Stack *s)
{
    if (s->top == NULL)
        return -1;

    Node *temp = s->top;
    int val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}

int peek(Stack *s)
{
    if (s->top == NULL)
        return -1;
    return s->top->data;
}

// 4. Main Simulation
int main()
{
    int n;
    // Read the number of developers and projects
    if (scanf("%d", &n) != 1)
        return 1;

    Queue developersQueue;
    initQueue(&developersQueue);

    Stack projectsStack;
    initStack(&projectsStack);

    // Read developer preferences and add to queue
    for (int i = 0; i < n; i++)
    {
        int pref;
        scanf("%d", &pref);
        enqueue(&developersQueue, pref);
    }

    // Read projects into a temporary array first
    int *projArray = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &projArray[i]);
    }

    // Push to stack in reverse order so index 0 is at the top
    for (int i = n - 1; i >= 0; i--)
    {
        push(&projectsStack, projArray[i]);
    }
    free(projArray);

    // 5. Process the Queue
    int rejections = 0;

    // Continue until queue is empty or no one wants the top project
    while (developersQueue.size > 0 && rejections < developersQueue.size)
    {
        int dev = dequeue(&developersQueue);
        int proj = peek(&projectsStack);

        if (dev == proj)
        {
            // Match: Developer takes the project and leaves the queue
            pop(&projectsStack);
            rejections = 0; // Reset rejections since the top project changed
        }
        else
        {
            // Mismatch: Developer rejects and moves to the end of the queue
            enqueue(&developersQueue, dev);
            rejections++;
        }
    }

    // Output the number of developers unable to get a project
    printf("%d\n", developersQueue.size);

    return 0;
}
