#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    float biggest = 0;

    float arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
        if (arr[i] > biggest)
        {
            biggest = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i] / biggest);
    }
    printf("\n");

    return 0;
}