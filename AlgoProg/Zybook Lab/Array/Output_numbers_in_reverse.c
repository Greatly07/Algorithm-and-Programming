#include <stdio.h>

int main()
{
    int x[20];

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d,", x[i]);
    }
    printf("\n");

    return 0;
}