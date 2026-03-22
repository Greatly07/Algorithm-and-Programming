#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Add an element to the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // Set front to 0 when inserting the first element
    }
    q->items[++q->rear] = value;
    printf("Enqueued %d to queue\n", value);
}

// Remove an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front++];
}

int main() {
    Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 30);
    enqueue(&myQueue, 40);
    
    printf("Dequeued %d from queue\n", dequeue(&myQueue));
    
    return 0;
}
