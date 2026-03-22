#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int threshold;
    scanf("%d", &threshold);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= threshold)
        {
            printf("%d,", arr[i]);
        }
    }
    printf("\n");

    return 0;
}