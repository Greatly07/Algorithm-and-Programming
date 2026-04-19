#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next, *prev;
} Node;

Node *head, *tail, *curr, *temp = NULL;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

void insert(int val)
{
    curr = createNode(val);
    if (!head && !tail)
    {
        head = tail = curr;
    }
    else
    {
        curr->prev = tail;
        tail->next = curr;
        tail = tail->next;
    }
}

void printAll()
{
    curr = head;
    while (curr)
    {
        printf("%d", curr->data);
        if (curr->next)
        {
            printf(" ");
        }
        curr = curr->next;
    }
    puts("");
}

void pop()
{
    if (curr == head && curr == tail)
    {
        head = tail = NULL;
    }
    else if (curr == head)
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
    free(curr);
}

void popMax(int val)
{
    curr = head;
    while (curr)
    {
        temp = curr->next;
        if (curr->data <= val)
        {
            pop();
        }
        curr = temp;
    }
}

void popAll()
{
    curr = head;
    while (curr)
    {
        temp = curr->next;
        pop();
        curr = temp;
    }
}

int main()
{
    int val;
    char s[20];

    do
    {
        scanf("%s", s);
        if (strcmp(s, "Insert") == 0)
        {
            scanf("%d", &val);
            insert(val);
        }
        else if (strcmp(s, "PrintAll") == 0)
        {
            printAll();
        }
        else if (strcmp(s, "PopMax") == 0)
        {
            scanf("%d", &val);
            popMax(val);
        }
    } while (s[0] != '0'); // 0 to exit

    popAll();

    return 0;
}