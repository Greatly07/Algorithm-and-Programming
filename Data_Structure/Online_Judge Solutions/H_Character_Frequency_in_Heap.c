#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define maxChar 26

typedef struct
{
    char letter;
    int freq;
} Node;

typedef struct
{
    Node letter[26];
    int count;
} MaxHeap;

void swap(Node *child, Node *parent)
{
    Node temp = *child;
    *child = *parent;
    *parent = temp;
}

int compare(Node child, Node parent)
{ // heap->letter[curr].freq > heap->letter[parent].freq
    if (child.freq > parent.freq)
    {
        return true;
    }

    if (child.freq == parent.freq && child.letter > parent.letter)
    {
        return true;
    }

    return false;
}

void insert(MaxHeap *heap, Node node)
{
    heap->letter[heap->count] = node;

    int curr = heap->count;
    heap->count++;
    while (curr > 0)
    {
        int parent = (curr - 1) / 2;
        if (compare(heap->letter[curr], heap->letter[parent])) // if child is a higher priority than parent
        {
            swap(&heap->letter[curr], &heap->letter[parent]);
            curr = parent;
        }
        else
        {
            break;
        }
    }
}

void deleteMax(MaxHeap *heap)
{
    heap->count--;
    heap->letter[0] = heap->letter[heap->count];

    int curr = 0;

    while (true)
    {
        // left child: 2i + 1
        // right child: 2i + 2
        int leftChild = 2 * curr + 1;
        int rightChild = 2 * curr + 2;

        int maxVal = curr;

        if (leftChild < heap->count && compare(heap->letter[leftChild], heap->letter[maxVal]))
        {
            maxVal = leftChild;
        }
        if (rightChild < heap->count && compare(heap->letter[rightChild], heap->letter[maxVal]))
        {
            maxVal = rightChild;
        }

        if (maxVal == curr)
        {
            break;
        }

        swap(&heap->letter[maxVal], &heap->letter[curr]);
        curr = maxVal;
    }
}

void getMax(MaxHeap *heap)
{
    printf("%c %d\n", heap->letter[0].letter, heap->letter[0].freq);
}

int main()
{
    int k;
    char s[101] = {'A', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'D', '\0'};
    // k = 3;
    // printf("%d\n%s\n", k, s);

    scanf("%d", &k);
    scanf("%s", s);

    int bin[maxChar] = {0};
    int sLen = strlen(s);

    MaxHeap heap;
    heap.count = 0;

    for (int i = 0; i < sLen; i++)
    {
        bin[s[i] - 'A']++;
    }

    for (int i = 0; i < maxChar; i++)
    {
        if (bin[i] > 0)
        {
            Node node;
            node.letter = i + 'A';
            node.freq = bin[i];

            insert(&heap, node);
        }
    }

    for (int i = 0; i < k && heap.count > 0; i++)
    {
        getMax(&heap);
        deleteMax(&heap);
    }

    return 0;
}