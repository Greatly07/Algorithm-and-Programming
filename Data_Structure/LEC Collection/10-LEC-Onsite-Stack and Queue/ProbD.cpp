#include <stdio.h>
#include <stdlib.h>

// Define structure for Single Linked List nodes
struct Node {
    int val;
    struct Node *next;
};

// Queue Management (Developers)
struct Queue {
    struct Node *head, *tail;
    int size;
};

// Stack Management (Projects)
struct Stack {
    struct Node *top;
    int size;
};

// Helper to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Queue Functions
void pushQueue(struct Queue *q, int val) {
    struct Node* temp = createNode(val);
    if (q->tail == NULL) {
        q->head = q->tail = temp;
    } else {
        q->tail->next = temp;
        q->tail = temp;
    }
    q->size++;
}

int popQueue(struct Queue *q) {
    if (q->head == NULL) return -1;
    struct Node* temp = q->head;
    int val = temp->val;
    q->head = q->head->next;
    if (q->head == NULL) q->tail = NULL;
    free(temp);
    q->size--;
    return val;
}

// Stack Functions
void pushStack(struct Stack *s, int val) {
    struct Node* temp = createNode(val);
    temp->next = s->top;
    s->top = temp;
    s->size++;
}

int popStack(struct Stack *s) {
    if (s->top == NULL) return -1;
    struct Node* temp = s->top;
    int val = temp->val;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return val;
}

int main() {
    int n, val;
    struct Queue devQueue = {NULL, NULL, 0};
    struct Stack projStack = {NULL, 0};

    // Input number of developers/projects
    if (scanf("%d", &n) != 1) return 0;

    // Input Developers (Queue)
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        pushQueue(&devQueue, val);
    }

    // Input Projects (Stack)
    // Projects are provided in stack order (top first), but since we 
    // want to maintain that order, we push them in reverse or 
    // simply adjust the pushHead logic.
    int projects[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &projects[i]);
    }
    // Push in reverse to ensure projects[0] is at the top of the stack
    for (int i = n - 1; i >= 0; i--) {
        pushStack(&projStack, projects[i]);
    }

    int attempts = 0;
    // Process until queue is empty or no one matches the top project
    while (devQueue.size > 0 && attempts < devQueue.size) {
        if (devQueue.head->val == projStack.top->val) {
            popQueue(&devQueue);
            popStack(&projStack);
            attempts = 0; // Reset attempts when a match is found
        } else {
            // Move developer to the back
            int movedDev = popQueue(&devQueue);
            pushQueue(&devQueue, movedDev);
            attempts++;
        }
    }

    [span_3](start_span)[span_4](start_span)// The answer is the remaining size of the queue[span_3](end_span)[span_4](end_span)
    printf("%d\n", devQueue.size);

    return 0;
}
