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
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[arr[i]]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("%d\n", arr2[n - 1]);
    return 0;
}