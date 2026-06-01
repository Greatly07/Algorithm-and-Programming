#include <stdio.h>
#include <stdbool.h>

int find(int roads[], int i)
{
    if (roads[i] == i)
    {
        return i;
    }
    return roads[i] = find(roads, roads[i]);
}

int main()
{
    int p, r;
    scanf("%d %d", &p, &r);

    int roads[p + 1];
    for (int i = 0; i <= p; i++)
    {
        roads[i] = i;
    }

    bool cycle = false;
    for (int i = 0; i < r; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        int rootA = find(roads, a);
        int rootB = find(roads, b);

        if (rootA != rootB)
        {
            // union the two roads
            roads[rootA] = rootB;
        }
        else
        {
            cycle = true;
        }
    }

    if (cycle)
    {
        printf("CYCLE\n");
    }
    else
    {
        printf("SAFE\n");
    }

    return 0;
}
