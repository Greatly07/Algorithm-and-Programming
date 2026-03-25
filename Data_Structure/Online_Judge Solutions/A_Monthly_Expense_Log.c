#include <stdio.h>
#include <stdlib.h>

void update(int *arr, int day, int value)
{
    *(arr + (day - 1)) = value;
}

int sum(int *arr, int left, int right)
{
    int total = 0;
    for (int i = left - 1; i < right; i++)
    {
        total += *(arr + i);
    }

    return total;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    for (int i = 0; i < q; i++)
    {
        char operation;
        int a, b;
        scanf(" %c %d %d", &operation, &a, &b);

        if (operation == 'U')
        {
            update(arr, a, b);
        }
        else if (operation == 'S')
        {
            printf("%d\n", sum(arr, a, b));
        }
    }
    free(arr);

    return 0;
}